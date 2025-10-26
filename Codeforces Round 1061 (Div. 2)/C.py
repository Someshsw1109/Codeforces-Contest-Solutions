''' Maximum GCD on whiteboard '''

'''
Approach: prefix sum with reverse simulation approach
it builds prefix frequency arrays and then iterates backward 
to find the largest valid index where subtree-like cumulative conditions meet the given threshold k.

'''





''' Author: ACr0bat — Created on 24-10-2025 '''

import sys
rg = range
ip = sys.stdin.readline

def a1(): return int(ip())
def a2(): return list(map(int, ip().split()))
def a3(n): return [0]*(n+1)
def a4(a): return len(a)
def a5(a,b): return a+b
def a6(a,b): return a-b
def a7(a,b): return a*b
def a8(a,b): return a//b
def a9(a,b): return min(a,b)
def b1(a,b): return max(a,b)
def b2(a): return sum(a)
def b3(a): return list(map(str,a))
def b4(a): return print(a)
def b5(a,b): return a.append(b)
def b6(a,b): return a.extend(b)
def b7(a): return str(a)
def b8(a,b): return a[a6(a4(a),b):]
def b9(a): return reversed(a)
def c1(a): return [0]*a
def c2(a): return [0 for _ in rg(a)]
def c3(a,b): return list(map(a,b))
def c4(a,b): return list(zip(a,b))
def c5(a): return enumerate(a)
def c6(a,b): return a[b]
def c7(a,b,v): a[b]=v
def c8(a,b): return a[b:]
def c9(a): return a.copy()
def d1(a): return sorted(a)
def d2(a): return list(reversed(a))
def d3(a,b): return a.index(b) if b in a else -1

def e1(n): return a3(n)
def e2(n): return a3(n)
def e3(a,n):
    f = e1(n)
    for x in a:
        f[x] = a5(f[x],1)
    return f
def e4(f,n):
    p = e2(n)
    for v in rg(1,a5(n,1)):
        p[v] = a5(p[a6(v,1)], f[v])
    return p

def e5(d,n):
    return b1(a7(4,d)-1,0)
def e6(u,n):
    return a9(u,n)
def e7(f,p,d,n,k):
    u = e5(d,n)
    u = e6(u,n)
    cL = p[u]
    s = 0
    if d <= n: s = a5(s,f[d])
    if a7(2,d) <= n: s = a5(s,f[a7(2,d)])
    if a7(3,d) <= n: s = a5(s,f[a7(3,d)])
    b = a6(cL,s)
    return (b <= k)

def e8(f,p,n,k):
    a = 1
    for d in b9(rg(1,a5(n,1))):
        if e7(f,p,d,n,k):
            a = d
            break
    return a

def e9():
    t = a1()
    for _ in rg(t):
        n,k = a2()
        a = a2()
        f = e3(a,n)
        p = e4(f,n)
        r = e8(f,p,n,k)
        b4(r)

def main():
    e9()

if __name__ == "__main__":
    main()

# @Copyright ACr0bat
