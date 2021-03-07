//
//  main.cpp
//  Kattis_Widget Tree
//
//  Created by mcr on 31/10/2020.
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



bool flag=false;
bool detecflag=false;
vector<list<int>> adjacentLisDown;
vector<list<int>> adjacentLisUp;
unordered_map<int,int> edgeWeightUp;
vector<int> vertexWeight;
deque<int> bottomLis;
vector<int> can;
vector<int>visited;
deque<int> track_back;

vector<int>bfsvisit;
//vector<int> upperLength;
unordered_set<int> sharedSet;
int N, M;
vector<int> weightDfsDown2;
unordered_set<int> setForDfsDown2;
unordered_map<int,int> applyTimes;
ll downLength=0;
ll upperLength=0;
void dfsDown(int pos)
{
    visited[pos]=2;
    for (auto c: adjacentLisDown[pos])
    {
        if (visited[c]==1) continue;
        else if (visited[c]==2 || can[c]==false)
        {
            for (auto d:track_back)
            {
                can[d]=0;
            }
        }
        else
        {
            track_back.push_back(c);
            dfsDown(c);
            track_back.pop_back();
        }
    }
    visited[pos]=1;
}

/*
void dfsDown2(int pos)
{
    bool dfs2flag=false;
    ll temp=0;
    for (auto c: adjacentLisDown[pos])
    {
        if (visited[c]==0||can[c]==false) continue;
        else
        {
            if (weightDfsDown2[c]==0)
            {
                dfsDown2(c);
                if (weightDfsDown2[c]!=0)
                {
                    temp+=weightDfsDown2[c]*edgeWeightUp[c*(N+1)+pos];
                    dfs2flag=true;
                }
            }
            else
            {
                temp+=weightDfsDown2[c]*edgeWeightUp[c*(N+1)+pos];
                dfs2flag=true;
            }
            
        }
        if (dfs2flag) weightDfsDown2[pos]+=(temp+1);
    }
  
}
*/
void bfsUp()
{
    while(!bottomLis.empty())
    {
        //cout<<1<<endl;
        int t=bottomLis.front();
        bottomLis.pop_front();
        bool outerflag=false;
        
            
        for (auto c: adjacentLisUp[t])
        {
            if (visited[c]==1)
            {
            bool bfsFlag=0;
            int temp=0;
            if (vertexWeight[c]!=-1) continue;
            for (auto d: adjacentLisDown[c])
            {
                if (visited[d]==1)
                {
                if (vertexWeight[d]==-1)
                {
                   // cout<<c<<" "<<d<<endl;
                    bfsFlag=1;
                    break;
                }
                else
                {
                    temp+=(vertexWeight[d])*edgeWeightUp[d*(N+1)+c];
                    //cout<<d<<" "<<c<< " heihei "<<edgeWeightUp[d*(N+1)+c]<<endl;
                }
                }
            }
            if (bfsFlag==1)
            {
                outerflag=true;
                continue;
            }
            else
            {
                vertexWeight[c]=temp+1;
                bottomLis.push_back(c);
                //cout<<c<<" "<<vertexWeight[c]<<endl;
            }
        }
        }
        if (outerflag==true)
        {
            bottomLis.push_back(t);
        }
    }
}

