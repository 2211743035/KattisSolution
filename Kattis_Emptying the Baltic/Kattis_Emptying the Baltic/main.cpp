//
//  main.cpp
//  Kattis_Emptying the Baltic
//
//  Created by mcr on 21/11/2020.
//

#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
# include <string.h>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<list>
#include<unordered_set>
#include<unordered_map>


#include<utility>
#include<tuple>

#include<algorithm>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

/*
const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;
 struct node
 {
     
     int energy;
     int gold;
     node() {}
     node(int ener, int gol )
     {
         gold=gol;
         energy=ener;
     }
 };
 bool operator <(const node & left, const node & right)
 {
     if (left.energy==right.energy) return left.gold>right.gold;
     return left.energy>right.energy;
 }

*/

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<int>> mapS(h,vector<int> (w));
    vector<vector<ll>> lengthS(h,vector<ll> (w,100000));
    vector<int> adjLis={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            cin>>mapS[i][j];
        }
    }
    int rD,cD;
    cin>>rD>>cD;
    rD--,cD--;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dijQ;
    dijQ.push({mapS[rD][cD], rD*w+cD});
    ll outcome=0;
    lengthS[rD][cD]=mapS[rD][cD];
    
    set<pair<int,int>> vert;
    vert.insert({rD,cD});
    while (!dijQ.empty())
    {
        auto [l,p]=dijQ.top(); dijQ.pop();
        if (l>lengthS[p/w][p%w]) continue;
        int rS=p/w,cS=p%w;
        for (int i=0; i<8; i++)
        {
            int r_=rS+adjLis[i*2];
            int c_=cS+adjLis[2*i+1];
            if (!(r_>=0&&r_<h&&c_>=0&&c_<w&&mapS[r_][c_]<0)) continue;
            if (mapS[r_][c_]>lengthS[rS][cS])
            {
                if (mapS[r_][c_]<lengthS[r_][c_])
                {
                vert.insert({r_,c_});
                dijQ.push({mapS[r_][c_],r_*w+c_});
                lengthS[r_][c_]=mapS[r_][c_];
                //cout<<"from:   "<<rS<<" "<<cS<<lengthS[rS][cS]<<endl;
                //cout<<r_<<" "<<c_<<" "<<lengthS[r_][c_]<<endl;
                }
                else continue;
            }
            else
            {
                if (lengthS[rS][cS]<lengthS[r_][c_])
                {
                    lengthS[r_][c_]=lengthS[rS][cS];
                    dijQ.push({lengthS[r_][c_],r_*w+c_});
                    vert.insert({r_,c_});
                    //cout<<rS<<" "<<cS<<endl;
                   // cout<<r_<<" "<<c_<<" "<<lengthS[r_][c_]<<endl;
                }
            }
        }
    }
    for (auto c: vert)
    {
       // cout<<"aaaa"<<c.first<<" "<<c.second<<" "<<lengthS[c.first][c.second]<<endl;
        outcome+=-1*lengthS[c.first][c.second];
    }
    cout<<outcome<<endl;
    return 0;
}
