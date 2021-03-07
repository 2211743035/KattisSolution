//
//  main.cpp
//  Kattis_ Cracking The Safe Kattis_Cracking The Safe
//
//  Created by mcr on 23/11/2020.
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

vector<vector<int>>adjLis={{0,1,2,3,6},{0,1,2,4,7},{0,1,2 ,5,8},{0,3,4,5,6}, {1,3,4,5,7},{2,3,4,5,8},{0,3,6,7,8},{1,4,6,7,8},{2,5,6,7,8}};
unordered_map<int,int> dis;

inline int hashNum(vector<int> v)
{
    int output=0;
    for (int i=0; i<9; i++)
    {
        output=output*5+v[i];
    }
    return output;
}

inline vector<int> deHash(int h)
{
    vector<int> output(9);
    for (int i=8; i>=0; i--)
    {
        output[i]=h%5;
        h/=5;
        
    }
    return output;
}
inline int search(vector<int> mapS,vector<int> c)
{
    for (int i=0; i<5; i++)
    {
        mapS[c[i]]=(mapS[c[i]]+1)%4;
    }
    int t=hashNum(mapS);
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<int> ini;
    int a;
    for (int i=0; i<9; i++)
    {
        cin>>a;
        ini.push_back(a);
    }
    queue<int> bfsQ;
    int u=hashNum(ini);
    dis[u]=0;
    bfsQ.push(u);
    while (!bfsQ.empty())
    {
        int u=bfsQ.front(); bfsQ.pop();
        vector<int> mapS=deHash(u);
        for (auto c:adjLis)
        {
            int t=search(mapS,c);
            if ((!dis.count(t))||dis[t]>dis[u]+1)
            {
               
                dis[t]=dis[u]+1;
                bfsQ.push(t);

            }
        }
    }
    if (dis.count(0)) cout<<dis[0]<<endl;
    else cout<<-1<<endl;
    return 0;
}

/*
 总结：
 1. bfs
 2. 小图hash保存
 */
