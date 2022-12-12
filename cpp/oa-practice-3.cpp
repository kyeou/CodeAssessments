#include <bits/stdc++.h>

using namespace std;

int call_count = 0;
int call_c = 0;

string sol1(string _a)
{

    call_count++;
    string _b = string(_a.rbegin(), _a.rend());

    if (_a == _b)
    {
        return _a;
    }
    else
    {
        return max({sol1(_a.substr(1)), sol1(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                   { return s1.length() < s2.length(); });
    }
}

map<string, bool> dp;

string sol1_dp(string _a)
{

    if (dp.find(_a) != dp.end())
    {
        if (!dp[_a])
        {
            return max({sol1_dp(_a.substr(1)), sol1_dp(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                       { return s1.length() < s2.length(); });
        }
        else
        {
            return _a;
        }
    }
    else
    {
        // cout << "call " << _a << '\n';
        string _b = string(_a.rbegin(), _a.rend());

        if (_a == _b)
        {
            dp[_a] = true;
            return _a;
        }
        else
        {
            dp[_a] = false;
            return max({sol1_dp(_a.substr(1)), sol1_dp(_a.substr(0, _a.length() - 1))}, [](string s1, string s2)
                       { return s1.length() < s2.length(); });
        }
    }
}

int sol2(vector<vector<int>> matrix)
{
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
        min_cols.push_back(*max_element(temp.begin(), temp.end()));
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

        max_rows.push_back(*max_element(matrix[i].begin(), matrix[i].end()));
    }

    vector<int> ret;

    sort(max_rows.begin(), max_rows.end());
    // for (auto &a : max_rows)
    // {
    //     cout << a << " ";
    // }
    // cout << '\n';
    std::set_intersection(min_cols.begin(), min_cols.end(),
                          max_rows.begin(), max_rows.end(),
                          back_inserter(ret));
    // for (auto a : ret)
    // {
    //     cout << a << " ";
    // }
    // cout << '\n';
    return *ret.begin();
}

int main()
{
    cout << sol1("YABCCBAZ") << '\n';                                                     // ABCCBA
    cout << sol1("abbaecccccc") << '\n';                                                  // cccccc
    cout << sol1_dp("YABCCBAZ") << '\n';                                                  // ABCCBA
    cout << sol1_dp("abbaecccccc") << '\n';                                               // cccccc
    cout << sol2({{1, 2}, {3, 4}}) << '\n';                                               // 4
    cout << sol2({{14, 3, 6, 4}, {15, 7, 5, 8}, {20, 11, 12, 10}, {9, 2, 3, 1}}) << '\n'; // 20
    for (auto &a : dp)
    {
        cout << a.first << " " << a.second << '\n';
    }
    // cout << "DP SIZE " << dp.size() << '\n';
}