//
//  main.cpp
//  Kattis_Grandpa Bernie
//
//  Created by mcr on 25/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    unordered_map<string,vector<int>> calendar;
    unordered_map<string,bool> countries;
    int N;
    cin>>N;
    for (int i=0; i<N; i++)
    {
        string place;
        int year;
        cin>>place>>year;
        calendar[place].push_back(year);
        countries[place]=true;
        //countries.insert(place);
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        string place;
        int times;
        cin>>place>>times;
        if (countries[place])
        {
            sort(calendar[place].begin(),calendar[place].end());
            countries[place]=false;
        }
        cout<<calendar[place][times-1]<<endl;
    }
    return 0;
}
