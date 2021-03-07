//
//  main.cpp
//  Kattis_Conservation
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


int n, m; // 1≤𝑛≤100000, 0≤𝑚≤1000000
typedef vector<int> vi;
vi nodeType;

int topoSort(vi indegree, vector<vector<pair<int,int>>> adjacentLis, int startSide )
{
int cost=0;
queue<int> kahnQ1,kahnQ2;
for (int i=1; i<=n; i++)
{
    if (indegree[i]==0)
    {
        if (nodeType[i]==1) kahnQ1.push(i);
        else kahnQ2.push(i);
    }
}

while(!kahnQ1.empty()|| !kahnQ2.empty())
{
    if (startSide==1)
    {
    while(!kahnQ1.empty())
    {
        int u=kahnQ1.front();
        kahnQ1.pop();
        for (auto c: adjacentLis[u])
        {
            indegree[c.second]--;
            if (indegree[c.second]==0)
            {
                if (nodeType[c.second]==1) kahnQ1.push(c.second);
                else kahnQ2.push(c.second);
            }
        }
    }
    }
    else
    {
    while(!kahnQ2.empty())
    {
        int u=kahnQ2.front();
        kahnQ2.pop();
        for (auto c: adjacentLis[u])
        {
            indegree[c.second]--;
            if (indegree[c.second]==0)
            {
                if (nodeType[c.second]==1) kahnQ1.push(c.second);
                else kahnQ2.push(c.second);
            }
        }
    }
    }
    cost++;
    startSide=startSide==1 ? 2:1;
    
}
    return cost-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<vector<pair<int,int>>> adjacentLis;

    vi indegree;
    int T; // 1≤𝑇≤35000.

    cin>>T;
    while(T--)
    {
        adjacentLis.clear();
        nodeType.clear();
        indegree.clear();
        cin>>n>>m;
        nodeType.resize(n+10);
        adjacentLis.resize(n+10);
        indegree.resize(n+10,0);
        for (int i=1; i<=n; i++)
        {
            cin>>nodeType[i];
        }
        for (int i=0 ;i<m; i++)
        {
            int a, b;
            cin>>a>>b;
            if (nodeType[a]==nodeType[b])
            {
                adjacentLis[a].emplace_back(0,b);
            }
            else
            {
                adjacentLis[a].emplace_back(1,b);
            }
            indegree[b]++;
        }

        cout<<min(topoSort(indegree,adjacentLis,1),topoSort(indegree,adjacentLis,2))<<endl;
    }
    return 0;
}

/*
 总结：
 1. kahn algo的变型
 2. 每次每边尽量多的消完点再去另一边
 3. 注意： 哪怕没有dependency,也得去另一边
 4. 哪边先开始消可能会影响最终结果
 */
