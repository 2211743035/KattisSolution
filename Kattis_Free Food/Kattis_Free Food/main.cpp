//
//  main.cpp
//  Kattis_Free Food
//
//  Created by mcr on 24/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

#include<math.h>
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
    int N;
    int calendar[366];
    for (int i=0; i<366; i++) calendar[i]=0;
    cin>>N;
    int from, to;
    for (int i=0; i<N; i++)
    {
        cin>>from>>to;
        for (int i=from; i<=to; i++)
        {
            calendar[i]++;
        }
    }
    int output=0;
    for (int i=1;i<366;i++)
    {
        if (calendar[i]>0) output++;
    }
    cout<<output<<endl;
    return 0;
}
