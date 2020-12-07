#!/bin/python3

import string

forms = open('input6.txt').read().split('\n\n')     # split by empty lines

count1 = 0
count2 = 0
for group in forms:
    for letter in list(string.ascii_lowercase):
        if (group.count(letter) > 0):
            count1 += 1
                                                    # number of persons
        if (group.count(letter) == group.count('\n') + 1):
            count2 += 1
        
print('part 1', count1)
print('part 2', count2)
