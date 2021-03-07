//
//  main.cpp
//  Kattis_ICPC Tutorial
//
//  Created by mcr on 26/10/2020.
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
    ll m, n, t;
    cin>>m>>n>>t;
    if (t==7)
    {
        if (n>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else if (t==6)
    {
        ll com= ceil((log(n)/log(2)) *n);
        if (com>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else if (t==5)
    {
        ll maxN=ceil(pow(m,0.5));
        if (n>maxN)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else if (pow(n,2)>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else if (t==4)
    {
        ll maxN=ceil(pow(m,0.3333333333333));
        if (n>maxN)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else if (pow(n,3)>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else if (t==3)
    {
        ll maxN=ceil(pow(m,0.25));
        if (n>maxN)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else if (pow(n,4)>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else if (t==2)
    {
        ll maxN=ceil(log(m)/log(2));
        if (n>maxN)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else if (pow(2,n)>m)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        else
        {
            cout<<"AC"<<endl;
            return 0;
        }
    }
    else
    {
        if (n>11)
        {
            cout<<"TLE"<<endl;
            return 0;
        }
        ll prod=1;
        for (ll i=n; i>=1; i--)
        {
            prod*=i;
            if (prod>m)
            {
                cout<<"TLE"<<endl;
                return 0;
            }
        }
        cout<<"AC"<<endl;
        return 0;
    }
    return 0;
}

/*
 总结：
 1. O(n!) n<12
 2. O(2^n)    20<n<26
 3. O(n^4)   100<n<180
 4. O(n^3) n<1000
 5. O(n^2) n<30000
 6. O(nlogn) n<100,000,000
 7. O(n) n<1000,000,000
 8. O(logn) n<10^n
 */
