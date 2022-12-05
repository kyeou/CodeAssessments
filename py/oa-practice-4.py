# Given an array of nums calculate the minimum number of move-to-back required to sort an array of numbers in increasing order. set(l) = list l


# Given an integer array of nums representing the amount of candy held by each house, return the maximum amount of canady you can gain 
# while not visiting adjacent houses at any point


# Type A: $1000 for 3000 users 
# Type B: $500 for 2000 users
# Type C: $200 for 1000 users
# Type D: $100 for 800 users
# Type E: $50 for 200 users
# Write an algorithm to help CMO evaluate the highest number of users it can reach by using the budget: N and the advertisements types above.



# Given two string, s and t, where t is a subsequence of s, report the words of s that are missing in t in the order they are missing. 
def sol3(s, t):
    ret = []
    a, b = s.split(" "), t.split(" ")
    ac, bc = 0, 0
    while True:
        try:
            if a[ac] != b[bc]:
                ret.append(a[ac])
                ac += 1
            else:
                ac += 1
                bc += 1
        except IndexError:
            while ac < len(a):
                ret.append(a[ac])
                ac += 1
            break
    return ret
                
                
                
# Given a list of strings, determine if all the strings contain all the letters of alphabet (only lowercase)
# Returns a string consisting of 0's and 1's being False and True for each string 
# 0001 means that in a list of 4 strings, only the last one contained all 26 letters of the alphabet

def sol4(pangram):
    ret = []
    for p in pangram:
        l = 'a'
        while l != '{':
            if l not in p:
                ret.append('0')
                break
            l = chr(ord(l) + 1)
        if l == '{':
            ret.append('1')
    return ''.join(ret)