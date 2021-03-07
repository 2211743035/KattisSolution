//
//  main.cpp
//  Kattis_Pairing Socks
//
//  Created by mcr on 20/10/2020.
//

#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

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
    int n,temp,output=0;
    cin>>n;
    queue<int> initialPile;
    stack<int> auxiliaryPile;
    
    for (int i=0; i<2*n; i++)
    {
        cin>>temp;
        initialPile.push(temp);
    }
    while (!initialPile.empty())
    {
        if (auxiliaryPile.empty())
        {
            auxiliaryPile.push(initialPile.front());
            initialPile.pop();
            output++;
            continue;
        }
        
        if (initialPile.front() == auxiliaryPile.top())
        {
            initialPile.pop();
            auxiliaryPile.pop();
            output++;
            continue;
        }
        else
        {
            auxiliaryPile.push(initialPile.front());
            initialPile.pop();
            output++;
            continue;
        }
    }
    
    if (!auxiliaryPile.empty())
    {
        cout<<"impossible\n";
    }
    else
    {
        cout<<output<<endl;
    }
    return 0;
}
