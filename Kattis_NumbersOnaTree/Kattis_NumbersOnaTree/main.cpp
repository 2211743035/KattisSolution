//
//  main.cpp
//  Kattis_NumbersOnaTree
//
//  Created by mcr on 21/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

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
    ll n=0;
    string temp;
    //cin>>n;
    
    getline(cin,temp);
    bool flag=false;
    queue<char> orders;
    for (auto c: temp)
    {
        if (isdigit(c))
        {
            n=n*10+(int)(c-'0');
        }
        else
        {
            orders.push(c);
            flag=true;
        }
    }
    ll totalNum=pow(2,n+1),output=1;

    while(!orders.empty())
    {
        char c=orders.front();
        orders.pop();
        if(c=='R')
        {
            output=output*2+1;
        }
        else if (c=='L')
        {
            output=output*2;
        }
        else continue;
    }
                 cout<<totalNum-output<<endl;
    
    return 0;
}

/*
 总结：
 1.开始写代码前把sample全看一遍
 2.本题考对二叉树child和parent的index关系的理解
 */
