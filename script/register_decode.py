#!/usr/bin/env python3
# 12:57
# 13:18 done

import sys
import functools


def convert_int(s):
    if s.startswith('0x'):
        return int(s[2:], 16)
    else:
        return int(s)

# input [1,0,1], return sum([1*4, 0*2, 1])


def list_sum(v):  # like: [1,0,1,0]
    sum = 0
    for i in range(len(v)):
        sum = sum * 2 + v[i]
    return sum


def parse_xpsr(name, value):
    reg = {
        'xpsr': {
            'N': 31,
            'Z': 30,
            'C': 29,
            'V': 28,
            'Q': 27,
            'T': 24,
            'ICI/IT': [26, 25, 15, 14, 13, 12, 11, 10],
            'ExceptionNumber': [8, 7, 6, 5, 4, 3, 2, 1, 0],
        },
        'scb_icsr': {
            'NMIPENDSET': 31,
            'PENDSVSET': 28,
            'PENDSVCLR': 27,
            'PENDSTSET': 26,
            'PENDSTCLR': 25,
            'ISRPREEMPT': 23,
            'ISRPENDING': 22,
            'VECTPENDING': [20, 19, 18, 17, 16, 15, 14, 13, 12],
            'RETTOBASE': 11,
            'VECTACTIVE': [8, 7, 6, 5, 4, 3, 2, 1, 0],
        }
    }
    t = reg[name]
    for key in t:
        # print (f'key = {key}')
        if type(t[key]) == type(0):  # integer
            bit_value = (value & (1 << t[key])) >> t[key]
            if bit_value > 0:
                # print(f'{key}: {bit_value}, ', end='')
                print(f'{key}, ', end='')
        elif type(t[key]) == type([]):  # list
            bits = list_sum(
                list(map(lambda x: ((value & (1 << x)) >> x), t[key])))
            print(f'{key}: {hex(bits)}, {bits}, ', end='')
    print()


def main():
    # print("main")
    if len(sys.argv) >= 3:
        reg_name = sys.argv[1]
        reg_value = convert_int(sys.argv[2])
    else:
        exit(0)

    parse_xpsr(reg_name, reg_value)


if __name__ == '__main__':
    main()
