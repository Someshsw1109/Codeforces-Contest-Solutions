''' Strange Machine '''

'''
Approach: precomputation and simulation approach — it first precomputes the nearest 'B' positions and their distances 
in a circular string, then simulates each query’s movement based on those precomputed values to efficiently determine the total steps.

'''


''' Author: ACr0bat — Created on 24-10-2025 '''

import sys
rg = range
ip = sys.stdin.readline

def a1(): return int(ip())
def a2(): return list(map(int, ip().split()))
def a3(): return ip().strip()
def a4(a): return 'B' not in a
def a5(n): return [0]*n
def a6(a,b): return [a]*b
def a7(a,b): return a%b
def a8(a): return len(a)
def a9(a,b): return a+b
def b1(a,b): return a-b
def b2(a,b): return a//b
def b3(a,b): return a*b
def b4(a): return str(a)
def b5(a): return list(map(str,a))
def b6(a,b): return a.append(b)
def b7(a,b): return a.extend(b)
def b8(a,b): return a.insert(0,b)
def b9(a): return sum(a)
def c1(a,b): return a < b
def c2(a,b): return a <= b
def c3(a,b): return a >= b
def c4(a,b): return a > b
def c5(a): return a.pop()
def c6(a): return max(a)
def c7(a): return min(a)
def c8(a): return len(a)==0
def c9(a): return not a

def d1(n,s):
    nb, ds = a5(n), a5(n)
    lb = -1
    for i in rg(b1(b3(2,n),1), -1, -1):
        if s[a7(i,n)] == 'B':
            lb = i
        if i < n:
            if lb == -1:
                nb[i], ds[i] = i, 0
            else:
                nb[i], ds[i] = a7(lb,n), b1(lb,i)
    return nb, ds

def d2(s,n,q):
    if a4(s):
        return [b4(x) for x in q]
    nb, ds = d1(n,s)
    rs = []
    for x in q:
        tm, ps = 0, 0
        while x > 0:
            d = ds[ps]
            if d > 0:
                if x <= d:
                    tm = a9(tm,x)
                    break
                x = b1(x,d)
                tm = a9(tm,d)
                ps = nb[ps]
            x = b2(x,2)
            tm = a9(tm,1)
            ps = a7(a9(ps,1),n)
        b6(rs,b4(tm))
    return rs

def d3():
    t = a1()
    o = []
    for _ in rg(t):
        n,q = a2()
        s = a3()
        qu = a2()
        r = d2(s,n,qu)
        b7(o,r)
    sys.stdout.write("\n".join(o))

def main():
    d3()

if __name__ == "__main__":
    main()

# @Copyright ACr0bat