

"""
Given a string of lowercase English letters s your task is to rearrange its letters by pairing them together according to the following rule. First letter with the last one, second letter with the second to last one, etc. More formally, if s = c1c2c3…..cn-3*cn -2*cn, then the letters should be arranged in c1cnc2cn-1 if s contains an odd number of letters, the middle letter should not be paired with any other letters, but placed at the end of the output string instead. 
Example:
s = “abcdef”
solution(s) = “afbecd”
"""




def sol1(word):
    ret = ""
    for i in range(0, len(word)//2):
        ret += word[i] + word[len(word) - i - 1]
    
    if len(word) % 2 != 0:
        ret += word[len(word)//2]
    
    return ret

print(sol1("adc3def"))

"""
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
    
"""

def sol2(members, messages):
    stats_dict = {}
    ret = []
    for mem in members:
        stats_dict[mem] = 0
    
    for msg in messages:
        curr_mentions = []
        for word in msg.split(" "):
            if word.__contains__('@') and word[0] == '@':
                curr_mentions += [x for x in word.replace("@", "").split(',')]
        curr_mentions = list(set(curr_mentions))
        for men in curr_mentions:
            try:
                stats_dict[men] += 1
            except KeyError:
                continue
    
    stats_dict = dict(sorted(stats_dict.items(), key=lambda x:x[1]))
    
    # For every unique value in the stats_dict, sort every key that has that value by name, and then proceed 
    org_dict = {}
    for key in stats_dict.keys():
        try:
            org_dict[stats_dict[key]].append(key)
        except KeyError:
            org_dict[stats_dict[key]] = [key]
    
    for key in org_dict.keys():
        for id in sorted(org_dict[key]):
            ret.append(f"[{id}] - [{stats_dict[id]}]")
               
    return ret
    
    
print(sol2(["id123", "id234", "id7", "id321"], ["Hey @id123,id321 review this PR please! @id123 what do you think about this approach?", 
"Hey @id7 nice approach! Great job! @id800 what do you think?",
"@id323,id121 thx!"]
))


"""
3. For an array a and an integer t (0 <= t < a.length), let’s define cyclic t-shift operation as carrying t elements from the beginning of the array to the end. 

For example, applying cyclic t-shift to a = [ 1, 2, 3, 4] can turn it into four different arrays:
[1, 2, 3, 4] (0-shift)
[2, 3, 4, 1] (1-shift, one element from the beginning was carried to the end)
[3, 4, 2, 1] (2-shift two elements were carried to the end)
[4, 3, 2, 1] (3-shift 1, 2, 3 were carried to the end)
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


"""                             

def sol3(numbers):
    
    
    # Split the array at the min, with the min being grouped with the elements suceeding it
    h1, h2 = numbers[0:numbers.index(min(numbers))], numbers[numbers.index(min(numbers)):]

    
    # if one of the arrays is empty, that means the min was at the beginning
    # if everything after the min is not sorted, there is no shift possible
    if h1 is None or h2 is None:
        if sorted(h2) != h2 or sorted(h1) != h1:
            return -1        
    
    
    # if the half's are sorted in increasing order, that means a shift on a sorted array occured
        # return the distance between 0 and index of the min, i.e. the shift
    # else return -1
    if sorted(h2) == h2 and sorted(h1) == h1:
        return numbers.index(min(numbers))
    else:
        return -1


print(sol3([3, 4, 5, 1, 2]))    
