//
//  main.cpp
//  Kattis_Texas Summers
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

const ll  inf  = 1e9 + 10;
/*
struct Point
{
    int x,y;
    Point(int x_,int y_)
    {
        this->x=x_;
        this->y=y_;
    }
    bool operator < (const Point& a) const
        {
            if (this->x == a.x)  return this->y < a.y;
            return this->x < a.x;
        }
};
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<pair<int,int>> points;
    int n;
    cin>>n;
    int a, b;
   // unordered_map<Point,int> toInde;
    unordered_map<int,pair<int,int>> toPoint;
    for(int i=0; i<n; i++)
    {
  
        cin>>a>>b;
        points.push_back({a,b});
        //toInde[Point(a,b)]=i;
        toPoint[i]={a,b};
    }
    cin>>a>>b;
    pair<int,int> start={a,b};
    cin>>a>>b;
    pair<int,int> des={a,b};
   // cout<<a<<" "<<endl;
    vector<int> Usefulpoints;
    ll lengthSD=pow((start.first-des.first),2)+pow((start.second-des.second),2);
    unordered_map<int, ll> length;
    unordered_map<int,int> parent;
    for (int i=0; i<n; i++)
    {
        auto c=points[i];
        if (pow((c.first-des.first),2)+pow((c.second-des.second),2)<=lengthSD)
        {
            Usefulpoints.push_back(i);
            //Point m(c.first,c.second);
            length[i]=inf;
        }
    }
    //Point dest=Point(des.first,des.second),star=Point(start.first,start.second);
    length[n+1]=0;
    length[n+2]=inf;
    toPoint[n+1]=start;
    toPoint[n+2]=des;
    Usefulpoints.push_back(n+1);
    Usefulpoints.push_back(n+2);
    //cout<<n+1<<" "<<n+2<<endl;
    
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> dijQ;
    dijQ.push({0, n+1});
    while(!dijQ.empty())
    {
        ll l =dijQ.top().first;
        int j=dijQ.top().second;
        dijQ.pop();
        if (l>length[j]) continue;
        for (auto i: Usefulpoints)
        {
            //cout<<i<<" hh"<<endl;
            auto c=toPoint[i];
            auto p=toPoint[j];
            if (c.first==p.first&&c.second==p.second) continue;
            else
            {
                ll lengthcP=pow(c.first-p.first,2)+pow(c.second-p.second,2);
               
                if (length[j]+lengthcP<length[i])
                {
                    length[i]=length[j]+lengthcP;
                    dijQ.push({length[i],i});
                    parent[i]=j;
                    //cout<<i<<" "<<parent[i]<<" "<<length[i]<<endl;
                }
            }
        }
    }
    
    if (parent[n+2]==n+1)
    {
        cout<<'-'<<endl;
        return 0;
    }
    else
    {
        int t=n+2;
        stack<int> st;
        while (parent[t]!=n+1)
        {
            //cout<<t<<endl;
            t=parent[t];
            st.push(t);
        }
        while (!st.empty())
        {
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    return 0;
}
