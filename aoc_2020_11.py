#!/bin/python3

import copy

example = open('input11_example.txt').read().split('\n')
example = [list(line) for line in example]

data = open('input11.txt').read().split('\n')
data = [list(line) for line in data]

def countAdjacentSeats(grid, ii, jj):

    def notOutOfBounds(grid, ii, jj):
        return not (ii < 0 or ii >= len(grid) or jj < 0 or jj >= len(grid[ii]))

    X = [ii-1, ii-1, ii-1, ii, ii, ii+1, ii+1, ii+1]
    Y = [jj-1, jj, jj+1, jj-1, jj+1, jj-1, jj, jj+1]
    
    count = 0
    for pos in range(0, 8):
        x = X[pos]
        y = Y[pos]

        if (notOutOfBounds(grid, x, y) and grid[x][y] == '#'):
            count += 1

    return count

def countVisibleSeats(grid, ii, jj):
    count = 0

    for idx in range(jj + 1, len(grid[ii])):
        if grid[ii][idx] == 'L':
            break
        if grid[ii][idx] == '#':
            count += 1
            break

    for idx in range(jj - 1, -1, -1):
        if grid[ii][idx] == 'L':
            break
        if grid[ii][idx] == '#':
            count += 1
            break        

    for idx in range(ii + 1, len(grid)):
        if grid[idx][jj] == 'L':
            break
        if grid[idx][jj] == '#':
            count += 1
            break          

    for idx in range(ii - 1, -1, -1):
        if grid[idx][jj] == 'L':
            break
        if grid[idx][jj] == '#':
            count += 1
            break  

    x = ii; y = jj
    while (x != 0 and y != 0):
        x -= 1; y -= 1
        if grid[x][y] == 'L':
            break
        if grid[x][y] == '#':
            count += 1
            break  

    x = ii; y = jj
    while (x != len(grid) - 1 and y != len(grid[0]) - 1):
        x += 1; y += 1
        if grid[x][y] == 'L':
            break
        if grid[x][y] == '#':
            count += 1
            break  

    x = ii; y = jj
    while (x != 0 and y != len(grid[0]) - 1):
        x -= 1; y += 1
        if grid[x][y] == 'L':
            break
        if grid[x][y] == '#':
            count += 1
            break  

    x = ii; y = jj
    while (y != 0 and x != len(grid) - 1):
        x += 1; y -= 1
        if grid[x][y] == 'L':
            break
        if grid[x][y] == '#':
            count += 1
            break  

    return count

def update1(grid):
    newGrid = copy.deepcopy(grid)

    for ii in range(0, len(grid)):
        for jj in range(0, len(grid[ii])):
            char = grid[ii][jj]

            # If a seat is empty and NO occupied seats adjacent, the seat becomes occupied.
            if char == 'L' and countAdjacentSeats(grid, ii, jj) == 0:
                newGrid[ii][jj] = '#'

            # If a seat is occupied and four or more occupied adjacent, seat becomes empty.
            elif char == '#' and countAdjacentSeats(grid, ii, jj) >= 4:
                newGrid[ii][jj] = 'L'

    return newGrid

def update2(grid):
    newGrid = copy.deepcopy(grid)

    for ii in range(0, len(grid)):
        for jj in range(0, len(grid[ii])):
            char = grid[ii][jj]

            # If a seat is empty and NO occupied seats visible, the seat becomes occupied.
            if char == 'L' and countVisibleSeats(grid, ii, jj) == 0:
                newGrid[ii][jj] = '#'

            # If a seat is occupied and five or more visible adjacent, seat becomes empty.
            elif char == '#' and countVisibleSeats(grid, ii, jj) >= 5:
                newGrid[ii][jj] = 'L'

    return newGrid

def countPassengers(grid):
    count = 0
    for line in grid:
        count += line.count('#')
    return count

oldGrid = data
newGrid = []
while (True):
    newGrid = update1(oldGrid)

    if (oldGrid == newGrid):
        break
 
    oldGrid = newGrid

print('part1', countPassengers(newGrid))

oldGrid = data
while (True):
    newGrid = update2(oldGrid)

    if (oldGrid == newGrid):
        break

    oldGrid = newGrid

print('part2', countPassengers(newGrid))
