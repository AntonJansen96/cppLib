#!/bin/python3

data = open("input10.txt").read().split('\n')
data = [int(i) for i in data]

# example = data
# used    = [0 for i in range(0, len(data))]

example = [16, 10, 15, 5, 1, 11, 7, 19, 6, 12, 4]
used    = [0 for i in range(0, len(example))]

chain   = [0]

def differenceCoutner(array):
    count1 = 0
    count2 = 1 # Adapter always 3 higher than highest.
    for idx in range(0, len(array) - 1):
        if array[idx] + 1 == array[idx + 1]:
            count1 += 1
        
        elif array[idx] + 3 == array[idx + 1]:
            count2 += 1
    
    # print(count1, count2) # debug

    return count1 * count2

def solve(example, used, chain):
    
    if (sum(used) == len(used)): # if every number in input was used
        return chain
    
    # print(example, used, chain) # debuf

    for idx in range(0, len(example)):
        if used[idx] != 1:
            if chain[-1] >= example[idx] - 3 and chain[-1] <= example[idx] + 3:
                chain.append(example[idx])
                used[idx] = 1
                return solve(example, used, chain)

answer = solve(sorted(example), used, chain)



print(answer)

################################################################################

# #!/bin/python3

# data = open("input10.txt").read().split('\n')
# data = [int(i) for i in data]

# example = data
# used    = [0 for i in range(0, len(data))]

# # example = [16, 10, 15, 5, 1, 11, 7, 19, 6, 12, 4]
# # used    = [0 for i in range(0, len(example))]

# chain   = [0]

# def differenceCoutner(array):
#     count1 = 0
#     count2 = 1 # Adapter always 3 higher than highest.
#     for idx in range(0, len(array) - 1):
#         if array[idx] + 1 == array[idx + 1]:
#             count1 += 1
        
#         elif array[idx] + 3 == array[idx + 1]:
#             count2 += 1
    
#     # print(count1, count2) # debug

#     return count1 * count2

# def solve(example, used, chain):
    
#     if (sum(used) == len(used)): # if every number in input was used
#         return chain
    
#     # print(example, used, chain) # debuf

#     for idx in range(0, len(example)):
#         if used[idx] != 1:
#             if chain[-1] >= example[idx] - 3 and chain[-1] <= example[idx] + 3:
#                 chain.append(example[idx])
#                 used[idx] = 1
#                 return solve(example, used, chain)

# answer = solve(sorted(example), used, chain)
# # print(answer) # debug
# print('part1', differenceCoutner(answer))
