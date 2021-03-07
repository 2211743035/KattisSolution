//
//  main.cpp
//  Kattis_Fun House
//
//  Created by mcr on 7/12/2020.
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
    vector<int> move{1,0,-1,0,0,1,0,-1};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int r,c;
    cin>>r>>c;
    vector<vector<char>> mapS(r,vector<char> (c));
    char tempC;
    int rS,cS;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin>>tempC;
            mapS[i][j]=tempC;
            if (tempC=='*')
            {
                rS=i;cS=j;
                
            }
        }
    }
    int dire;
    int rP=rS, cP=cS;
    if (rS==0)dire=0;
    if (rS==r-1) dire=1;
    if (cS==0) dire=2;
    if (cS=c-1) dire=3;
    while (1)
    {
        if (cS!=cP||rS!=rP) && (0==cP||0==rP||c-1==cP||r-1==rP)
        {
            
        }
    }
    
    return 0;
}
