# CodeAssessments
Some Leetcode style questions for practice. 

## OA-Practice-1 

### Question 1 `(PY: SOLVED, CPP: SOLVED)`
Given a string of lowercase English letters s your task is to rearrange its letters by pairing them together according to the following rule. First letter with the last one, second letter with the second to last one, etc. More formally, if $s = c_1c_2c_3…..c_{n-3}c_{n-2}c_n$, then the letters should be arranged in $c_1c_nc_2c_{n-1}$ if s contains an odd number of letters, the middle letter should not be paired with any other letters, but placed at the end of the output string instead. 
```
Example:
s = “abcdef”
solution(s) = “afbecd”
```


### Question 2 `(PY: SOLVED, CPP: SOLVED)`
Imagine there is a group chat with many users writing messages. The content of messages includes text and mentions of other users in the chat. Mentions in the group chat are formatted as strings starting with the `@` character and followed by at least one id separated by commas. An `id` is formatted as a string starting with `id` and followed by a positive integer from ```0-999```
`“This is an example with no mentions@”`
`“This is an example with @id1 one mention of one user”`
`“This is an example with @id1,id123,id983 one mention of three users”`
`“This is an example with @id1,id123,id983 several mentions of several users @id239`
    Now imagine you are given two arrays of strings titled members and messages. Your task is to calculate the mention statistics from the group chat. In other words, count the number of messages that each chat member is mentioned in. Chat members mentioned multiple times in a message should be counted only once per message.

Return the mention statistics in an array of strings, where each string follows this format: ```"[user id] - [mentions count]"```. The array should be sorted by mention count in descending order, or in the case of a tie, lexicographically by userid in ascending order.

It is guaranteed that proper ids will be used for each mention. Additionally, all mentions will be preceded by and followed by a space. Unless they are located either at the beginning or end of the message. Note that the @ character is still allowed to be included in a message not as a part of any mention, but not as the first character in a word. 
```
Example:  
members = [“id123”, “id234”, “id7”, “id321”]
messages = [“Hey @id123,id321 review this PR please! @id123 what do you think about this approach?”, 
“Hey @id7 nice approach! Great job! @id800 what do you think?”, “@id323,id121 thx!”]

solved(members, messages) =
["[id123] - [1]", "[id321] - [1]", "[id7] - [1]", "[id234] - [0]"]
```


### Question 3 `(PY: SOLVED, CPP: SOLVED)`
For an array a and an integer `t` $(0 <= t < a.length)$, let’s define cyclic t-shift operation as carrying `t` elements from the beginning of the array to the end. 

For example, applying cyclic t-shift to $a = [1, 2, 3, 4]$ can turn it into four different arrays:
$[1, 2, 3, 4]$ `(0-shift)`
$[2, 3, 4, 1]$ `(1-shift, one element from the beginning was carried to the end)`
$[3, 4, 1, 2]$ `(2-shift two elements were carried to the end)`
$[4, 1, 2, 3]$ `(3-shift 1, 2, 3 were carried to the end)`
Given an array of integers elements find such `t` $(0 <= t < elements.length)$ that cyclic t-shift operations turns elements into a sorted array $[1, 2, . . . , elements.length]$. If there is no such `t`. `return -1`. 
```
Example: 
For elements = [1, 4, 2, 3] the output should be 
solution(elements) = -1 
Let's consider all possible cyclic t-shifts: 

0 - shift: moving 0 elements from the beginning to the end we get
[1, 4, 2 ,3]

1 - shift: moving 1 elements from the beginning to the end we get
[4, 2, 3, 1]

2 - shift: moving 2 elements from the beginning to the end we get
[2, 3, 1, 4]

3 - shift: moving 3 elements from the beginning to the end we get
[3, 1, 4, 2] 

None of the resulting arrays equals sorted array $[1, 2, 3, 4]$, so the answer is `-1`
```
```
Example:
For elements = [3, 4, 5, 1, 2], the output should be solution(elements) = 3
If we move the first 3 elements of the given array to the beginning to the end, 
we get a sorted array: [1, 2, 3, 4, 5], so the answer is 3

[3, 4, 5, 1, 2] 0-Shift
[4, 5, 1, 2, 3] 1-Shift
[5, 1, 2, 3, 4] 2-Shift
[1, 2, 3, 4, 5] 3-Shift

solved(elements) = 3
```


