//
//  main.cpp
//  Kattis_Awkward Party
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
    int n;
    cin>>n;
    unordered_map<int,int> pos; // language, sitPos
    int minimum=1e9+10;
    for (int i=0;i<n; i++)
    {
        int lang;
        cin>>lang;
        if(pos.count(lang))
        {
            int dis=i-pos[lang];
            minimum=min(dis,minimum);
            pos[lang]=i;
        }
        else
        {
            pos[lang]=i;
        }
    }
    if (minimum<1e9+10)
    cout<<minimum<<endl;
    else
    cout<<n<<endl;
    return 0;
}

/*
 总结：
 只有相邻位置matter
 */
