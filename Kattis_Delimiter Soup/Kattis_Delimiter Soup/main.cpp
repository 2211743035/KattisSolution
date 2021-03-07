//
//  main.cpp
//  Kattis_Delimiter Soup
//
//  Created by mcr on 20/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

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
    int n;
    cin>>n;
    stack<char> openP;
    cin.ignore();
    string temp;
    getline(cin, temp);
    char c;
    
    for (int i=0;i<n; i++)
    {
        c=temp[i];
        if (c==' ') continue;
        else if(c=='(') openP.push(')');
        
        else if (c=='[') openP.push(']');
        else if (c=='{') openP.push('}');
        else
        {
            if (openP.empty() || openP.top()!=c)
            {
                cout<<c<<" "<<i<<"\n";
                return 0;
            }
            else
            {
                openP.pop();
            }
        }
        
    }
    cout<<"ok so far\n";
    return 0;
}
