//
//  main.cpp
//  Kattis_Bumped!
//
//  Created by mcr on 23/11/2020.
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
const ll  inf  = 1e18 + 10;
int n, m, f,s,t;
vector<list<pair<int,int>>> adjRoad;
vector<list<int>>adjFlight;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>f>>s>>t;
    adjRoad.resize(n); adjFlight.resize(n);
    for (int i=0; i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjRoad[u].push_back({v,w});
        adjRoad[v].push_back({u,w});
    }
    for (int j=0; j<f; j++)
    {
        int u,v;
        cin>>u>>v;
        adjFlight[u].push_back(v);
    }
    vector<vector<ll>> length (n, vector<ll>(2,inf));
    length[s][0]=0;
    set<pair<int,int>> roadDijQ, flitedDijQ;
    roadDijQ.insert({0,s});
    while (!roadDijQ.empty())
    {
        auto c=*roadDijQ.begin(); roadDijQ.erase(c);
        if(c.first>length[c.second][0]) continue;
        int dis=c.first, u=c.second;
        for (auto v: adjRoad[u])
        {
            if (v.second + length[u][0]<length[v.first][0])
            {
                roadDijQ.erase({length[v.first][0],v.first});
                length[v.first][0]=v.second + length[u][0];
                roadDijQ.insert({length[v.first][0],v.first});
            }
        }
        for (auto v:adjFlight[u])
        {
            if ( length[u][0]<length[v][1])
            {
                flitedDijQ.erase({length[v][1],v});
                length[v][1]=length[u][0];
                flitedDijQ.insert({length[v][1],v});
                
            }
        }
    }
    //cout<< *flitedDijQ.begin()->first<<" "<<*flitedDijQ.begin()->second<<endl;
    while(!flitedDijQ.empty())
    {
        auto c=*flitedDijQ.begin(); flitedDijQ.erase(c);
        if(c.first>length[c.second][1]) continue;
        int dis=c.first, u=c.second;
      //  cout<<dis<<" "<<u<<" "<<length[u][0]<<" "<<length[u][1]<<endl;
        for (auto v: adjRoad[u])
        {
           // cout<<v.second + length[u][1]<<" "<<length[v.first][1]<<endl;
            if (v.second + length[u][1]<length[v.first][1])
            {
                //cout<<1<<endl;
                flitedDijQ.erase({length[v.first][1],v.first});
                length[v.first][1]=v.second + length[u][1];
                flitedDijQ.insert({length[v.first][1],v.first});
            }
        }
    }
    cout<<min(length[t][0],length[t][1])<<endl;
    return 0;
}

/*
 总结：
 1. 最短路径多状态可以考虑用多维矩阵
 2. length[][0]为只开车耗时， length[][1]为做了一次飞机的耗时
 */
