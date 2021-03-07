//
//  main.cpp
//  Kattis_Game of Throwns
//
//  Created by mcr on 20/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

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

inline int strToNum(string n)
{
    int output=0,pos=10, sign=1;
    for (auto c: n)
    {
        if (c=='-')
        {
            sign*=-1;
            continue;
        }
        
        else{
        output=output*pos+(c-'0');
        //pos*=10;
        }
    }
    //cout<<output<<endl;
    return output*sign;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    deque<int> sequenceOrder;
    cin>>n>>k;
    cin.ignore();
    string temp;
    getline(cin,temp);
    istringstream ss(temp);
    string order;
    bool flag=false;
    while(getline(ss,order,' '))
    {
        if (order=="undo")
        {
            flag=true;
            continue;
        }
        else if (flag)
        {
            int num=strToNum(order);
            //stack<int> tem;
            for (int i=0; i<num; i++)
            {
                //tem.push(sequenceOrder.back());
                if (!sequenceOrder.empty())
                sequenceOrder.pop_back();
            }
            flag=false;
        }
        else
        {
            int num=strToNum(order);
            sequenceOrder.push_back(num);
        }
    }
    ll initial=0;
    while(!sequenceOrder.empty())
    {
        int move=sequenceOrder.front();
        //cout<<move<<endl;
        initial=(initial+move+10000*n)%n;
        //cout<<move<<endl;
        sequenceOrder.pop_front();
    }
    cout<<initial<<endl;
    return 0;
}
