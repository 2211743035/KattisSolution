//
//  main.cpp
//  Kattis_Esej
//
//  Created by mcr on 25/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

#include<unordered_set>
# include <string.h>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<list>

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
    int A,B;
    cin>>A>>B;
    unordered_set <int> words;
    for (int i=0; i<B; i++)
    {
        int t=i;
        while(t/26)
        {
            cout<<(char)('a'+t%26);
            t/=26;
        }
        cout<<(char)('a'+t%26)<<" ";
    }
    //unordered_set <string> stringSet ;
    return 0;
}
