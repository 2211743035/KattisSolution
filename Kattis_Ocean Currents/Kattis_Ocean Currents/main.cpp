 //
//  main.cpp
//  Kattis_Ocean Currents
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
vector<vector<int>> mapS;
vector<pair<int,int>> adjacentLis={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int r,c;
    cin>>r>>c;
    
    mapS.resize(r,vector<int>(c+10));
    for(int i=0; i<r; i++)
    {
        int num; cin>>num;
        for (int j=c-1; j>=0; j--)
        {
            mapS[i][j]=num%10;
            num/=10;
        }
    }
    int t,rs,cs,rd,cd;
    cin>>t;
    while(t--)
    {

        //length.clear();
        vector<vector<int>> length(r+10,vector<int>(c+10, iinf));
        cin>>rs>>cs>>rd>>cd;
        rs--;cs--;cd--;rd--;
        queue<pair<int,int>> bfsQ;
        bfsQ.push({rs,cs});
       // int s=rs*c+cs;
        length[rs][cs]=0;
        while (!bfsQ.empty())
        {
            
            auto[rX,cX]=bfsQ.front(); bfsQ.pop();
           //if (rX==rd&&cX==cd) break;
            //if (length[s][rX*r+c]
            //cout<<rX<<" "<<cX<<endl;
            switch (mapS[rX][cX])
            {
            case 0:
                {
                    if (rX-1>=0&&length[rX-1][cX]>length[rX][cX]){
                        length[rX-1][cX]=length[rX][cX];
                        bfsQ.push({rX-1,cX});
                       
                    }
                    break;
                }
            case 1:
                {
                    if (rX-1>=0&&cX+1<c&&length[rX-1][cX+1]>length[rX][cX])
                    {length[rX-1][cX+1]=length[rX][cX];
                        bfsQ.push({rX-1,cX+1});
                        
                    }
                    break;
                }
            case 2:
                {
                        if (cX+1<c&&length[rX][cX+1]>length[rX][cX])
                        {length[rX][cX+1]=length[rX][cX];
                            bfsQ.push({rX,cX+1});
                        }
                    break;
                }
            case 3:
                {
                        if (rX+1<r&&cX+1<c&&length[rX+1][cX+1]>length[rX][cX])
                        {length[rX+1][cX+1]=length[rX][cX];
                            bfsQ.push({rX+1,cX+1});
                        }
                    break;
                }
            case 4:
                {
                        if (rX+1<r&&length[rX+1][cX]>length[rX][cX])
                        {length[rX+1][cX]=length[rX][cX];
                            bfsQ.push({rX+1,cX});
                        }
                    break;
                }
            case 5:
                {
                            if (rX+1<r&&cX-1>=0&&length[rX+1][cX-1]>length[rX][cX])
                            {length[rX+1][cX-1]=length[rX][cX];
                            bfsQ.push({rX+1,cX-1});
                            }
                    break;
                }
            case 6:
                    {
                                if (cX-1>=0&&length[rX][cX-1]>length[rX][cX])
                                {length[rX][cX-1]=length[rX][cX];
                                    bfsQ.push({rX,cX-1});
                                }
                        break;
                    }
            case 7:
                    {
                                if (rX-1>=0&&cX-1>=0&&length[rX-1][cX-1]>length[rX][cX])
                                {length[rX-1][cX-1]=length[rX][cX];
                                    bfsQ.push({rX-1,cX-1});
                                }
                        break;
                    }
            }
            for (auto [aX,bX]:adjacentLis)
            {
                if (rX+aX>=0&&rX+aX<r&&cX+bX>=0&&cX+bX<c&&length[rX+aX][cX+bX]>length[rX][cX]+1)
                {
                    length[rX+aX][cX+bX]=length[rX][cX]+1;
                    bfsQ.push({rX+aX,cX+bX});
                }
            }
            
        }
        /*
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                cout<<length[i][j];
            }
            cout<<endl;
        }
        */
        cout<<length[rd][cd]<<endl;
        
    }
    
    return 0;
}
