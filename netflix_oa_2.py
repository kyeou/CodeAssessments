
# Take a string, and swap every pair of characters. If odd number of characters, leave end alone
# ab => ba
# abc => bac

def sol1(str):
    str = [*str]
    for i in range(0, len(str)-1, 2):
        str[i], str[i+1] = str[i+1], str[i]
    
    return ''.join(str)

print(sol1("abcdefg"))





# Take a arrival time and a schedule and figure out how long you have to wait till the next aval time in the schedule

def sol2(schedule, arrival): # ["12:30", "14:00", "19:55"]
    ns = [int(x.replace(":", "")) for x in schedule]
    for n in ns:
        if int(arrival.replace(":", "")) < n:
            ret = str(n - int(arrival.replace(":", "")))
            ret = f"{ret[0:len(str(ret))-2]}:{ret[len(ret)-2:]}"
            if len(ret) == 4:
                ret = f"0{ret}"
            return f"\"{ret}\""
    return -1

print(sol2(["12:30", "14:00", "19:55"], "14:30"))


# Take an array of nums and determine how many pairs of numbers that exist that are shifts of each other
# [13, 5604, 31, 2, 13, 4560, 546, 654, 456]
# 13 - 31
# 13 - 13
# 31 - 13
# 5604 - 4560
# 546 - 654

def sol3(nums):
    class Node:
        def __init__(self, data, **kwargs): # keyword arguments
            self.data = str(data)[0]

            try:
                self.next = Node(data[1:], len=len(data))
            except IndexError:
                self.next = None

            try:
                self.length = kwargs["len"]
            except KeyError:
                self.length = len(data)


        def __str__(self):
            c = self
            ret = "HEAD: "
            for i in range(self.length):
                ret += c.data + " -> "
                c = c.next
            return ret

    pairs = 0
    nodes = [Node(str(x)) for x in nums]
    
    
    for node in nodes:
        head = node
        c = head
        while c.next is not None:
            c = c.next
        c.next = head

        
            
    rings = {}
    for node in nodes:
        try:
            rings[node.length].append(node)
        except KeyError:
            rings[node.length] = [node]

        
    for key in rings.keys(): # For all the lengths
        for node in rings[key]: # Go through the nums in the array that are of a specified length
            for a in rings[key][rings[key].index(node)+1:]: # Traverse through that same array but excluding the one we are comparing everything to
                find_head_match = a # using this to start at the same number
                for i in range(find_head_match.length):
                    if find_head_match.data == node.data: # if we find the same number
                        if find_head_match.__str__() == node.__str__(): # compare the traversals, if they are same, they are shifts of each other
                            pairs += 1
                            break
                    else:
                        find_head_match = find_head_match.next 
         
    return pairs            

print(sol3([13, 5604, 31, 2, 13, 4560, 546, 654, 456]))


from collections import Counter

def sol3_but_smarter(nums):
    # take a number, and shift it until its the biggest number possible
    # 1234 -> 2341 -> 3412 -> 4123 <= MAX
    def big(num):
        max = num
        s = str(num)
        for _ in s:
            x = int(s[-1] + s[0:-1])
            if x > max:
                max = x
        return max

    circs = [big(z) for z in nums] # do that to all of the numbers in nums
    c = Counter(circs) # count how many times a number shows up
    print(c)
    
    pairs = 0
    for i in c:
        if c[i] > 1: # if a number shows up more than once thats how many pairs there were
            # if you have 123, 231, 312 => 123 paired with 231 and 312 (2 pairs) and 231 paired with 312 
            pairs += c[i]
    return pairs

print(sol3_but_smarter([13, 5604, 31, 2, 13, 4560, 546, 654, 456]))