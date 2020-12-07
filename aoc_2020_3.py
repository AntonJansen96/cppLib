#!/bin/python3

import loaddata as load

data = load.StrList('input.txt')

for idx in range(0, len(data)):

    val = data[idx]

    for _ in range(0, 1000):
        data[idx] += val

# print(data[0])

# array = ['' for _ in range(0, 11)]

# for idx in range(0, len(data)):
#     array[idx % 11] += data[idx]

multiple = 1

trees = 0
x = 0
y = 0
while (y <= len(data) - 1):

    if data[y][x] == '#':
        trees += 1

    x += 1
    y += 1

multiple *= trees

trees = 0
x = 0
y = 0
while (y <= len(data) - 1):

    if data[y][x] == '#':
        trees += 1

    x += 3
    y += 1

multiple *= trees

trees = 0
x = 0
y = 0
while (y <= len(data) - 1):

    if data[y][x] == '#':
        trees += 1

    x += 5
    y += 1

multiple *= trees

trees = 0
x = 0
y = 0
while (y <= len(data) - 1):

    if data[y][x] == '#':
        trees += 1

    x += 7
    y += 1

multiple *= trees

trees = 0
x = 0
y = 0
while (y <= len(data) - 1):

    if data[y][x] == '#':
        trees += 1

    x += 1
    y += 2

multiple *= trees

print(multiple)
