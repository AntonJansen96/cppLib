#!/bin/python3

def check1(passport):
    if  (passport.find('byr') != -1) and (passport.find('iyr') != -1) \
    and (passport.find('eyr') != -1) and (passport.find('hgt') != -1) \
    and (passport.find('hcl') != -1) and (passport.find('ecl') != -1) \
    and (passport.find('pid') != -1):
        return True
    
    return False

def check2(passport):
    if not check1(passport):
        return False;
    
    def getSpaceIndex(string, startIdx):
        for ii in range(startIdx, len(string)):
            if string[ii] == ' ':
                return ii

    # BYR
    idx = passport.find('byr')
    val = int(passport[idx + 3 + 1:getSpaceIndex(passport, idx)])
    
    if (val < 1920 or val > 2002):
        return False

    # IYR
    idx = passport.find('iyr')
    val = int(passport[idx + 3 + 1:getSpaceIndex(passport, idx)])

    if (val < 2010 or val > 2020):
        return False

    # EYR
    idx = passport.find('eyr')
    val = int(passport[idx + 3 + 1:getSpaceIndex(passport, idx)])

    if (val < 2020 or val > 2030):
        return False

    # HGT
    idx = passport.find('hgt')
    val = passport[idx + 3 + 1:getSpaceIndex(passport, idx)]
    
    last  = val[len(val)-2:len(val)]

    if last not in ['cm', 'in']:
        return False

    first = int(val[0:len(val)-2])

    if (last == 'cm'):
        if (first < 150 or first > 193):
            return False
    elif (last == 'in'):
        if (first < 59 or first > 76):
            return False

    # HCL
    idx = passport.find('hcl')
    val = passport[idx + 3 + 1:getSpaceIndex(passport, idx)]

    if len(val) != 7 or val[0] != '#':
        return False

    # val = val[1:len(val)]
    # for char in val:
    #     if char not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']:
    #         return False

    # ECL
    idx = passport.find('ecl')
    val = passport[idx + 3 + 1:getSpaceIndex(passport, idx)]

    if val not in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']:
        return False

    # PID
    idx = passport.find('pid')
    val = passport[idx + 3 + 1:getSpaceIndex(passport, idx)]

    if len(val) != 9:
        return False

    # for char in val:
    #     if char not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
    #         return False

    return True

with open('input.txt', 'r') as file:
    lines = file.read()

passportList = lines.split(',')

count = 0
for passport in passportList:
    if check2(passport):
        count += 1

print(count)

# zit er één naast?
