//
//  main.cpp
//  Kattis_Lost in translation_true
//
//  Created by mcr on 12/11/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>                                                               # include <string.h>
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
unordered_map<string,int> encoder;
vector<string> decoder;
vector<list<int>>adjacentLis;
vector<vector<int>>adjacentMatrix;
vector<vector<int>> visit;
vector<int> shortestPos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    decoder.resize(n+1);
    visit.resize(n+10,vector<int>(1000,1000000));
    adjacentMatrix.resize(n+10,vector<int>(n+10, 100000));
    adjacentLis.resize(n+10);
    shortestPos.resize(n+10,1000000);
    string lan;
    encoder["English"]=0;
    decoder[0]="English";
    for (int i=1; i<=n; i++)
    {
        cin>>lan;
        encoder[lan]=i;
        decoder[i]=lan;
    }
    string lan1,lan2;
    int weight;
    for (int i=0; i<m; i++)
    {
        cin>>lan1>>lan2>>weight;
        adjacentMatrix[encoder[lan1]][encoder[lan2]]=min(weight,adjacentMatrix[encoder[lan1]][encoder[lan2]]);
        adjacentMatrix[encoder[lan2]][encoder[lan1]]=min(weight,adjacentMatrix[encoder[lan2]][encoder[lan1]]);
        adjacentLis[encoder[lan2]].push_back(encoder[lan1]);
        adjacentLis[encoder[lan1]].push_back(encoder[lan2]);
    }
    
 
    queue<int> runQ;
    ll totalLen=0;
    runQ.push(0);
    int visitNum=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> selectEdge;
    //queue<pair<int,int>> selectEdge;
    selectEdge.push(make_pair(0,0));
    visit[0][0]=0;
    
    int length=0;
    while(!selectEdge.empty())
    {
        queue<pair<int,int>> tempQ;
        while(!selectEdge.empty())
        {
        int u=selectEdge.top().second;
        if (length>shortestPos[u])
        {
            selectEdge.pop();
            continue;
        }
        
        totalLen+=selectEdge.top().first;
        //cout<<u<<" "<<totalLen<<endl;
        selectEdge.pop();
        visit[length][u]=totalLen;
        visitNum++;
        if (visitNum>=n+1) break;
        for (auto c: adjacentLis[u] )
        {
            if(length<=visit[c].first)
            {
                
                //cout<<c.first<<endl;
                
                selectEdge.push(make_pair(adjacentMatrix[c][u],c));
                
            }
        }
        }
    }
    if (visitNum<n+1) cout<<"Impossible"<<endl;
    else cout<<totalLen<<endl;
    return 0;
}
//mst
