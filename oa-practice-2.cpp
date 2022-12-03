#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

string sol1(string s)
{
    for (int i = 0; i < s.length() - 1; i += 2)
    {
        swap(s[i], s[i++]);
    }
    return s;
}

string sol2(vector<string> s, string ar)
{
    vector<int> si;
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        si.push_back(stoi((*it).erase(2, 1)));
    }
    int ari = stoi(ar.erase(2, 1));
    for (int a : si)
    {
        if (ari < a)
        {
            string result = to_string(a - ari);
            ostringstream os;
            os << result.substr(0, result.length() - 2) << ":" << result.substr(result.length() - 2);
            result = os.str();
            if (result.length() == 4)
            {
                return result.insert(0, "0");
            }
            return result;
        }
    }
    return "";
}

int sol3(vector<int> nums)
{
    auto big = [](int num)
    {
        int max = num;
        string ns = to_string(num);
        for (int i = 0; i < ns.length(); i++)
        {
            rotate(ns.begin(), ns.begin() + 1, ns.end());
            if (stoi(ns) > max)
            {
                max = stoi(ns);
            }
        }
        return max;
    };
    set<int> no_dups_nums;
    for (int a : nums)
    {
        no_dups_nums.insert(big(a));
    }
   

    return nums.size() - no_dups_nums.size() + 1;
}

int main()
{
    cout << sol1("abcdefg") << '\n';
    cout << sol2({"12:30", "14:00", "19:55"}, "14:30") << '\n';
    cout << sol3({13, 5604, 31, 2, 13, 4560, 546, 654, 456}) << '\n';
}