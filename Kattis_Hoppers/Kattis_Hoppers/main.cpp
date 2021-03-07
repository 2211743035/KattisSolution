//
//  main.cpp
//  Kattis_Hoppers
//
//  Created by mcr on 27/10/2020.
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
*/
//2 seconds

bool visited[500000+10];
bool used[500000+10];
int flag=1;
vector<list<int>> adjacentLis;
void bfs(int pos)
{
    visited[pos]=true;
    int currentP;
    queue<int> remainV;
    remainV.push(pos);
    while(!remainV.empty())
    {
        currentP= remainV.front();
        remainV.pop();
        visited[currentP]=true;
    for (auto c: adjacentLis[currentP])
    {
        
        if (flag)
        {
        for (auto d: adjacentLis[c])
        {
            for (auto t: adjacentLis[d])
            if(t==currentP) flag=0;
        }
        }
        if (visited[c]==false)
        {
            remainV.push(c);
           // cout<<c<<endl;
        }
    }
 
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N, M;
    cin>>N>>M; // 3≤𝑁≤5e5 and 2≤𝑀≤5e5
    
    for (int i=0; i< 500010; i++)
    {
        visited[i]=false;
        used[i]=false;
    }
    
    adjacentLis.resize(N+1);
    int u, v; //1≤𝑢,𝑣≤𝑁
    for (int i=0 ;i<M; i++)
    {
        cin>>u>>v;
        adjacentLis[u].push_back(v);
        adjacentLis[v].push_back(u);
    }
    int output=-1;
    for (int i=1; i<=N; i++)
    {
        if (visited[i]) continue;
        else
        {
            bfs(i);
            //cout<<i<<" ww"<<endl;
            output+=1;
        }
    }
    output=(output==-1)? 0:output;
    cout<<output+flag<<endl;
    return 0;
}

/*
 总结：
 1. 找聚集类问题的变形
 2. 找到规律很关键， 只有三角形能隔代自洽
 3. 做题时把各变量的范围comments在变量后
 */
