//
//  main.cpp
//  Kattis_Fire
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
inline int change_around(vector<vector<char>> & mapS,int w,int h, int currw,int currh, char sta)
{
    if (currw-1>0&&mapS[h][currw-1]!='*'&&mapS[h][currw-1]!='#')
    {
        mapS[h][currw-1]=sta;
        
    }
    if (currh-1>0) mapS[h-1][currw]=sta;
    
}
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int w,h;
        cin>>w>>h;
        vector<vector<char>> mapS(h,vector<char>(w));
        vector<pair<int,int>> exit;
        queue<pair<int,int>> peopleQ,fireQ;
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {
                char c;
                cin>>c;
                mapS[i][j]=c;
                if (c=='*')
                {
                    fireQ.push({i,j});
                }
                else if (c=='@')
                {
                    peopleQ.push({i,j});
                }
                else if(c=='.' && (i==0||i==h-1||j==0||j==w-1))
                {
                    exit.emplace_back(i,j);
                }
                
            }
        }
        int curr=1;
        bool flag=false;
        while(!peopleQ.empty()&&!flag)
        {
            
            queue<pair<int,int>> tempFire;
            while(!fireQ.empty())
            {
            
                auto[hL,wL]=fireQ.front();fireQ.pop();
                if (wL-1>=0&&mapS[hL][wL-1]!='*'&&mapS[hL][wL-1]!='#')
                {
                    mapS[hL][wL-1]='*';
                    tempFire.push({hL,wL-1});
                }
                if (hL-1>=0&&mapS[hL-1][wL]!='*'&&mapS[hL-1][wL]!='#')
                {
                    mapS[hL-1][wL]='*';
                    tempFire.push({hL-1,wL});
                }
                if (wL+1<w&&mapS[hL][wL+1]!='*'&&mapS[hL][wL+1]!='#')
                {
                    mapS[hL][wL+1]='*';
                    tempFire.push({hL,wL+1});
                }
                if (hL+1<h&&mapS[hL+1][wL]!='*'&&mapS[hL+1][wL]!='#')
                {
                    mapS[hL+1][wL]='*';
                    tempFire.push({hL+1,wL});
                }
            }
            fireQ=tempFire;
            queue<pair<int,int>> tempPeople;
            while(!peopleQ.empty())
            {
                auto[hL,wL]=peopleQ.front();peopleQ.pop();
                //cout<<hL<<" "<<wL<<endl;
                if (hL==0||wL==0||hL==h-1||wL==w-1)
                {
                    cout<<curr<<endl;
                    flag=true;
                    break;
                }
                mapS[hL][wL]='#';
                if (wL-1>=0&&mapS[hL][wL-1]!='*'&&mapS[hL][wL-1]!='#')
                {
                    
                    mapS[hL][wL-1]='@';
                    tempPeople.push({hL,wL-1});
                }
                if (hL-1>=0&&mapS[hL-1][wL]!='*'&&mapS[hL-1][wL]!='#')
                {
                    mapS[hL-1][wL]='@';
                    tempPeople.push({hL-1,wL});
                }
                if (wL+1<w&&mapS[hL][wL+1]!='*'&&mapS[hL][wL+1]!='#')
                {
                    mapS[hL][wL+1]='@';
                    tempPeople.push({hL,wL+1});
                }
                if (hL+1<h&&mapS[hL+1][wL]!='*'&&mapS[hL+1][wL]!='#')
                {
                    mapS[hL+1][wL]='@';
                    tempPeople.push({hL+1,wL});
                }
            }
            peopleQ=tempPeople;
            curr++;

            
        }
        if (!flag) cout<<"IMPOSSIBLE"<<endl;
        
    }
    return 0;
}
