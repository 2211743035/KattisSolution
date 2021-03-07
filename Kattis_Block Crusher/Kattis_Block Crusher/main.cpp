//
//  main.cpp
//  Kattis_Block Crusher
//
//  Created by mcr on 20/11/2020.
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int h,w;
    vector<int> adjLis={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
    do{
        cin>>h>>w;
        if (h==0&&w==0) break;
        vector<vector<int>> mapS(h,vector<int>(w));
        vector<vector<int>> length(h,vector<int> (w,10000));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dijQ;
        vector<int> parent;
        parent.resize((h)*(w));
       // cout<<h<<" "<<w<<endl;
        for (int i=0; i<h; i++)
        {
            //cout<<i<<endl;
            for (int j=0; j<w; j++)
            {
                char t;
                cin>>t;
                int a=t-'0';
                mapS[i][j]=a;
                //cout<<mapS[i][j];
                //cout<<i<<" "<<j <<endl;;
                
            }
         
        }
       // cout<<1<<endl;
        for (int j=0; j<w; j++)
        {
        
              length[0][j]=mapS[0][j];
              dijQ.push({mapS[0][j],j});
             // cout<<mapS[0][j];
            
        }
       // cout<<1<<endl;
        while(!dijQ.empty())
        {
            auto [l,v]=dijQ.top(); dijQ.pop();
         
            int r_=v/w,c_=v%w;
            //cout<<r_<<" "<<c_<<endl;
            if (l>length[r_][c_]) continue;
            for (int i=0; i<8; i++)
            {
                int rT=r_+adjLis[i*2];
                int cT=c_+adjLis[i*2+1];
                if (rT>=0 && rT<h && cT>=0 &&cT<w&&length[r_][c_]+mapS[rT][cT]<length[rT][cT])
                {
                    length[rT][cT]=length[r_][c_]+mapS[rT][cT];
                    dijQ.push({length[rT][cT],rT*w+cT});
                    parent[rT*w+cT]=v;
                  //  cout<<"prent"<<v/w<<" "<<v%w<<" child:"<<rT<<" "<<cT<<endl;
                }
            }
        }
        int minDest,minNum=100000;
        for (int i=0; i<w; i++)
        {
            if (length[h-1][i]<minNum)
            {
            minDest=i;
            minNum=length[h-1][i];
            }
        }
        int ct=minDest,rt=h-1;
        while(rt!=0)
        {
            mapS[rt][ct]=-1;
            int p=parent[rt*w+ct];
           // cout<<rt<<" "<<ct<<" aaa"<<endl;
            rt=p/w;
            ct=p%w;
           // cout<<rt<<" "<<ct<<" hhh"<<endl;
        }
        mapS[rt][ct]=-1;
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
            {
                if ( mapS[i][j]==-1)
                {
                    cout<<" ";
                }
                else
                {
                    cout<<mapS[i][j];
                }
                    
            }
            cout<<endl;
        }
        cout<<endl;
        
    }while(h!=0&&w!=0);
    return 0;
}
