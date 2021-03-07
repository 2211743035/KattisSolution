//
//  main.cpp
//  Kattis_Visualgo
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
int outcome=0;
vector<unordered_set<int>>parent;
int s,t;
void dfs (int pos)
{
   // cout<<pos<<" ";
    for (auto c: parent[pos])
    {
        /*
        if(c.second==0)
        {
            continue;
        }
         */
        //parent[pos].erase(c);
       // parent[pos].insert({c.first,0});
        if (c==s)
        {
            outcome++;
            //cout<<c<<endl;
            continue;
        }
        
        dfs(c);
      
    }
}
int inf=2000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int V,E;
    cin>>V>>E;
    vector<list<pair<int,int>>> adjLis;
    adjLis.resize(V);
    vector<int> length;

    length.resize(V,inf);
    int u,v,w;
    
    for (int i=0; i<E; i++)
    {
        cin>>u>>v>>w;
        adjLis[u].push_back({v,w});
        
    }
    
    cin>>s>>t;
    length[s]=0;
    //priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> dijQ;
    set<pair<int,int>,less<pair<int,int>>> dijQ;
    if (s==t)
        {
            cout<<1<<endl;
            return 0;
        }
    dijQ.insert({0,s});

   // cout<<1<<endl;
    vector<int> ways(V,0);
    ways[s]=1;
    while(!dijQ.empty())
    {
        auto p=* dijQ.begin(); dijQ.erase(p);
        //cout<<l<<" "<<v<<" "<<length[v]<<endl;
        int v=p.second;
        if (p.first>length[v]) continue;
       // cout<<1<<endl;
        for (auto c:  adjLis[v])
        {
          //  cout<<c.first<<" "<<c.second<<" wuwuw "<<length[c.first]<<endl;
            if (length[v]+c.second<length[c.first])
            {
               // cout<<c.first<<" "<< length[c.first]<<endl;
                dijQ.erase({ length[c.first],c.first});
                length[c.first]=   length[v]+c.second;
                dijQ.insert({ length[c.first],c.first});
                //parent[c.first].clear();
              //  parent[c.first].insert(v);
                ways[c.first]=ways[v];
              // cout<<v<<" "<<c.first<<"kkk"<<endl;
              // cout<<c.first<<" "<<ways[c.first]<<endl;
            }
            else if (length[v]+c.second==length[c.first])
            {
             //  cout<<v<<" "<<c.first<<"kkk"<<endl;
             //  cout<<c.first<<" "<<ways[c.first]<<"???"<<endl;
                
                //parent[c.first].insert(v);
                ways[c.first]+=ways[v];
            }
        }
    }
   // cout<<length[t]<<endl;

    //dfs(t);
    cout<<ways[t]<<endl;
    return 0;
}
/*
 总结：
 1. 要track多条路径时最好用original dijkstra
 2. 动态规划计算最短路径条数
 */
