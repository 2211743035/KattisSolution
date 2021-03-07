//
//  main.cpp
//  Kattis_Grid
//
//  Created by mcr on 16/11/2020.
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

const ll  inf  = 1e18 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mapN(n,vector<int>(m));
    vector<vector<ll>> mapD(n,vector<ll>(m,inf));
    cin.ignore();
    string temp;
    for (int i=0; i<n; i++)
    {
        getline(cin,temp);
        
        for (int j=0; j<m; j++)
        {

            mapN[i][j]=temp[j]-'0';
            //cout<< mapN[i][j]<<" ";
           
        }
        //cout<<endl;
    }
    queue<pair<int,int>>bfsQ;
    bfsQ.push({0,0});
    mapD[0][0]=0;
    while(!bfsQ.empty())
    {
  
        //auto  [x,y]=bfsQ.front();
        int x=bfsQ.front().first;
        int y=bfsQ.front().second;
        //cout<<x<<" "<<y<<endl;
        bfsQ.pop();
        int len=mapN[x][y];
        if (x+len<n && mapD[x][y]+1<mapD[x+len][y])
        {
            //cout<<"x"<<x<<" "<<x+len<<endl;
            mapD[x+len][y]=mapD[x][y]+1;
            bfsQ.push({x+len,y});
        }
        if (x-len>=0 && mapD[x][y]+1<mapD[x-len][y])
        {
            //cout<<"x"<<x<<" "<<x+len<<endl;
            mapD[x-len][y]=mapD[x][y]+1;
            bfsQ.push({x-len,y});
        }
        if (y-len>=0 && mapD[x][y]+1<mapD[x][y-len])
        {
            mapD[x][y-len]=mapD[x][y]+1;
            bfsQ.push({x,y-len});
        }
        if (y+len<m && mapD[x][y]+1<mapD[x][y+len])
        {
            mapD[x][y+len]=mapD[x][y]+1;
            bfsQ.push({x,y+len});
        }
    }
    if (mapD[n-1][m-1]==inf) cout<<-1<<endl;
    else cout<<mapD[n-1][m-1]<<endl;
    
    
    return 0;
}
