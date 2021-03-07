//
//  main.cpp
//  Kattis_Flowery Trails
//
//  Created by mcr on 7/11/2020.
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

const int mod  = 1000000007;
const ld  prec = .000001;

 bool operator <(const node & left, const node & right)
 {
     if (left.energy==right.energy) return left.gold>right.gold;
     return left.energy>right.energy;
 }

*/

struct node
{
    
    int from;
    int to;
    int weight;
    node() {}
    node(int fro, int t, int weigh )
    {
        from=fro;
        to=t;
        weight=weigh;
    }
};
const ll  inf  = 1e18 + 10;
ll length[10010];

vector<vector<pair<int,int>>> track_back;
vector<list<node>> adjacentLis;
unordered_map<ll,int> edgeNum;
vector<bool> status;
int P=2; // 2≤𝑃≤10000 Number of points.
int T=2; // 1≤𝑇≤250000 Number of trails.
ll totalLength=0;
 
void Dijkstra()
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> chooseEdge;
    chooseEdge.push(make_pair(0,0));
    while(!chooseEdge.empty())
    {
        int u=chooseEdge.top().second;
        chooseEdge.pop();
        status[u]=true;
        ll MIN=inf;
        if (!adjacentLis[u].empty())
        {
            if (length[u]>MIN) continue;
            for (auto c: adjacentLis[u])
            {
                
                int toPos=c.to;
                
                //cout<<toPos<<endl;
                if (c.to==P-1)
                {
                    MIN=min(MIN,length[P-1]);
                }
                if (!status[toPos] && length[toPos]>length[u]+c.weight)
                {
                    //list<int> temp={u};
                    track_back[toPos].clear();
                    track_back[toPos].push_back(make_pair(u,c.weight));
                    //cout<<c.to<<" "<<u<<" "<<c.weight<<endl;
                    length[toPos]=length[u]+c.weight;
                    chooseEdge.push(make_pair(length[toPos],toPos));
                    
                }
                else if(!status[toPos] && length[toPos]==length[u]+c.weight)
                {
                    track_back[toPos].push_back(make_pair(u,c.weight));
                }
            }
        }
        
    }
}

//O(VlogV +E)
void bfs()
{
    vector<int> visited ;
    visited.resize(P+10, 0);
    queue<int> onBfs;
    onBfs.push(P-1);
    while(!onBfs.empty())
    {
        //cout<<onBfs.size()<<endl;
        int u=onBfs.front();
        onBfs.pop();
        visited[u] = 1;
        set<pair<int,int>> adj (track_back[u].begin(),track_back[u].end());
        for (auto c: adj)
        {
            if (visited[c.first]==0)
            {
                totalLength+=c.second*edgeNum[max(c.first,u)*10001+min(c.first, u)+c.second*1000000000];
                //cout<<c.first<<" "<<u<<" "<<c.second<<"*"<<edgeNum[max(c.first,u)*10001+min(c.first, u)+c.second*1000000000]<<"="<<c.second*edgeNum[max(c.first,u)*10001+min(c.first, u)+c.second*1000000000]<<endl;
                if (c.first!=0)
                onBfs.push(c.first);
            }
        }
    }
}
//O(V+E)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>P>>T;
    status.resize(P+10,false);
    adjacentLis.resize(P+10);
    track_back.resize(P+10);
    int p1,p2,l;
    while(T--)
    {
        cin>>p1>>p2>>l;
        if (edgeNum.count(max(p1,p2)*10001+min(p1,p2)+l*1000000000))
        {
            edgeNum[max(p1,p2)*10001+min(p1,p2)+l*1000000000]+=1;
        }
        else
        {
            //cout<<p1<<" "<<p2<<" "<<l<<endl;
        edgeNum[max(p1,p2)*10001+min(p1,p2)+l*1000000000]=1;
        adjacentLis[p1].push_back(node(p1,p2,l));
        adjacentLis[p2].push_back(node(p2,p1,l));
            
        }
    }
    for (int i=1; i<10010; i++)
    {
        length[i]=inf;
    }
    length[0]=0;
    Dijkstra();
    bfs();
    cout<<totalLength*2<<endl;
    return 0;
}
