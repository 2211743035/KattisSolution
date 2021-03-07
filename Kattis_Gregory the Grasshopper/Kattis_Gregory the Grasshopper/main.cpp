//
//  main.cpp
//  Kattis_Gregory the Grasshopper
//
//  Created by mcr on 18/11/2020.
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
const int iinf = 1e9 + 10;
vector<pair<int,int>> adjacentLis={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
vector<vector<int>> mapS;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int R,C,Gr,Gc,Lr,Lc;
    while(cin>>R)
    {
        //if (cin.eof()) break;
        mapS.clear();
        queue<pair<int,int>> bfsQ;
        cin>>C>>Gr>>Gc>>Lr>>Lc;
        mapS.resize(R,vector<int>(C,iinf));
        mapS[Gr-1][Gc-1]=0;
        bfsQ.push({Gr-1,Gc-1});
        while(!bfsQ.empty())
        {
            auto [x,y]=bfsQ.front();bfsQ.pop();
            for (auto [xC,yC]: adjacentLis)
            {
                if (x+xC>=0&&x+xC<R && y+yC>= 0 && y+yC<C && mapS[x][y]+1<mapS[x+xC][y+yC])
                {
                    
                    mapS[x+xC][y+yC]=mapS[x][y]+1;
                    bfsQ.push({x+xC,y+yC});
                    if (x+xC==Lr-1&&y+yC==Lc-1)
                    {
                        //bfsQ.clear();
                        break;
                    }
                }
            }
        }
        if (mapS[Lr-1][Lc-1]==iinf) cout<<"impossible"<<endl;
        else cout<<mapS[Lr-1][Lc-1]<<endl;
    }
    return 0;
}
