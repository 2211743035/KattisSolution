//
//  main.cpp
//  Kattis_Even Up Solitaire
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
    
    int N;
    cin>>N;
    stack<int> counte;
    int pre, temp;
    cin>>temp;
    counte.push(temp);
    pre=temp;
    for (int i=1; i<N; i++)
    {
        cin>>temp;
        if (counte.empty())
        {
            counte.push(temp);
            continue;
        }
        pre=counte.top();
        if ((temp-pre)&1)
        {
            counte.push(temp);
            continue;
        }
        else
        {
            counte.pop();
        }
    }
    cout<<counte.size()<<"\n";
    return 0;
}
