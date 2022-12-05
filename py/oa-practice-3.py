# Take a string and truncate the start, end, or both until it is a palindrome.
# If no such string exists return -1 or None
# Print the largest possible substring
# if multiple substrings exists, print th lexigraphically smallest one
def sol1(inputStr):
    
    # I dont think this always returns the lexigraphically smallest one
    if inputStr == inputStr[::-1]:
        return inputStr
    else:
        return max(sorted([sol1(inputStr[0:len(inputStr)-1]), sol1(inputStr[1:])]), key=len)
    
    
    
    
    
    # dead --------------------------------
    sols = []
    for i in range(len(inputStr)//2):
        if inputStr[i:len(inputStr)-1] == inputStr[i:len(inputStr)-1][::-1]: 
            sols.append(inputStr[i:len(inputStr)-i])
    if len(sols) >-1:
        sols.sort(key=lambda s:len(s))
        max_l = len(sols[len(sols)-1])
        sols = [x for x in sols if len(x) == max_l]
        return sorted(sols)[0]
    
    
    try:
        return sols[0]
    except IndexError:
        return None


import numpy as np


# Take a matrix, and find the number that is largest in its column and smallest in its row.
# If none found, return -1
def sol2(matrix):
    
    a = np.array(matrix)
    try:
        return (np.intersect1d(np.max(a, axis=0), np.min(a, axis=1)))[0]
    # (np.min(a, axis=0), np.max(a, axis=1)) returns smallest in column and largest in row
    except IndexError:
        return -1

    
    # dead --------------------------------
    def intersection(i, j):
        return [x for x in i if x in j]  
    m = matrix
    all_cols = []
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            try:
                all_cols[j].append(matrix[i][j])
            except IndexError:
                all_cols.append([matrix[i][j]])
    all_cols = [sorted(x, reverse=True)[0] for x in all_cols] # switch reverse to False to get smalled in column



    for i in range(len(m)):
        ma = min(m[i]) # switch to max to get largest in row
        for j in range(len(m[i])):
            m[i][j] = -1 if m[i][j] != ma else m[i][j]

    for i in range(len(m)):
        if len(intersection(m[i], all_cols)) == 1:
            return intersection(m[i], all_cols)[0]

    return -1


print(sol1("YABCCBAZ")) # ABCCBA
print(sol2([[1, 2], [3, 4]])) # 3
print(sol2([[14, 3, 6, 4], [15, 7, 5, 8], [20, 11, 12, 10], [9, 2, 3, 1]])) # 10