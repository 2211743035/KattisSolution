//
//  main.cpp
//  Kattis_Horror List
//
//  Created by mcr on 17/11/2020.
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
vector<vector<int>> adjacentLis;
vector<int> length;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,H,L;
    cin>>N>>H>>L;
    queue<int>bfsQ;
    adjacentLis.resize(N);
    length.resize(N,10001);
    for (int i=0; i<H; i++)
    {
        int t;
        cin>>t;
        bfsQ.push(t);
        length[t]=0;
    }
    for (int i=0 ;i<L; i++)
    {
        int a, b;
        cin>>a>>b;
        adjacentLis[a].push_back(b);
        adjacentLis[b].push_back(a);
    }
    while(!bfsQ.empty())
    {
        int u=bfsQ.front();bfsQ.pop();
        for (auto c: adjacentLis[u])
        {
            if (length[u]+1<length[c])
            {
                bfsQ.push(c);
                length[c]=length[u]+1;
            }
        }
    }
    int maxPos=-1, maxValue=-1;
    for (int i=0; i<N;i++)
    {
        if (length[i]>maxValue)
        {
            maxPos=i;
            maxValue=length[i];
        }
    }
    cout<<maxPos<<endl;
    return 0;
}
