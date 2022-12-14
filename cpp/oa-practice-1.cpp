#include <bits/stdc++.h>
using namespace std;

/*
Given a string of lowercase English letters s your task is to rearrange its letters by pairing them together according to the following rule. First letter with the last one, second letter with the second to last one, etc. More formally, if s = c1c2c3…..cn-3*cn -2*cn, then the letters should be arranged in c1cnc2cn-1 if s contains an odd number of letters, the middle letter should not be paired with any other letters, but placed at the end of the output string instead.
Example:
s = “abcdef”
solution(s) = “afbecd”
*/

string sol1(string word)
{
    ostringstream os;
    for (int i = 0; i < word.length() / 2; i++)
    {
        os << word[i] << word[word.length() - i - 1];
    }

    if (word.length() % 2 == 1)
    {
        os << word[(word.length() - 1) / 2];
    }
    return os.str();
}

/*
Imagine there is a group chat with many users writing messages. The content of messages includes text and mentions of other users in the chat. Mentions in the group chat are formatted as strings starting with the @ character and followed by at least one id separated by commas. An id is formatted as a string starting with id and followed by a positive integer from 0  to 999
“This is an example with no mentions@”
“This is an example with @id1 one mention of one user”
“This is an example with @id1,id123,id983 one mention of three users”
“This is an example with @id1,id123,id983 several mentions of several users @id239
    Now imagine you are given two arrays of strings titled members and messages. Your task is to calculate the mention statistics from the group chat. In other words, count the number of messages that each chat member is mentioned in. Chat members mentioned multiple times in a message should be counted only once per message.

Return the mention statistics in an array of strings, where each string follows this format: “[user id] - [mentions count]”. The array should be sorted by mention count in descending order, or in the case of a tie, lexicographically by userid in ascending order.

It is guaranteed that proper ids will be used for each mention. Additionally, all mentions will be preceded by and followed by a space. Unless they are located either at the beginning or end of the message. Note that the @ character is still allowed to be included in a message not as a part of any mention, but not as the first character in a word.
Example:
For members = [“id123”, “id234”, “id7”, “id321”] and
messages = [“Hey @id123,id321 review this PR please! @id123 what do you think about this approach?”,
“Hey @id7 nice approach! Great job! @id800 what do you think?”,
“@id323,id121 thx!”]

*/

string sol2(vector<string> members, vector<string> messages)
{
    map<string, int> stats;
    for (auto &a : members)
    {
        stats[a] = 0;
    }

    vector<string> msgs_split;
    for (auto &m : messages)
    {
        stringstream A(m);
        string ap;
        set<string> s; // using a set because a member can only add one mention per message
        while (getline(A, ap, ' ')) // going through every word of the split
        {

            if (ap[0] == '@') // if it begins with @
            {
                stringstream C(ap.substr(1)); 
                string cp;
                while (getline(C, cp, ',')) // split the word by the commas
                {
                    s.insert(cp); // insert every member
                    // stats[cp] += 1;
                }
            }
        }
        for (auto &a : s)
        {
            stats[a] += 1; // for every memeber mentioned in the message, add one to their count
        }
    }

    map<int, vector<string>> stats_rev; 

    for (auto &a : members) // only the members we care about
    {
        stats_rev[stats[a]].push_back(a); // group the members by their mention count
    }
    ostringstream os;

    // iterator starts from highest key value, so start from the back 
    for (auto a = stats_rev.rbegin(); a != stats_rev.rend(); a++) 
    {
        sort(a->second.begin(), a->second.end()); // sort the members first
        for (auto &b : a->second)
        {
            os << "[" << b << "] - [" << stats[b] << "], ";
        }
    }

    return os.str();
}

/*
3. For an array a and an integer t (0 <= t < a.length), let’s define cyclic t-shift operation as carrying t elements from the beginning of the array to the end.

For example, applying cyclic t-shift to a = [ 1, 2, 3, 4] can turn it into four different arrays:
[1, 2, 3, 4] (0-shift)
[2, 3, 4, 1] (1-shift, one element from the beginning was carried to the end)
[3, 4, 1, 2] (2-shift two elements were carried to the end)
[4, 1, 2, 3] (3-shift 1, 2, 3 were carried to the end)
Given an array of integers elements find such t (0 <= t < elements.length) that cyclic t-shift operations turns elements into a sorted array [1, 2, . . . , elements.length]. If there is no such t. return -1.
Example:
For elements = [1, 4, 2, 3] the output should be solution(elements) = -1
Let's consider all possible cyclic t-shifts:
0 - shift: moving 0 elements from the beginning to the end we get
[1, 4, 2 ,3]
1 - shift: moving 1 elements from the beginning to the end we get
[4, 2, 3, 1]
2 - shift: moving 2 elements from the beginning to the end we get
[2, 3, 1, 4]
3 - shift: moving 3 elements from the beginning to the end we get
[3, 1, 4, 2]
        None of the resulting arrays equals sorted array [ 1, 2, 3, 4], so the answer is -1

For elements = [3, 4, 5, 1, 2], the output should be solution(elements) = 3
If we move the first 3 elements of the given array to the beginning to the end, we get a sorted array: [1, 2, 3, 4, 5], so the answer is 3


*/

int sol3(vector<int> nums)
{
    int min = *min_element(nums.begin(), nums.end());
    auto index_of_min = *(nums.begin()) - *find(nums.begin(), nums.end(), min) + 1; // +1 because without it it would be element right before the min
    vector<int> h1(nums.begin(), nums.end() - index_of_min + 1);                    // +1 is the element it stops at (1) but doesnt consider
    vector<int> h2(nums.begin() + index_of_min, nums.end());                        // +index_of_min is the actual position of the min

    //for (auto &a : h1)
    //{
    //    cout << a << " ";
    //}
    //cout << '\n';

    //for (auto &a : h2)
    //{
    //    cout << a << " ";
    //}
    //cout << '\n';


    // if both halfs are sorted that then shift is the distance of index of the min from the beginning
    if (is_sorted(h1.begin(), h1.end()) && is_sorted(h2.begin(), h2.end()))
    {
        return index_of_min;
    }
    return -1;
}

int main()
{
    cout << sol1("abc3def") << '\n';
    cout << sol2({"id123", "id234", "id7", "id321"}, {"Hey @id123,id321 review this PR please! @id123 what do you think about this approach?",
                                                      "Hey @id7 nice approach! Great job! @id800 what do you think?",
                                                      "@id323,id121 thx!"})
         << '\n';
    cout << sol3({3, 4, 5, 1, 2}) << '\n';
}