vector<int> dfsvisit;
ll length=1;
ll g=-1;
void dfsUp(int pos)
{
   
    for (auto c: adjacentLisUp[pos])
    {
       // int use=max(nodeFrequent[c],1);
        
       if (visited[c]==1)
        {
       
        //cout<<c<<" wuwu "<<pos<<" "<<edgeWeightUp[pos*(N+1)+c]*use<<endl;
        // edgeSet.insert(pos*(N+1)+c);
            
        if (sharedSet.count(c) )
        {
            dfsvisit[c]=vertexWeight[c];
            continue;
        }
        else if  (g>-1)
        {   g=g*edgeWeightUp[pos*(N+1)+c];
            dfsvisit[c]+=g;
            //cout<<pos<<" "<<c<<" "<<g/max(edgeWeightUp[pos*(N+1)+c],1)<<"*"<<edgeWeightUp[pos*(N+1)+c]<<"="<<dfsvisit[c]<<endl;
            dfsUp(c);
          
            continue;
        }
        else if (dfsvisit[c]==0)
        {
            dfsvisit[c]=(dfsvisit[pos]*edgeWeightUp[pos*(N+1)+c])+1;
            //cout<<pos<<" "<<c<<" "<<dfsvisit[pos]<<"*"<<edgeWeightUp[pos*(N+1)+c]<<"+1="<<dfsvisit[c]<<"!!!"<<endl;
            dfsUp(c);
        }
        else
            {
                g=(dfsvisit[pos]*edgeWeightUp[pos*(N+1)+c]);
                dfsvisit[c]+=g;
                //cout<<pos<<" "<<c<<" "<<dfsvisit[pos]<<"*"<<edgeWeightUp[pos*(N+1)+c]<<"="<<dfsvisit[c]<<"???"<<endl;
                dfsUp(c);
                g=-1;
 
                continue;
            }

    }

}
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>N>>M;//𝑁 (1≤𝑁≤1000) and 𝑀 (1≤𝑀≤109).
    
    can.resize(N, true);
    visited.resize(N,0);
    adjacentLisDown.resize(N+10);
    adjacentLisUp.resize(N+10);
    vertexWeight.resize(N+10,-1);
    for (int i=0; i<N; i++)
    {
        int C;
        cin>>C;
        if (C==0)
        {
            bottomLis.push_back(i);
            vertexWeight[i]=1;
        }
        
        for (int j=0 ;j<C; j++)
        {
            int num;
            cin>>num;
            
            if (edgeWeightUp.count(num*(N+1)+i))
            {
                edgeWeightUp[num*(N+1)+i]++;
                
            }
            else
            {
                edgeWeightUp[num*(N+1)+i]=1;
                adjacentLisUp[num].push_back(i);
                adjacentLisDown[i].push_back(num);
            }
        }
        
    }
    if (bottomLis.size()==0) flag=true;

dfsDown(0);

for (int i=0; i<N; i++)
    {
        if (visited[i]==1)
        {
            int temp=0;
        for (auto c:adjacentLisUp[i])
        {
            if (visited[c]==1)
            {
                temp++;
            }
        }

        }
    }

bfsUp();
    vertexWeight[0]=1;
for (auto c: adjacentLisDown[0])
{
    vertexWeight[0]+=vertexWeight[c];
}

    for (int i=0; i<N; i++)
    {
        if (can[i]&&visited[i]) continue;
        //cout<<i<<" "<<vertexWeight[i]<<endl;
        else vertexWeight[i]=0;
    }
    
    int Q,T;
    cin>>Q>>T;
    int X;
    //cout<<"Q: "<<Q<<" T "<<T<<endl;
    if (T==1)
    {
    if (flag || can[0]==false) cout<<"Invalid"<<endl;
    else
    {cout<<"Valid"<<endl;
        //cout<<Q<<" "<<T<<endl;
    }
    return 0;
    }
    else
    {
    if (flag|| can[0]==false)
    {
     
        cout<<"Invalid"<<endl;
        return 0;
    }
        cout<<vertexWeight[0]<<endl;
    for (int i=0; i<Q; i++)
    {
        cin>>X;
        dfsvisit.clear();
        dfsvisit.resize(N+10,0);
        sharedSet.clear();
        for (int j=0; j<X;j++)
        {
            
            int Y;
            cin>>Y;
            if (visited[Y]==1)
            sharedSet.insert(Y);
            //weightDfsDown2[Y]=vertexWeight[Y];

        }
        dfsvisit.resize(N+10, 0);
        for (auto c: sharedSet)
        {
            
            upperLength=0;
            dfsvisit[c]=vertexWeight[c];
            dfsUp(c);
            downLength=0;

            
        }

        cout<<dfsvisit[0]<<endl;
    }
 
  
    }
    //dfs(0,-1);
    
    return 0;
}
