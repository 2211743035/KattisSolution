//
//  main.cpp
//  Ksttis_Build Dependencies
//
//  Created by mcr on 15/11/2020.
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
typedef vector<string> vs;
unordered_map<string,vs> AL;
unordered_map<string, bool> vis;
vs toposort;

void dfs(string u)
{
    vis[u]=true;
    for (auto &v:AL[u])
        if (vis.find(v)==vis.end())
            dfs(v);
    toposort.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n; cin>>n;cin.get();
    AL.clear();
    while(n--)
    {
        string line;getline(cin,line);
        istringstream iss(line);
        string file; iss>>file;file.pop_back();//string可以直接用pop_back()把最后一个字母删去
        string dep;
        while (iss>>dep) AL[dep].push_back(file);
    }
    string file; getline(cin,file);
    dfs(file);
    for (int  i= (int) toposort.size()-1; i>=0; i--) cout<<toposort[i]<<endl;
    return 0;
}

/*
 总结：
 1. toposort用dfs时采用post order
 2. hash编码用数字和直接用字符串hash是一个grph edge的数量平衡关系
 */
