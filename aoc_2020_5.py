#!/bin/python3

import loaddata as load

data = load.StrList('input5.txt')

def computeRow(boardingPass):
    row = [i for i in range(0, 128)]
    # print(row)

    if boardingPass[0] == 'B':
        row = row[64:128]
    else:
        row = row[0:64]

    if boardingPass[1] == 'B':
        row = row[32:64]
    else:
        row = row[0:32]
    
    if boardingPass[2] == 'B':
        row = row[16:32]
    else:
        row = row[0:16]

    if boardingPass[3] == 'B':
        row = row[8:16]
    else:
        row = row[0:8]

    if boardingPass[4] == 'B':
        row = row[4:8]
    else:
        row = row[0:4]

    if boardingPass[5] == 'B':
        row = row[2:4]
    else:
        row = row[0:2]

    if boardingPass[6] == 'B':
        row = row[1]
    else:
        row = row[0]

    return row

def computeCol(boardingPass):
    col = [0, 1, 2, 3, 4, 5, 6, 7]

    if (boardingPass[7] == 'R'):
        col = col[4:8]
    else:
        col = col[0:4]

    if (boardingPass[8] == 'R'):
        col = col[2:4]
    else:
        col = col[0:2]
    
    if (boardingPass[9] == 'R'):
        col = col[1]
    else:
        col = col[0]

    return col

def seatID(boardingPass):
    return 8 * computeRow(boardingPass) + computeCol(boardingPass)

# Assert example
test = 'FFFBBBFRRR'
print(computeRow(test), computeCol(test), seatID(test))

array = [0 for i in range(0, 865)]

seatIDs = []
for boardingPass in data:
    seatIDs.append(seatID(boardingPass))
    array[seatID(boardingPass)] = seatID(boardingPass)

for idx in range(1, 865):
    print(idx, array[idx])