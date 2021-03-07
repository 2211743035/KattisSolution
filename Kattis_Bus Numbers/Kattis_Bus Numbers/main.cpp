//
//  main.cpp
//  Kattis_Bus Numbers
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
    cin>>N;
    vector<int> seq(N);
    for (int i=0; i<N; i++)
         {
        cin>>seq[i];
        
    }
    sort(seq.begin(),seq.end());
    int i=0;
    
   while(i<N)
    {
        if (seq[i]+2==seq[i+2])
        {
            int start=i;
            while(seq[i]+1==seq[i+1]) i++;
            cout<<seq[start]<<"-"<<seq[i]<<" ";
        }
        else cout<<seq[i]<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}
