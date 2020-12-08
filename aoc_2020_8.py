#!/bin/python3

import copy # for deepcopy

data = open('input8.txt').read().split('\n')

# PART 1
accumulator = 0
used = [0 for i in range(0, len(data))]     # To keep count of which instructions
                                            # were used.
idx = 0
while (idx < len(data)):

    line        = data[idx]
    instruction = line[:3]
    value       = int(line[4:])

    if 2 in used:                   # If instruction used more than once...
        print('part1', accumulator)
        break

    if (instruction == 'nop'):
        idx += 1

    elif (instruction == 'acc'):
        accumulator += value
        idx += 1
    
    elif (instruction == 'jmp'):
        idx += value

    used[idx] += 1                  # Mark this instruction as used.

# Returns accumulator if terminates within 10'000 steps, returns 0 if not.
def checkinfinite(data):
    accumulator = 0
    executions  = 0

    idx = 0     # stop if > 10'000 executions or we are beyond last instruction
    while (executions < 10000 and idx < len(data)):

        line        = data[idx]
        instruction = line[:3]
        value       = int(line[4:])

        executions += 1

        if (instruction == 'nop'):
            idx += 1

        elif (instruction == 'acc'):
            accumulator += value
            idx += 1
        
        elif (instruction == 'jmp'):
            idx += value

    if (executions < 10000):
        return accumulator
    else:
        return 0

# PART 2
for idx in range(0, len(data)):
    data2 = copy.deepcopy(data)
    
    if data2[idx][:3] == 'nop':
        data2[idx] = "%s %s" % ('jmp', data2[idx][4:])
    
    elif data2[idx][:3] == 'jmp':
        data2[idx] = "%s %s" % ('nop', data2[idx][4:])

    if (checkinfinite(data2) != 0):
        print('part2', checkinfinite(data2))
        break
