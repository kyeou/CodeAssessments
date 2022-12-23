#include <bits/stdc++.h>

using namespace std;

// Take a string and truncate the start, end, or both until it is a palindrome.
// If no such string exists return -1 or None
// Print the largest possible substring
// if multiple substrings exists, print th lexigraphically smallest one

string sol1(string _a)
{

    string _b = string(_a.rbegin(), _a.rend());

    if (_a == _b) // if param is already substring, return it
    {
        return _a;
    }
    else // if not, call the function on a truncation of the string from both the left and right
    {
        return max({sol1(_a.substr(1)), sol1(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                   { return s1.length() < s2.length(); });
    }
}

// since some substrings will be calculated more than once, a dp version might be more suitable
map<string, bool> dp;
string sol1_dp(string _a)
{

    if (dp.count(_a))
    {
        if (!dp[_a])
        {
            return max({sol1_dp(_a.substr(1)), sol1_dp(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                       { return s1.length() < s2.length(); });
        }

        return _a;
    }
    cout << "call " << _a << '\n';

    int i = 0, j = _a.length() - 1;
    while (i < j)
    {
        if (_a[i] != _a[j])
        {
            dp[_a] = false;
            return max({sol1_dp(_a.substr(1)), sol1_dp(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                       { return s1.length() < s2.length(); });
        }
        i++; j--;
    }
    dp[_a] = true;
    return _a;
}

// The reverse version of the Python one.
// Take a matrix, and find the number that is SMALLESST in its column and LARGEST in its row.
// If none found, return -1

int sol2(vector<vector<int>> matrix)
{
    // given a column position, go through all the rows and save that column in a vector
    auto col = [](vector<vector<int>> matrix, int axis)
    {
        vector<int> ret;
        for (int i = 0; i < matrix.size(); i++)
        {
            ret.push_back(matrix[i][axis]);
        }
        return ret;
    };

    vector<int> min_cols;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        vector<int> temp = col(matrix, i);
        min_cols.push_back(*min_element(temp.begin(), temp.end())); // finds min value for every column
    }
    sort(min_cols.begin(), min_cols.end());
    // for (auto &a : min_cols)
    // {
    //     cout << a << " ";
    // }
    // cout << '\n';

    vector<int> max_rows;
    for (int i = 0; i < matrix.size(); i++)
    {
        max_rows.push_back(*max_element(matrix[i].begin(), matrix[i].end())); // finds max for every row
    }

    vector<int> ret;

    sort(max_rows.begin(), max_rows.end());
    // for (auto &a : max_rows)
    // {
    //     cout << a << " ";
    // }
    // cout << '\n';

    // find the intersection of the respective mins and maxs, should only be one result
    std::set_intersection(min_cols.begin(), min_cols.end(),
                          max_rows.begin(), max_rows.end(),
                          back_inserter(ret));
    // for (auto a : ret)
    // {
    //     cout << a << " ";
    // }
    // cout << '\n';
    return *ret.begin(); // return the intersection
}

int main()
{
    cout << sol1("YABCCBAZ") << '\n';       // ABCCBA
    cout << sol1("abbaecccccc") << '\n';    // cccccc
    cout << sol1_dp("YABCCBAZ") << '\n';    // ABCCBA
    cout << sol1_dp("abbaecccccc") << '\n'; // cccccc
    cout << sol1_dp("aaaaaaaaaaaaaaaaaaaaaaaaaaaaacccccccccccccccc") << '\n';
    cout << sol2({{1, 2}, {3, 4}}) << '\n';                                               // 2
    cout << sol2({{14, 3, 6, 4}, {15, 7, 5, 8}, {20, 11, 12, 10}, {9, 2, 3, 1}}) << '\n'; // 9
    // for (auto &a : dp)
    // {
    //     cout << a.first << " " << a.second << '\n';
    // }
    // cout << "DP SIZE " << dp.size() << '\n';
}