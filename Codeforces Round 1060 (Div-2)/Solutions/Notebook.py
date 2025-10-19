# Approach:

'''
Greedy approach, selecting '1's from left to right.
Each '1' is chosen only if it is at least k distance away from the last selected one.

'''

''' Author: ACr0bat — created on 19-10-2025 '''

import sys
rd = sys.stdin.readline

def g1():
    return int(rd())

def g2():
    x, y = rd().split()
    return int(x), int(y)

def g3():
    return rd().strip()

def g4(st):
    r, j = [], 1
    for ch in st:
        if ch == '1':
            r.append(j)
        j += 1
    return r

def g5(lst, d):
    ln = len(lst)
    if ln == 0:
        return 0
    if ln == 1:
        return 1
    t = 1
    c = lst[0]
    i = 1
    while i < ln:
        z = lst[i] - c
        if z >= d:
            t += 1
        c = lst[i]
        i += 1
    return t

def run():
    q = g1()
    for _ in range(q):
        n, k = g2()
        s = g3()
        arr = g4(s)
        res = g5(arr, k)
        print(res)

if __name__ == "__main__":
    run()

# @Copyright ACr0bat
