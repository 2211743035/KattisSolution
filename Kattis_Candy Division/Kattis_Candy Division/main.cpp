//
//  main.cpp
//  Kattis_Candy Division
//
//  Created by mcr on 26/10/2020.
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll N;
    cin>>N;
    int upperBound=ceil(pow(N, 0.5));
    set<ll> possibles;
    for (int i=1; i<=upperBound; i++)
    {
        if (N%i==0)
        {
            possibles.insert(i-1);
            possibles.insert(N/i-1);
        }
    }
    set<ll>::iterator it=possibles.begin();
    for (;it!=possibles.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}

/*
 总结：
 1. map的iterator和set的iterator
    map<type1, type2>::iterator it;
        it->first; //map的key
        it->second; //map的value
    set<type>::iterator it;
    *it; //set的一个值
 2. 找质因数分解找[1,pow(n,0.5)] 注意右边为闭区间；
 */
