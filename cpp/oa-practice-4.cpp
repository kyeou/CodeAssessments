#include <bits/stdc++.h>
using namespace std;


// Given an array of nums calculate the minimum number of move-to-back required to sort an array of numbers in increasing order. set(l) = list l

int sol1(vector<int> nums) {}


// Given an integer array of nums representing the amount of candy held by each house, return the maximum amount of canady you can gain
// while not visiting adjacent houses at any point

int sol2(vector<int> nums) {}


// Type A: $1000 for 3000 users
// Type B: $500 for 2000 users
// Type C: $200 for 1000 users
// Type D: $100 for 800 users
// Type E: $50 for 200 users
// Write an algorithm to help CMO evaluate the highest number of users it can reach by using the budget: N and the advertisements types above.

int sol3(map<int, int> ad_types, int N)
{

    map<vector<int>, int> possible_packages; // all possible partitions that add up to N
    vector<int> prefix; // the list of numbers that make the set possible_packages
    vector<int> ad_list; // the costs of all the types
    
    // capture possible_packages and prefix for sub-scope access
    // recursive lambda to find all partitions
    auto partition = [&possible_packages, &prefix](auto &&partition, int n, int max, vector<int> ad_types_list)
    {
        if (n == 0) // if n is 0, that means all the nums currently in prefix add up to N
        {
            possible_packages[prefix] = 0; // save that prefix
            prefix = {}; // reset temp prefix
            return;
        }

        for (int i = min(max, n); i >= 1; i -= *min_element(ad_types_list.begin(), ad_types_list.end()))
        {
            if (std::count(ad_types_list.begin(), ad_types_list.end(), i)) // only consider adding to the prefix if the i is one of the costs
            {
                prefix.push_back(i);
                partition(partition, n - i, i, ad_types_list); // call the lamdba again subtracting the i from whats left 
            }
        }
    };
    for (auto &a : ad_types) 
    {
        ad_list.push_back(a.first); // record all the costs of the ad_types
    }
    partition(partition, N, N, ad_list); // start partitioning

    for (auto &a : possible_packages) // for every partition
    {
        for (auto &b : a.first) // for every number in the partition
        {
            possible_packages[a.first] += ad_types[b]; // add the amount of users to the value for the current partition
        }
    }
    int max = 0;
    // go through all the values and return the max
    for (auto &a : possible_packages)
    {
        if (a.second > max)
            max = a.second;
    }
    return max;
}


//Given two string, s and t, where t is a subsequence of s, report the words of s that are missing in t in the order they are missing.
vector<string> sol4(string s, string t) {}

// Given a list of strings, determine if all the strings contain all the letters of alphabet (only lowercase)
// Returns a string consisting of 0's and 1's being False and True for each string
// 0001 means that in a list of 4 strings, only the last one contained all 26 letters of the alphabet

string sol5(vector<string> words) {}



int main()
{
    cout << sol3({{1000, 3000}, {500, 2000}, {200, 1000}, {100, 800}, {50, 200}}, 800) << '\n';
}