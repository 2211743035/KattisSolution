//
//  main.cpp
//  Kattis_Faulty Robot
//
//  Created by mcr on 27/10/2020.
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
*/
unordered_set<int> stopPoint;
unordered_map<int,int> forcePath;
vector<list<int>> adjacentLis;
int visited[1000+10];
void sudo_bfs()
{
    queue<int> bfsQ;
    bfsQ.push(1);
    visited[1]=1;
    int t=1;
    bool loopFlag=false;
    
    while(forcePath.count(t))
    {
        if (visited[forcePath[t]])
        {
            loopFlag=true;
            break;
        }
        else
        {
            
            t=forcePath[t];
            bfsQ.push(t);
            visited[t]=1;
            
        }
    }
    if (!loopFlag)
    {stopPoint.insert(t);
        //cout<<t<<endl;
    }
    while(!bfsQ.empty())
    {
        int p=bfsQ.front();
        bfsQ.pop();
        
        for (auto t:adjacentLis[p])
        {
        loopFlag=false;
        while(forcePath.count(t))
        {
            if (visited[forcePath[t]])
            {
                loopFlag=true;
                break;
            }
            else
            {
                t=forcePath[t];
                visited[t]=1;
            }
        }
        if (!loopFlag)
        {stopPoint.insert(t);
            //cout<<t<<endl;
        }
        }
        
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m, a, b;
    cin>>n>>m; //1≤𝑛≤1*e3, 0≤𝑚≤1*e4
    adjacentLis.resize(n+10);
    for (int i=0; i<m; i++)
    {
        cin>>a>>b;
        
        if (a>0)
        {
            adjacentLis[a].push_back(b);
            visited[a]=0;
            visited[b]=0;
        }
        else
        {
            forcePath[-1*a]=b;
            visited[-1*a]=0;
            visited[b]=0;
        }
    }
    sudo_bfs();
    cout<<stopPoint.size()<<endl;
    return 0;
}

/*
 总结：
 1. 变种bfs/dfs：总之只在既定路线外走一步
 2. 做adjacentLis时一般比总边+10
 3. 注意flag的边界
 */
