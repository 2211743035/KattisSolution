//
//  main.cpp
//  Kattis_Booking a Room
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
    int r, n;
    cin>>r>>n;
    if (r==n)
    {
        int stupid;
        for (int i=0;i<n;i++)
        {
            cin>>stupid;
        }
        cout<<"too late"<<endl;
        return 0;
    }
    int room[r+10];
    for (int i=1; i<=r;i++)
    {
        room[i]=0;
    }
    for (int i=0 ; i<n; i++)
    {
        int num;
        cin>>num;
        room[num]++;
    }
    for (int i=1; i<=r; i++)
    {
        if (room[i]==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    
    return 0;
}

/*
 总结：
 stupid question, just don't do it
 */
