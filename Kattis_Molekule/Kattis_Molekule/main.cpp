//
//  main.cpp
//  Kattis_Molekule
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
int vertexColor[100000+10],firstEle[100000+10],visited[100000+10];
vector<list<int>> adjacentLis;
void bfs(int startPos)
{
    queue<int> sequence;
    vertexColor[startPos]=0;
    sequence.push(startPos);
    while(!sequence.empty())
    {
        int u=sequence.front();
        sequence.pop();
        visited[u]=1;
        int paintColor=vertexColor[u]? 0:1;
        for (auto c: adjacentLis[u])
        {
            if (visited[c]==0)
            {
                sequence.push(c);
                vertexColor[c]=paintColor;
            }
        }
            
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N; //𝑁  (2≤𝑁≤100000)
    cin>>N;
    int a, b;//1≤a,b≤100000
    adjacentLis.resize(N+1);
    for (int i=0; i<100000+10; i++)
    {
        vertexColor[i]=-1;
        firstEle[i]=-1;
        visited[i]=0;
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>a>>b;
        adjacentLis[a].push_back(b);
        adjacentLis[b].push_back(a);
        firstEle[i]=a;
    }
    bfs(firstEle[0]);
    for (int i=0; i<N-1; i++)
    {
        cout<<vertexColor[firstEle[i]]<<endl;
    }
    return 0;
}

/*

 总结：
 1. 做题前要想清楚，做笔记， 标出每个变量的取值范围， 不要用oj试错
 2. 知识点：
    a. 树是一个bipartite
    b. bipartite可以用染色法把两类分出来
    c. 要想走的最近，就要让每个node相邻的所有nodes同时指向自己或指出去（两类nodes）
    d. 当graph涉及两类nodes时考虑bipartite
            
 */
