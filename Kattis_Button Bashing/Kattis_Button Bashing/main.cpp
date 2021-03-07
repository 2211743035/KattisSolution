//
//  main.cpp
//  Kattis_Button Bashing
//
//  Created by mcr on 16/11/2020.
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
vector<int> times;
vector<int> adjacentLis;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        //cout<<"???"<<endl;
        int n,t;
        cin>>n>>t;
        times.clear();
        adjacentLis.clear();
        times.resize(3601,1000000);
        //adjacentLis.resize(n);
        for (int i=0; i<n; i++)
        
        {
            int d;
            cin>>d;
            adjacentLis.push_back(d);
        }
        queue<int> bfsQ;
        times[0]=0;
        bfsQ.push(0);
        while(!bfsQ.empty())
        {
            int u=bfsQ.front();
            bfsQ.pop();
            for (auto c: adjacentLis)
            {
                int f;
                if (u+c>3600)  f=3600;
                else if (u+c<0) f=0;
                else f=u+c;
                
                if (times[u]+1<times[f])
                {
                    times[f]=times[u]+1;
                    bfsQ.push(f);
                }
            }
        }
        for (int i=t; i<=3600; i++)
        {
            if (times[i]!=1000000)
            {
                cout<<times[i]<<" "<<i-t<<endl;
                break;
            }
        }
    }
    return 0;
}

/*
 总结：
 1. 注意3600和0的两个边界条件
 2. 这题其实像bfs，也像optimized bellman-ford
 3. 注意下一个能到的点暗示要计算多个点的最短距离
 
 
 */
