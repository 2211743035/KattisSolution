//
//  main.cpp
//  Kattis_Single source shortest path, time table
//
//  Created by mcr on 20/11/2020.
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

const ll  inf  = 1e9 + 10;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m,q,s;
    do
    {
    vector<vector<int>> edgLis;
    vector<list<vector<int>>> adjLis;
    vector<ll> length;
    cin>>n>>m>>q>>s;
    //adjLis.resize(n);
    length.resize(n+10,inf);
    adjLis.resize(n+10);
    int u,v,t0,P,d;
    
    for (int i=0; i<m; i++)
    {
        cin>>u>>v>>t0>>P>>d;
        edgLis.push_back(vector<int>{u,v,t0,P,d});
        adjLis[u].push_back(vector<int>{u,v,t0,P,d});
    }
        
    length[s]=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> dijQ;
        int times=0;
        dijQ.push({0,s});
    //for (int i=0; i<n; i++)
    while(!dijQ.empty())
    {
        times++;
        //bool flag=true;
        auto [lenV,v] =dijQ.top(); dijQ.pop();
        if (lenV>length[v]) continue;
        
        for (auto c : adjLis[v])
        {
            //if (length[c[0]]==inf ) continue;
            if (c[3]==0 && length[c[0]]!=c[2])
            {
                if (length[c[0]]<=c[2])
                {
                    int startTime=c[2];
                    //cout<<c[0]<<" "<<c[1]<<" "<<startTime<<endl;
                    if (startTime+c[4]<length[c[1]])
                    {
                       // flag=false;
                        length[c[1]]=startTime+c[4];
                        dijQ.push({length[c[1]],c[1]});
                    }
                }
            }
            else
            {
                int startTime=c[2];
                while(startTime<length[c[0]]) startTime+=c[3];
                //int startTime=ceil((length[c[0]]-c[2])/c[3])*c[3]+c[2];
                //cout<<c[0]<<" "<<c[1]<<" "<<startTime<<endl;
                if (startTime+c[4]<length[c[1]])
                {
                    //flag=false;
                    length[c[1]]=startTime+c[4];
                    dijQ.push({length[c[1]],c[1]});
                }
            }
        }
        /*
        if (flag)
        {   //cout<<"times "<<times<<endl;
            break;
        }
         */
    }
    for (int i=0; i<q; i++)
    {
        int que;
        cin>>que;
        if (length[que]!=inf) cout<<length[que]<<endl;
        else cout<<"Impossible"<<endl;
    }
    }while(!(n==0&& m==0&&q==0&&s==0));
    return 0;
}

/*
 测试：
 1. bellman ford通过不了
 2. dijstra可以
 3. bellman ford优化：
    a. 没relax就停止
    b. 开头length为初始inf的continue
 4. dijstra用小顶堆，k=length在前
 */
