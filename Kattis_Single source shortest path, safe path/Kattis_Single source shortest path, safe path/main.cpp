//
//  main.cpp
//  Kattis_Single source shortest path, safe path
//
//  Created by mcr on 24/10/2020.
//

#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<list>

#include<utility>
#include<tuple>

#include<algorithm>


using namespace std;
using ll=long long ;
const int inf = 0x3f3f3f3f;
//const ll INF = 0x7fffffff;
const int maxn = 1e3+10;
const int M = 2e5+10; //这是什么？
struct node
{
    ll dis;
    int v;
    int _v;
    node() {}
    node(int vv, int d,int _vv)
    {
        v = vv;
        dis = d;
        _v=_vv;
    }
};
inline bool operator < (node a, node b)
{
    if(a.dis == b.dis)
    {
        if(a._v!=b._v)
            return a._v>b._v;
        return a.v > b.v;
    }
    return a.dis > b.dis;
}
int head[maxn];
int cnt;
struct star
{
    int to;
    int w;
    int nxt;
} edge[M];
void addEdge(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
ll dist[maxn][40];
bool vis[maxn][40];
void dijkstra(int s,int V,int k)
{
    priority_queue<node> q;
    memset(dist,inf,sizeof(dist));
    memset(vis,0,sizeof(vis));
    for(int i=0; i<35; i++)
        dist[s][i] = 0;
    q.push(node(s, 0,1));
    ll Min=inf;
    if(s==V)Min=0;
    while(!q.empty())
    {
        node fr = q.top();
        q.pop();
        int v = fr.v;
        ll dis = fr.dis;
        int _v=fr._v;
        vis[v][_v] = 1;
        if(_v>=k||dis>=Min)
            continue;
        for(int i=head[v]; i; i=edge[i].nxt)
        {
            int to = edge[i].to;
            if(!vis[to][_v+1] && dist[to][_v+1] > dis + edge[i].w)
            {
                dist[to][_v+1] = dist[v][_v] + edge[i].w;
                if(to==V)
                    Min=min(Min,dist[to][_v+1]);
                q.push(node(to,  dist[to][_v+1],_v+1));
            }
        }
    }
//    for(int i=0; i<=k; i++)
//        Min=min(Min,dist[v][i]);
    if(Min!=inf)
        printf("%lld\n",Min);
//        cout<<Min<<endl;
    else
        printf("-1\n");
//        cout<<-1<<endl;
    return ;
}
int main()
{
//    ios::sync_with_stdio(false);
//    std::cin.tie(0);
    int t;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        cnt = 1;
        memset(head, 0,sizeof(head));
        int n;
//        cin>>n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            int _N;
            scanf("%d",&_N);
//            cin>>_N;
            for(int j=0; j<_N; j++)
            {
                int v,w;
                scanf("%d%d",&v,&w);
//                cin>>v>>w;
                addEdge(i, v, w);
            }
        }
        int m;
//        cin>>m;
        scanf("%d",&m);
        while(m--)
        {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
//            cin>>u>>v>>k;
            dijkstra(u,v,k);
        }
    }
    return 0;
}
/*
3
4
3 1 2 2 9 3 15
1 2 3
2 0 1 3 7
0
2
0 3 4
0 3 3

4
3 1 2 2 9 3 15
1 2 3
2 0 1 3 7
0
2
0 3 2

*/
