//
//  main.cpp
//  Kattis_Getting Gold
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
int mapS[60][60],output=0,W,H;
int adjacencyLis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
inline int trans(char c)
{
    if (c=='#') return -1;
    else if (c=='.') return 0;
    else if (c=='T') return -2;
    else if (c=='G') return 1;
    else return -3;
}

void bfs(queue<pair<int,int>> concur)
{
    while(!concur.empty())
    {
        queue<pair<int,int>> tempQueue;
        while(!concur.empty())
        {
            int w1=concur.front().second, h1=concur.front().first;
            concur.pop();
            bool tryOr=true;
            for (auto c: adjacencyLis)
            {
                int w2=w1+c[0],h2=h1+c[1];
                if (w2<0||w2>=W||h2<0||h2>=H || mapS[h2][w2]>-2) continue;
                else
                {
                    tryOr=false;
                }

            }
            if (tryOr)
            {
            for (auto c: adjacencyLis)
            {
                int w2=w1+c[0],h2=h1+c[1];
                if (w2<0||w2>=W||h2<0||h2>=H || mapS[h2][w2]==-1) continue;
                
                
                else
                {
                    if(mapS[h2][w2]==1) output++;
                    tempQueue.push(make_pair(h2,w2));
                    mapS[h2][w2]=-1;
                }
            }
            }
        }
        concur=tempQueue;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int startX,startY;
    cin>>W>>H;
    cin.ignore();
    
    for (int j=0; j<H; j++)
    {
        string temp;
        getline(cin,temp);
        for(int i=0; i<W; i++ )
        {
            int num=trans(temp[i]);
            if (num!=-3) mapS[j][i]=num;
            else
            {
                startX=i;
                startY=j;
                mapS[j][i]=-1;
            }
            
        }
    }
    /*
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            cout<<mapS[i][j];
        }
        cout<<endl;
    }
    */
    
    queue<pair<int,int>> concur;
    concur.push(make_pair(startY, startX));
    
    bfs(concur);
    cout<<output<<endl;
     
    return 0;
     
}

/*
 总结：
 1. 此题和找loop题有异曲同工，相当于找出发点的loop
 2. 最大难点在于track， 每次向外扩展时都要先判断有没有track, 没有再扩展
 3. 此题也可用深度优先做， 因为图较小， 但是每次也得先判断四个方向有没有track再往前走
 */
