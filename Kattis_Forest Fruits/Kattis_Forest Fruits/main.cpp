//
//  main.cpp
//  Kattis_Forest Fruits
//
//  Created by mcr on 24/10/2020.
//


//#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

#include<string.h>
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

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
const ll  inf  = 1e18 + 10;

/*
const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;
*/

ll visited_fruit=0;
ll  minimum=-1;
ll maxi=-1;
ll hasFruit[20010];



void Dijkstra(ll startPos, ll n, vector<list<pair<ll,ll>>> adjacentLis,vector<bool> unvisited,vector<ll> &dis)
{
    fill(dis.begin(),dis.end(),inf);
    //fill(unvisited.begin(),unvisited.end(),true);
    dis[startPos]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push(make_pair(0,startPos));
    while(!q.empty())
    {
        
        ll u=q.top().second;
        q.pop();
        unvisited[u]=false;
        if (!adjacentLis[u].empty())
        {
        for (auto c: adjacentLis[u])
        {
            ll v=c.first;
            //cout<<u<<" "<<v<<" "<<dis[u]+c.second<<" "<<dis[v]<<" "<<unvisited[v]<<endl;
            if (unvisited[v] && dis[v]>dis[u]+c.second)
            {
                dis[v]=dis[u]+c.second;
                q.push(make_pair(dis[v],v));
                //cout<<dis[v]<<endl;
            }
           
        }
        }
       //cout<<"???"<<endl;
        

}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll V,E,C,K,M;
    cin>>V>>E>>C>>K>>M;
    K=min(M,K);
    //vector<ll> hasFruit(V+10,0);
    memset(hasFruit,0,sizeof(hasFruit));
    vector<list<pair<ll,ll>>> adjacentLis(V+10);
    //vector<list<pair<int,int>>> back_adjacentLis(V+10);

    for (int i=0; i<E; i++)
    {
        ll u,v, w;
        cin>>u>>v>>w;
        adjacentLis[u].push_back(make_pair(v,w));
        adjacentLis[v].push_back(make_pair(u,w));
       //back_adjacentLis[v].push_back(make_pair(u,w));
    }
    
    for (int i=0; i<C; i++)
    {
        ll fruit;
        cin>>fruit;
        hasFruit[fruit]=1;
    }
    
    if (K>C)
    {
        cout<<-1<<endl;
        return 0;
    }
    // Dijkstra(int startPos, int n, vector<list<pair<int,int>>> adjacentLis,vector<bool> unvisited,vector<ll> &dis)
    else
    {
        vector<bool> unvisited(V+10, true);
        
        vector<ll> dis(V+10,inf);
    
        Dijkstra(1, V, adjacentLis, unvisited, dis);
        vector<ll> distances(V);
        for (int i=1; i<=V; i++)
        {
            //cout<<i<<" "<<dis[i]<<endl;
            if (dis[i]<inf && hasFruit[i])
            {
                
                distances[visited_fruit]=dis[i];
                //cout<<dis[i]<<" wuwu "<<i<<" "<<distances[visited_fruit]<<endl;
                visited_fruit++;
            }

        }
        
        if (visited_fruit<K)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            sort(distances.begin(),distances.begin()+visited_fruit);
            //for (int i=0; i<visited_fruit; i++) cout<<i<<" "<<distances[i]<<"haha"<<endl;
            minimum=distances[(int)K-1];
            cout<<minimum*2<<endl;
            return 0;
        }
    }
    return 0;
}

/*
 The forest consists of 𝑉 clearings and 𝐸 trails.
 there are 𝐶 clearings containing exactly one batch of growing fruits
 will take 𝐾 days to grow before it is ready to be picked again. (A fruit picked on day 𝑋 is ready to be picked again on day 𝑋+𝐾
 
 The first line of the input contains 5 integers 𝑉 (1≤𝑉≤20000) 𝐸 (1≤𝐸≤100000) 𝐶 (1≤𝐶≤𝑉) 𝐾 (1≤𝐾≤2000000000) and 𝑀 (1≤𝑀≤2000000000).
 𝑢𝑖𝑣𝑖𝑤𝑖 (1≤𝑢𝑖,𝑣𝑖≤𝑉, 1≤𝑤𝑖≤1000000) describing a trail that directly connects clearing 𝑢 to clearing 𝑣 directly with a length of 𝑤 unit distance.
 
 The last line of the input contains 𝐶 distinct space separated integers 𝑓1 to 𝑓𝐶 (1≤𝑓≤𝑉), the clearings where fruits grow.
 
 There are at most one trail directly connecting any two clearings, and no trail connects a clearing to itself.
 
 what is the minimum distance you have to walk per day in order to be able to gather at least one batch of fruits and return to your cottage every day?
 
 
 
 
 */
