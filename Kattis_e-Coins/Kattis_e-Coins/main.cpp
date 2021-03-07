//
//  main.cpp
//  Kattis_e-Coins
//
//  Created by mcr on 21/11/2020.
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
int inf=1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    while (n--)
    {
        int m,S;
        cin>>m>>S;
        
        vector<pair<int,int>>edgeLis;
        vector<vector<int>> length(S+10,vector<int>(S+10,inf));
        for (int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            a*=-1; b*=-1;
           // cout<<"rc: "<<b<<" "<<a<<endl;
            edgeLis.push_back({b,a});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dijQ;
        for (int i=0; i<=S; i++)
        {
            if (ceil(pow(S*S-i*i,0.5))==floor(pow(S*S-i*i,0.5)))
            {
              //  cout<<i<<" "<<ceil(pow(S*S-i*i,0.5))<<endl;
                dijQ.push({0,i*(S+1)+ceil(pow(S*S-i*i,0.5))});
                length[i][ceil(pow(S*S-i*i,0.5))]=0;
            }
            //cout<<i<<endl;
        }
        //cout<<1<<endl;
        while (!dijQ.empty())
        {
            auto [l,v]=dijQ.top(); dijQ.pop();
            int rS=v/(S+1), cS=v%(S+1);
            if (l>length[rS][cS]) continue;
            for (auto c:edgeLis)
            {
                if (!(rS+c.first>=0&&rS+c.first<=S&&cS+c.second>=0&&cS+c.second<=S)) continue;
                if (length[rS][cS]+1<length[rS+c.first][cS+c.second])
                {
                    length[rS+c.first][cS+c.second]=length[rS][cS]+1;
                    dijQ.push({ length[rS+c.first][cS+c.second],(rS+c.first)*(S+1)+cS+c.second});
                }
            }
            
        }
        if (length[0][0]==inf) cout<<"not possible\n";
        else cout<<length[0][0]<<endl;
        cin.ignore();
    }
    return 0;
}

/*
 总结：
 1.整数能达到要求勾股定理的点是有限的
 2. 最多300*300个点
 3. 转化成bfs
 */
