//
//  main.cpp
//  Kattis_Missing Gnomes
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> hashRem(n+10);
    queue<int> remainLis, finalLis,deletedLis;
    for (int i=0; i<n+10; i++ ) hashRem[i]=0;
    int num;
    for (int i=0; i<m; i++)
    {
        cin>>num;
        remainLis.push(num);
        hashRem[num]=1;
    }
    //int t=0;
    
    for (int i=1; i<=n; i++)
    {
        if (hashRem[i]==0)
        {
            deletedLis.push(i);
        }
    }
    for  (int t=1; t<=n; t++)
    {
        if (!remainLis.empty()&&t==remainLis.front() )
        {
            finalLis.push(remainLis.front());
            remainLis.pop();
            continue;
        }
        if (!deletedLis.empty()&&!remainLis.empty())
        {
        if (deletedLis.front()>remainLis.front())
        {
            finalLis.push(remainLis.front());
            remainLis.pop();
            continue;
        }
        else
        {
            finalLis.push(deletedLis.front());
            deletedLis.pop();
            continue;
        }
        }
        else if (!remainLis.empty())
        {
            finalLis.push(remainLis.front());
            remainLis.pop();
            continue;
        }
        else
        {
            finalLis.push(deletedLis.front());
            deletedLis.pop();
            continue;
        }
        /*
        for (int i=1;i<=n;i++)
        {
            if (hashRem[i]==0)
            {
                if (!remainLis.empty()&& i>remainLis.front())
                {
                    finalLis.push(remainLis.front());
                    remainLis.pop();
                    continue;
                
                }
                else
                {
                    finalLis.push(i);
                    hashRem[i]=1;
                    continue;
                }
            }
        }
         */
    }
    
    while(!remainLis.empty())
    {
        finalLis.push(remainLis.front());
        remainLis.pop();
    }
    while(!deletedLis.empty())
    {
        finalLis.push(deletedLis.front());
        deletedLis.pop();
    }
    while(!finalLis.empty())
    {
        cout<<finalLis.front()<<endl;
        finalLis.pop();
    }
    return 0;
}
