//
//  main.cpp
//  Kattis_Terraces
//
//  Created by mcr on 19/11/2020.
//


//#pragma GCC optimize(3,"Ofast","inline")
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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    const int iinf = 1e9 + 10;
    //typedef vector<vector<int>> vvi;
    //vvi mapS, possibleM;
    
    vector<int> adjLis={1,0,-1,0,0,1,0,-1};
    int c, r;
    
    cin>>c>>r;
    //mapS.resize(r,vector<int> (c,iinf));
    //possibleM.resize(r,vector<int> (c,1));
    int mapS[r][c];
    //int possibleM[r][c];
    bool visited[r][c];
    for(int i=0; i<r; i++)
    {
        for (int j=0; j<c;j++)
        {
            cin>>mapS[i][j];
            //possibleM[i][j]=1;
            visited[i][j]=0;
        }
    }
    int output=0;

    for(int rX=0; rX<r; rX++)
    {
        for (int cX=0; cX<c;cX++)
        {
            
            if (visited[rX][cX]) continue;
            
                int flag=1;
                queue<pair<int,int>> bfsQ;
                //queue<pair<int,int>> storeQ;
                //queue<int> storeQ;
                bfsQ.push({rX,cX});
                visited[rX][cX]=1;
                //.push({rX,cX});
                int num=0;
                while(!bfsQ.empty())
                {
                   
                    auto [rL,cL]=bfsQ.front(); bfsQ.pop();
                    num++;
              
                    for (int i=0; i<4; i++)
                    {
                        int r_=rL+adjLis[i*2],c_=cL+adjLis[i*2+1];
                        if (r_>=0 && r_<r && c_>=0 && c_<c)
                        {
                            //if (possibleM[r_][c_]==2) continue;
                            if (!visited[r_][c_]&& mapS[r_][c_]==mapS[rL][cL])
                            {
                                
                                bfsQ.push({r_,c_});
                                visited[r_][c_]=1;
                              
                            }
                  
                            else if (mapS[r_][c_]<mapS[rL][cL])
                            {
                         
                                    flag=0;
                                
                            }
                        }
                    }

            }
                if (flag==1)
                {output+=num;
                    //cout<<mapS[rX][cX]<<" ";
                //cout<<num<<endl;
                }
            
        }
    
    }
    cout<<output<<endl;
    return 0;
}
