//
//  main.cpp
//  Kattis_Integer Lists
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
    int N;
    cin>>N;
    while(N--)
    {
    //int p;
    //cin>>p;
    string tempOrder,tempNum;
    queue<char> orders;
    cin>>tempOrder;
    /*
    for (auto c:tempOrder)
    {
        orders.push(c);
    }
     */
    deque<int> numLis;
    int n;
    cin>>n;
    cin.ignore();
    getline(cin, tempNum);
    if (tempNum!="[]")
    {
    tempNum=tempNum.substr(1, tempNum.length()-1);
    //cout<<tempNum<<endl;
    istringstream ss(tempNum);
    string strNum;
    while(getline(ss,strNum,','))
    {
        int num=stoi(strNum);
        numLis.push_back(num);
    }
    }
        int fron=1;
        bool flag=true;
        for (auto c: tempOrder)
        {
            if (c=='R')
            {
                fron=(fron+1)&1;
            }
            else
            {
                if (numLis.empty())
                {
                    cout<<"error\n";
                    flag=false;
                    break;
                }
                else if (fron)
                {
                    numLis.pop_front();
                    n--;
                }
                else
                {numLis.pop_back();
                    n--;
                }
            }
        }
        if (flag)
        {
            cout<<'[';
            
            if (fron==1 && n>0)
            {
                cout<<numLis.at(0);
                for(int i=1; i<n; i++)
                {
                    cout<<","<<numLis.at(i);
                }
              
                
            }
            else if (fron==0 && n>0)
            {
                cout<<numLis.at(n-1);
                for(int i=n-2; i>=0; i--)
                {
                    cout<<","<<numLis.at(i);
                }
            }
            cout<<"]\n";
        }
        
    }
    return 0;
}
