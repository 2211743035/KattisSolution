//
//  main.cpp
//  Kattis_Pick up sticks
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
typedef vector<int> vi;
vector<list<int>> adjacentLis;
vi indegree;
int countNum=0;
queue<int> kahnQ;
vi topoSort;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    adjacentLis.resize(n+10);
    indegree.resize(n+10,0);
    
    int a,b;
    for (int i=0; i<m; i++)
    {
        cin>>a>>b;
        adjacentLis[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0) kahnQ.push(i);
    }
    if (kahnQ.size()==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while (!kahnQ.empty())
    {
        int u=kahnQ.front();
        kahnQ.pop();
        topoSort.push_back(u);
        countNum++;
        for (auto c: adjacentLis[u])
        {
            indegree[c]--;
            if (indegree[c]==0) kahnQ.push(c);
        }
        if (countNum>n)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for (auto c: topoSort)
    {
        cout<<c<<endl;
    }

    return 0;
}

/*
 拓扑排序
 */
