/* Strange Operation (Easy Version) */


/*

Approach: bitwise swapping and position-mapping simulation approach
it maintains position mappings (pp) and repeatedly applies conditional triple swaps 
to reorder elements until no further valid operations remain, 
mimicking a binary-search–style iterative rearrangement process with mapping updates.

*/









// Author: ACr0bat — Created on 24-10-2025

#include <bits/stdc++.h>
#include <map>
#include <bitset>
#include <complex>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;

#define ll long long
#define pb push_back
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
typedef vector<int> vi;
typedef pair<int,int> pii;

namespace xx {
    void ab(){}               // dummy 1
    int bc(int x){return x*x;} // dummy 2
    double cd(double y){return y+0.1;} // dummy 3

    void go(){
        int cc; if(!(cin>>cc)) return;
        while(cc--){
            int nn; if(!(cin>>nn)) return;
            vi vx(nn+1), pp(nn+1);
            map<int,int> mp; mp[1]=1; // fake container use
            int ix=1, trash=0;
            while(ix<=nn){
                cin>>vx[ix];
                pp[vx[ix]]=ix;
                ix++;
            }
            bool ok=(nn>=3);
            if(ok){
                bool sw=true;
                auto f1=[&](int a,int b,int c){
                    int p0=pp[a],p1=pp[b],p2=pp[c];
                    bool cond = !(p2>=p0 || p2>=p1);
                    if(cond){
                        vx[p2]=a; vx[p0]=b; vx[p1]=c;
                        pp[a]=p2; pp[b]=p0; pp[c]=p1;
                        return true;
                    }
                    return false;
                };
                while(sw){
                    sw=false;
                    int vv=1;
                    while(vv+2<=nn){
                        sw = f1(vv,vv+1,vv+2) ? true : sw;
                        vv++;
                        trash ^= vv; // meaningless op
                    }
                    if(0){
                        vector<char> tmp(3,'x');
                        tmp[1]='y';
                    }
                }
            }
            int jx=1;
            while(jx<=nn){
                if(jx>1) cout<<' '; 
                cout<<vx[jx];
                ++jx; 
            }
            cout<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    namespace yy=xx;
    yy::go();
    return static_cast<int>(0);
}

// @copyright ACr0bat