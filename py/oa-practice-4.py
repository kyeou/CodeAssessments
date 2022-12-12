# Given an array of nums calculate the minimum number of move-to-back required to sort an array of numbers in increasing order. set(l) = list l

# Given an integer array of nums representing the amount of candy held by each house, return the maximum amount of canady you can gain
# while not visiting adjacent houses at any point


def sol2(nums):
    return


# Type A: $1000 for 3000 users
# Type B: $500 for 2000 users
# Type C: $200 for 1000 users
# Type D: $100 for 800 users
# Type E: $50 for 200 users
# Write an algorithm to help CMO evaluate the highest number of users it can reach by using the budget: N and the advertisements types above.


def p2(n, max, prefix, ad_types, possible_packages):
    if n == 0:
        possible_packages[tuple(prefix.split(" ")[1:])] = 0
        return

    for i in range(min(max, n), 0, -min(ad_types)):
        if i in ad_types:
            p2(n - i, i, prefix + " " + str(i), ad_types, possible_packages)




def sol3(ad_types, N):
    possible_packages = {}
    p2(N, N, "", list(ad_types.keys()), possible_packages)

    for key in possible_packages:
        for amt in key:
            possible_packages[key] += ad_types[int(amt)]
    print(max(list(possible_packages.values())))


# Given two string, s and t, where t is a subsequence of s, report the words of s that are missing in t in the order they are missing.
def sol4(s, t):
    ret = []
    a, b, ac, bc = s.split(" "), t.split(" "), 0, 0
    while bc < len(b):
        if a[ac] != b[bc]:
            ret.append(a[ac])
            ac += 1
        else:
            ac += 1
            bc += 1

    while ac < len(a):
        ret.append(a[ac])
        ac += 1

    return ret


# Given a list of strings, determine if all the strings contain all the letters of alphabet (only lowercase)
# Returns a string consisting of 0's and 1's being False and True for each string
# 0001 means that in a list of 4 strings, only the last one contained all 26 letters of the alphabet


def sol5(pangram):
    ret = []
    for p in [x.replace(" ", "") for x in pangram]:
        l = 'a'
        while l != 'z':
            if not p.__contains__(l):
                ret.append('0')
                break
            l = chr(ord(l) + 1)
        else:
            ret.append('1')
    return ''.join(ret)


print(sol3({1000: 3000, 500: 2000, 200: 1000, 100: 800, 50: 200}, 800))
print(sol4("Here is a string", "is string"))
print(
    sol5([
        "abcdefghijklmnopqrstuvwxyz",
        "the quick brown fox jumps over the lazy dog",
        "i just want a f***in job"
    ]))