## OA-Practice-2

### Question 1 `(PY: SOLVED, CPP: SOLVED)`
Take a string, and swap every pair of characters. If odd number of characters, leave end alone
```
Example:
solved(ab) = ba
solved(abc) = bac
```

### Question 2 `(PY: SOLVED, CPP: SOLVED)`
Take a arrival time and a schedule and figure out how long you have to wait till the next available time in the schedule
```
Example:
schedule = ["12:30", "14:00", "19:55"]
arrrival = "14:30"
solved(schedule, arrival) = "05:25"
```

### Question 3 `(PY: SOLVED, CPP: SOLVED)`
Take an array of nums and determine how many pairs of numbers that exist that are shifts of each other
```
Example:
nums = [13, 5604, 31, 2, 13, 4560, 546, 654, 456]
13 - 31
13 - 13
31 - 13
5604 - 4560
546 - 654

solved(nums) = 5
```
## OA-Practice-3

### Question 1 `(PY: SOLVED, CPP: SOLVED)`
Take a string and truncate the start, end, or both until it is a palindrome.
If no such string exists return -1 or None
Print the largest possible substring
if multiple substrings exists, print the lexigraphically smallest one
```
solved("YABCCBAZ") = "ABCCBA"
solved("abbaecccccc") =  "cccccc"
```

### Question 2 `(PY: SOLVED, CPP: SOLVED)`
Take a matrix, and find the number that is largest in its column and smallest in its row.
If none found, return -1
```
Exmaple:
solved([[1, 2], [3, 4]]) = 3

solved([[14, 3, 6, 4], [15, 7, 5, 8], [20, 11, 12, 10], [9, 2, 3, 1]]) = 10

```

## OA-Practice-4

### Question 1 `(PY: UNSOLVED, CPP: UNSOLVED)`
Given an array of nums calculate the minimum number of move-to-back required to sort an array of numbers in increasing order. 


### Question 2 `(PY: UNSOLVED, CPP: UNSOLVED)`
Given an integer array of nums representing the amount of candy held by each house, return the maximum amount of canady you can gain while not visiting adjacent houses at any point


### Question 3 `(PY: SOLVED, CPP: SOLVED)`

Write an algorithm to help CMO evaluate the highest number of users it can reach by using the budget: N and the advertisements types above.
```
Type A: 1000 USD for 3000 users
Type B: 500 USD for 2000 users
Type C: 200 USD for 1000 users
Type D: 100 USD for 800 users
Type E: 50 USD for 200 users

Exmaple:
ad_types = {1000: 3000, 500: 2000, 200: 1000, 100: 800, 50: 200} 
solved(ad_types, 800) = 6400
```


### Question 4 `(PY: SOLVED, CPP: UNSOLVED)`
Given two string, s and t, where t is a subsequence of s, report the words of s that are missing in t in the order they are missing.
```
Example:
s = "Here is a string"
solved(s, t)) = ['Here', 'a']
```

### Question 5 `(PY: SOLVED, CPP: UNSOLVED)`
Given a list of strings, determine if all the strings contain all the letters of alphabet (only lowercase)
Returns a string consisting of 0's and 1's being False and True for each string
0001 means that in a list of 4 strings, only the last one contained all 26 letters of the alphabet

```
Example:
solved([
        "abcdefghijklmnopqrstuvwxyz",
        "the quick brown fox jumps over the lazy dog",
        "i just want a f***in job"
    ]))
= 110
```