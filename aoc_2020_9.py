#!/bin/python3

data = open('input9.txt').read().split('\n')
data = [int(i) for i in data]

preamble = 25
wrong = 0

for idx in range(preamble, len(data)):

    sums = []
    for ii in range(idx - preamble, idx):
        for jj in range(idx - preamble, idx):
            sums.append(data[ii] + data[jj])
    
    if data[idx] not in sums:
        print('part1', data[idx])
        wrong = data[idx]
        break

done = False
for ii in range(0, len(data)):
    for jj in range(ii, len(data)):
        Sum = sum(data[ii:jj])

        if Sum == wrong:
            print('part2', min(data[ii:jj]) + max(data[ii:jj]))
            done = True
            break

    if (done):
        break