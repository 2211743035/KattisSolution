//
//  main.cpp
//  Kattis_Saving Princess Peach
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
    int N, Y;
    cin>>N>>Y;
    int obstacle[N];
    for (int i=0; i<N; i++) obstacle[i]=0;
    int wrong=0;
    for (int i=0; i<Y; i++)
    {
        int num;
        cin>>num;
        if (num>=N )
        {
            continue;
        }
        else
        {
            obstacle[num]++;
        }
        
    }
    
    for(int i=0; i<N; i++)
    {
        if (obstacle[i]==0)
        {
        cout<<i<<endl;
            wrong++;
        }
    }
    cout<<"Mario got "<<N-wrong<<" of the dangerous obstacles.\n";
    return 0;
}
