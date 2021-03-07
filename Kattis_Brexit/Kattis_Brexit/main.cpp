//
//  main.cpp
//  Kattis_Brexit
//
//  Created by mcr on 11/11/2020.
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
int C,P,X,L;
vector<list<int>> adjacentLis;
vector<int> initialRank;
queue<int> topLis;
vector<int> finalRank;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>C>>P>>X>>L;
    adjacentLis.resize(C+10);
    finalRank.resize(C+10,0);
    initialRank.resize(C+10,0);
    int a,b;
    for (int i=0 ; i<P; i++)
    {
        cin>>a>>b;
        adjacentLis[a].push_back(b);
        adjacentLis[b].push_back(a);
        initialRank[a]++;
        initialRank[b]++;
    }
    topLis.push(L);
    finalRank[L]=-1;
    while(!topLis.empty())
    {
        int u=topLis.front();
        topLis.pop();
        for (auto c: adjacentLis[u])
        {
            if (finalRank[c]!=-1)
            {

             finalRank[c]++;
                //cout<<c<<" "<<finalRank[c]<<" "<<initialRank[c]<<endl;
             if (finalRank[c]*2>=initialRank[c])
            {
                finalRank[c]=-1;
                topLis.push(c);
                if (c==X)
                {
                    cout<<"leave"<<endl;
                    return 0;
                }
            }
            
            }
        }
    }
    if (finalRank[X]!=-1) cout<<"stay"<<endl;
    else  cout<<"leave"<<endl;
    return 0;
}

