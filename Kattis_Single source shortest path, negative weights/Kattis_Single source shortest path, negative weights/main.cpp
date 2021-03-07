//
//  main.cpp
//  Kattis_Single source shortest path, negative weights
//
//  Created by mcr on 22/11/2020.
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
const int iinf = 20000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n, m, q, s;
   do
    {
    cin>>n>>m>>q>>s;
        if ( n==0&& m==0&&q==0&& s==0) break;
        vector<list<int>> adjLis;
        adjLis.resize(n);
    vector<pair<pair<int,int>,int>> edgeLis;
    vector<int> length(n,iinf);
    vector<int> parent(n);
    length[s]=0;
    int u,v,w;
    for (int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        edgeLis.push_back({{u,v},w});
        //adjLis[u].push_back(v);
    }
    int flag=1;
    for (int i=0; i<n-1; i++)
    {
        flag=1;
        for (auto c: edgeLis)
        {
            if (length[c.first.first]!=iinf&&length[c.first.first]+c.second<length[c.first.second])
            {
                length[c.first.second]=length[c.first.first]+c.second;
               // parent[c.first.second]=c.first.first;
                flag=0;
            }
        }
        if (flag==1)
        {
           // flag=i;
            break;
        }
    }

    /*
    queue<int> infQ;
        for(auto c:edgeLis)
        {
            if (length[c.first.second]>length[c.first.first]+c.second)
            {
                //length[c.first.second]=-1*inf;
                //cout<<c.first.second<<" "<<length[c.first.second]<<" "<<c.first.first<<" "<<length[c.first.first]+c.second<<endl;
                int t=c.first.second;
                infQ.push(c.first.second);
                //length[c.first.second]=-1*iinf;
                length[c.first.first]=-1*iinf;
                
                while(length[t]!=-1*iinf)
                {
                   
                    length[t]=-1*iinf;
                    t=parent[t];
                }
                 
            }
        }
        while(!infQ.empty())
        {
            int u=infQ.front();infQ.pop();
            for (auto c: adjLis[u])
            {
                if (length[c]!=-1*iinf)
                {
                    length[c]!=1*iinf;
                    infQ.push(c);
                }
            }
        }
    */
    for (int i=0; i<n; i++)
    {
        for (auto c: edgeLis)
        {
            if (length[c.first.first]!=iinf&&length[c.first.first]+c.second<length[c.first.second])
            {
                length[c.first.second]=-iinf;
            }
        }
    }

    for (int i=0; i<q; i++)
    {
        int qs;
        cin>>qs;
        if (length[qs]==iinf) cout<<"Impossible\n";
        else if (length[qs]==-1*iinf) cout<<"-Infinity"<<endl;
        else cout<<length[qs]<<endl;
    }
    cout<<endl;
    }while (!(n==0&& m==0&&q==0&& s==0));
    return 0;
}

/*
 总结：
 1. 用bellman ford algorithm找到所有点的距离（可能包含negative cycle）
    需要两轮bellman ford：
    a. 第一轮, detect nagative cycle
    b. 第二轮, 对于不满足最短距离（i.e. for edge u-v dis[v]>dis[u]+weight(u-v)) 把v标为-inf
 2. 注意！！！： 对于包含negative-weighted edge 的graph relax的条件是（dis[u]!=inf&&dis[v]>dis[u]+weight(u-v))而不是简单的（dis[v]>dis[u]+weight(u-v)) 否则本来的initial值可能会被不断relax
 */
