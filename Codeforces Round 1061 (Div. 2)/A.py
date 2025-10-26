''' Pizza Time '''


'''
Approach - iterative greedy division approach to repeatedly exchange every 3 units for 1 unit until fewer than 3 remain, summing all obtained units.

'''

''' Author: ACr0bat — Created on 24-10-2025 '''

# write your code here

import sys
rg = range

def ia(): return int(input())
def ib(): return int(input())
def ic(): return int(input())
def id(x): return x // 3
def ie(x): return x - 2 * (x // 3)
def ig(x): return x > 2
def ih(x, y): return x + y
def ii(): return sys.stdin.readline
def ij(): return ii()
def ik(): return int(ij())
def il(): return int(ij())
def im(): return int(ij())
def in_(): return int(ij())
def io(x): return print(x)
def ip(x): return x
def iq(x): return x
def ir(x): return x
def is_(x): return x
def it(x): return x
def iu(x): return x
def iv(x): return x
def iw(x): return x
def ix(x): return x
def iy(x): return x
def iz(x): return x

def ja(n):
    a = 0
    while ig(n):
        m = jb(n)
        a = ih(a, m)
        n = jc(n)
    return a

def jb(x): return id(x)
def jc(x): return ie(x)
def jd(): return ik()
def je(): return il()
def jf(): return im()
def jg(): return in_()
def jh(x): io(x)
def ji(): return

def solve():
    input = ii()
    t = ia()
    for _ in rg(t):
        n = ib()
        a = ja(n)
        jh(a)

if __name__ == "__main__":
    solve()



# @Copyright ACr0bat