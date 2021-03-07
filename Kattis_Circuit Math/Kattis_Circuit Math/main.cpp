//
//  main.cpp
//  Kattis_Circuit Math
//
//  Created by mcr on 20/10/2020.
//


//#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>



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

inline string trans_out(bool b)
{
    if (b) return "T";
    else return "F";
}

inline bool trans_in(string a)
{
    if (a=="F") return false;
    else return true;
}

int main()
{
    map<string,string> rem;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    
    stack<string>  orders;
    
    queue<string> inputV;
    for (int i=0; i<n; i++)
    {
        string te;
        cin>>te;
        string ke="";
                ke+= ('A'+i);
                rem[ke]=te;
        //inputV.push(temp);
    }
    cin.ignore();
    string temp;
    getline(cin,temp);
    stringstream ss(temp);
    string order;
    while( getline(ss, order,' ') )
    {
        if (order=="*")
        {
            string a,b;
            a=orders.top();
            orders.pop();
            b=orders.top();
            orders.pop();
            string res=trans_out(trans_in(a)&trans_in(b));
            orders.push(res);
            
        }
        else if (order=="+")
        {
            string a,b;
            a=orders.top();
            orders.pop();
            b=orders.top();
            orders.pop();
            string res=trans_out(trans_in(a)|trans_in(b));
            orders.push(res);
        }
        else if (order=="-")
        {
            string a;
            a=orders.top();
            orders.pop();
            if (a=="T") orders.push("F");
            else orders.push("T");
        }
        else
        {
            /*
            string a=inputV.front();
            //cout<<a<<endl;
            inputV.pop();
             */
            orders.push(rem[order]);
        }
    }
    cout<<orders.top()<<endl;
    
    return 0;
}
