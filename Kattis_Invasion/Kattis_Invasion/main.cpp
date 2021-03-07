//
//  main.cpp
//  Kattis_Invasion
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
    int N,M,A,K;
    do{
    cin>>N>>M>>A>>K;
      
    vector<list<pair<int,int>>> adjLis;
    adjLis.resize(N);
    int T1,T2,D;
    for (int i=0; i<M; i++)
    {
        cin>>T1>>T2>>D;
        T1--;T2--;
        adjLis[T1].push_back({T2,D});
        adjLis[T2].push_back({T1,D});
    }
    vector<int> length;
        length.resize(N,inf);
    int num=0;
    for (int i=0; i<A; i++)
        {
            int a;
            cin>>a;
            a--;
            if (length[a]==inf)num++;
            length[a]=0;
            
        
            priority_queue<pair<int,int>> dijQ;
            dijQ.push({0,a});
            while (!dijQ.empty())
            {
                auto [l,v]=dijQ.top(); dijQ.pop();
                //cout<<v<<" "<<l<<endl;
                if (l>=K||l>length[v])
                {continue;
 
                }
                for (auto c: adjLis[v])
                {
                    
                  //  cout<<length[v]<<" "<<c.first<<" "<<c.second<<" aaa "<<length[c.first]<<endl;
                    if (length[v]+c.second>=K) continue;
                   // cout<<length[v]+c.second<<" "<<length[c.first]<<endl;
                    if (length[v]+c.second<length[c.first])
                    {
                        //cout<<"aaa"<<endl;
                        if (length[c.first]==inf) num++;
                      
                        length[c.first]=length[v]+c.second;
                      //  cout<<c.first<<" "<< length[c.first]<<endl;
                        dijQ.push({length[c.first],c.first});
                    }
                }
            }
            cout<<N-num<<endl;
        }
        cout<<endl;
    } while(!(N==0&&M==0&&A==0&&K==0));
    return 0;
}
/*
 总结：
 1. dijkstra 每次加一个source之前的不变
 2. 当距离>=k时就可以不管
 */
