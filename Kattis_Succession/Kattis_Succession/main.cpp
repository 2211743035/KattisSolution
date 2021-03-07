//
//  main.cpp
//  Kattis_Succession
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
unordered_map<string,list<string>> adjacentLis;
typedef unordered_map<string,ll> sti;
sti degree;
sti blood;
const ll  inf  = 1e18 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    string king;
    cin>>king;

    
    for (int i=0; i<N; i++)
    {
        string p1,p2,c;
        cin>>c>>p1>>p2;
        adjacentLis[p1].push_back(c);
        adjacentLis[p2].push_back(c);
        if (!degree.count(p1))degree[p1]=0;
        if (!degree.count(p2))degree[p2]=0;
        degree[c]=2;
        blood[p1]=blood[p2]=blood[c]=0;
    }
    blood[king]=inf;
    degree[king]=0;
    queue<string> kahnQ;
    for (sti::iterator it=degree.begin(); it!=degree.end(); it++)
    {
        if(it->second==0)
        {
            kahnQ.push(it->first);
            //cout<<it->first<<endl;
        }
    }
    while(!kahnQ.empty())
    {
        string u=kahnQ.front(); kahnQ.pop();
        for (auto c: adjacentLis[u])
        {
            degree[c]--;
            if (blood[c]<blood[u]*0.5+blood[c])
            {
                blood[c]=blood[u]*0.5+blood[c];
            }
            if (degree[c]==0) kahnQ.push(c);
        }
    }
    ll maxBlood=-1;
    string maxName,name;
    
    for (int i=0; i<M; i++)
    {
        cin>>name;
        if (blood.count(name)&& blood[name]>maxBlood)
        {
            maxBlood=blood[name];
            maxName=name;
        }
    }
    cout<<maxName<<endl;
    return 0;
}

/*
1. 注意这道题是toposort,不是sssp
2. 如果没有n<50的限制， 可能会flow out, 考虑用二维矩阵描述血缘
 
 */
