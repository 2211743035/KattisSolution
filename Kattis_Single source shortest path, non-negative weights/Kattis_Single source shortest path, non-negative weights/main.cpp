//
//  main.cpp
//  Kattis_Single source shortest path, non-negative weights
//
//  Created by mcr on 8/11/2020.
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
bool flag=false;
const ll  inf  = 1e18 + 10;
vector<ll> D;
//vector<int> visit;
vector<list<pair<int,int>>> adjacentLis;
int s;// 0≤𝑠<𝑛

inline void relex(int u, pair<int,int> v)
{
    if (D[v.first]>D[u]+v.second)
    {
        D[v.first]=D[u]+v.second;
        flag=true;
    }
        
}

void Dijkstra()
{
    priority_queue<pair<ll, int>,vector<pair<ll,int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0,s));
    //visit[s]=0;
    while(!pq.empty())
    {
        //cout<<1;
        int u=pq.top().second;
        if (D[u]<pq.top().first)
        {
            pq.pop();
            continue;
        }
        pq.pop();
        //visit[u]=1;
        for (auto c: adjacentLis[u])
        {
            flag=false;
            relex(u, c);
            if (flag) pq.push(make_pair(D[c.first],c.first));
            flag=false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;// 1≤𝑛≤10000
    int m;// 0≤𝑚≤30000
    int q;// 1≤𝑞≤100

    cin>>n>>m>>q>>s;
    
    do
    {
        D.resize(n+10,inf);
        //visit.resize(n+10,0);
        D[s]=0;
        adjacentLis.resize(n+10);
        int f, t, w;
        for (int i=0; i<m; i++)
        {
            cin>>f>>t>>w;
            adjacentLis[f].push_back(make_pair(t,w));
        }
        Dijkstra();
        int p;
        for (int i=0; i<q; i++)
        {
            cin>>p;
            if (D[p]==inf) cout<<"Impossible\n";
            else cout<<D[p]<<endl;
        }
        
        D.clear();
        adjacentLis.clear();
        cin>>n>>m>>q>>s;
    }while(!(n==0 && m==0&&q==0&&s==0));
    return 0;
}
