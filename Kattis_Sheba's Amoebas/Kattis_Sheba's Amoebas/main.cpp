//
//  main.cpp
//  Kattis_Sheba's Amoebas
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
inline int trans(char a)
{
    if (a=='#') return 1;
    else return 0;
}
int m, n,output=0;
int adjacencyLis[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
//map<int,int> visited;

void dfs (vector<vector<int>>& mapS, int i, int j)
{
    mapS[i][j]=0;
    for (auto c: adjacencyLis)
    {
        int t=i+c[0],s=j+c[1];

        if (t<0||t>=m ||s<0||s>=n || mapS[t][s]==0) continue;
        else
        {
            dfs(mapS, t,s);
        }
    }
}
void bfs(vector<vector<int>>& mapS,queue<pair<int,int>> wedge)
{
    while(!wedge.empty())
    {
        queue<pair<int,int>> wedge2;
        while(!wedge.empty())
        {
        int i=wedge.front().first;
        int j=wedge.front().second;
        mapS[i][j]=0;
        wedge.pop();
        
    for (auto c: adjacencyLis)
    {
        int t=i+c[0],s=j+c[1];
        if (t<0||t>=m||s<0||s>=n) continue;
        else
        {
            if (mapS[t][s]!=0)
            {
            wedge2.push(make_pair(t,s));
            mapS[t][s]=0;
            }
        }
    }
    }
        wedge=wedge2;
        
    }
    return;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
  
    cin>>m>>n;
    cin.ignore();
    vector<vector<int>> mapS(m,vector<int>(n));
    for (int i=0 ;i<m; i++)
    {
        string temp;
        getline(cin,temp);
        for (int j=0; j<n; j++)
        {
            mapS[i][j]=trans(temp[j]);
        }
        
    }
    /*
    for (int k=0; k<m;k++)
    {
        for (int d=0; d<n;d++)
        {
            cout<<mapS[k][d];
        }
        cout<<endl;
    }
     */
    for (int i=0;i<m;i++)
    {
        for (int j=0; j<n; j++)
        {
            if (mapS[i][j]==0) continue;
            else
            {   queue<pair<int,int>> wedge2;
                wedge2.push(make_pair( i,  j));
                //bfs(mapS,wedge2);
                dfs(mapS,i,j);
                output++;
            }
        }
    }
   
    cout<<output<<endl;
    return 0;
}

/*
 总结：
 1.这题可以用dfs或者bfs做
 2.这题的dfs和正常的不同在于只用递归不用回溯
 3.如果需要回溯就需要记父节点？其实也可以不用，因为父节点会被标为visited；
 */
