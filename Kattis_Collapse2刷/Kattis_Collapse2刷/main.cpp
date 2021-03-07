//
//  main.cpp
//  Kattis_Collapse2刷
//
//  Created by mcr on 21/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>

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
*/
vector<int> deadOnes;

void bfs(queue<int> & deadLis,vector<vector<pair<int,int>>> influence,int servibility[],int & deadNum)
{
    while(!deadLis.empty())
    {
        queue<int> tempLis;
        while(!deadLis.empty())
        {
            int de=deadLis.front();
            deadLis.pop();
            vector<pair<int,int>> affect=influence[de];
            for (auto c: affect)
            {
                //cout<<c.first<<"  haha"<<deadOnes[c.first]<<endl;
                if (deadOnes[c.first]==0)
                {
                if (servibility[c.first]-c.second>=0)
                {
                    servibility[c.first]-=c.second;
                    //cout<<servibility[c.first]<<"  heihei"<<c.second<<endl;
                    continue;
                }
                else
                {
                    deadOnes[c.first]=1;
                    tempLis.push(c.first);
                    //cout<<c.first<<endl;
                    deadNum++;
                }
                }
            }
        }
        deadLis=tempLis;
        //cout<<deadLis.size()<<endl<<endl;
    }
}

void dfs(int de, queue<int> & deadLis,vector<vector<pair<int,int>>> influence,int servibility[],int & deadNum)
{
    vector<pair<int,int>> affect=influence[de];
    deadOnes[de]=1;
    deadNum++;
    for (auto c: affect)
    {
        if (deadOnes[c.first]==1) continue;
        if (c.second>servibility[c.first])
        {
            dfs(c.first,deadLis,influence,servibility,deadNum);
        }
        else
        {
            servibility[c.first]-=c.second;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    deadOnes.resize(N+10);
    for (int i=0; i<N+10;i++) deadOnes[i]=0;
    int servibility[N+10],deadNum=1;
    
    vector<vector<pair<int,int>>> influence(N+10);
    for (int i=1; i<=N; i++)
    {
        int threshold,influenced, fromWho, howMuch;
        cin>>threshold>>influenced;
        servibility[i]=-1*threshold;
        threshold*=-1;
        for (int j=0; j<influenced; j++)
        {
            cin>>fromWho>>howMuch;
            threshold+=howMuch;
            influence[fromWho].push_back(make_pair(i,howMuch));
            
        }
        servibility[i]=threshold;
    }
    /*
    for (auto c:influence[2])
        cout<<c.first<<" "<<c.second<<endl;
     */
    /*
    for (int i=1; i<=N; i++)
    {
        cout<<servibility[i]<<" ";
    }
     */
    //cout<<endl;
    queue<int> deadLis;
    servibility[1]=-1;
    deadOnes[1]=1;
    deadLis.push(1);
    //bfs(deadLis,influence, servibility,deadNum);
    deadNum=0;
    dfs(1,deadLis,influence,servibility,deadNum);
    cout<<N-deadNum<<endl;
    
    
    return 0;
}

/*
 总结：
 1. 不需回溯的问题，有边界的问题都可以同时用bfs和dfs
 2. bfs: 每次向外延生一层
 3. dfs: 不撞南墙不回头
 */
