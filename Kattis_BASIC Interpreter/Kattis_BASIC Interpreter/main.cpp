//
//  main.cpp
//  Kattis_BASIC Interpreter
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
ll variable[26];

ll overflow(ll inp)
{
    if (inp<=2147483647 && inp>=-2147483648 )
    return inp;
    else if (inp>2147483647 )
    return -2147483648+(inp-2147483648);
    else if (inp<-2147483648)
        return inp+2147483648 +2147483648;
    return inp;
}
 
/*
ll overflow(ll inp)
{
    ll mo=2147483648*2,way=inp;
    while(way<0)
    {
        way+=mo;
    }
    way=way%mo;
    return mo-2147483648;
}
 */


bool isNumber(const string& str) {    //判断字符串是否为数字
    istringstream sin(str);
    double test;
    return sin >> test && sin.eof();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    memset(variable,0, 26);
    map<int,pair<string,string>> orderLis;
    string temp;
    while(getline(cin,temp))
    {
        istringstream ss(temp);
        int label;
        string orderType,order="";
        ss>>label>>orderType;
        string t;
        //getline(ss,order,'');
        while(getline(ss,t,' ') ) order+=(t+" ");
        //cout<<label<<" "<<orderType<<" "<<order<<endl;
        orderLis[label]=make_pair(orderType, order);
        
    }
    //cout<<"haha"<<endl;
    map<int,pair<string,string>>::iterator it= orderLis.begin();
    for (;it!=orderLis.end(); it++)
    {
        string orderType=it->second.first,order=it->second.second;
        cout<<it->first<<" "<<order<<endl;
        if (orderType=="PRINT")
        {
            if (order[0]=='\"')
            {
                cout<<order.substr(1,order.length());
            }
            else
            {
                cout<<variable[order[0]-'A'];
            }
        }
        else if (orderType=="PRINTLN")
        {
            if (order[0]=='\"')
            {
                cout<<order.substr(1,order.length()-2)<<endl;
            }
            else
            {
                cout<<variable[order[0]-'A']<<endl;
            }
        }
        else if (orderType=="LET")
        {
            ll value=0;
            //cout<<"wuwu "<<order<<endl;
            istringstream ss(order);
            char varia, useless;
            string dig,num;
            ss>>varia>>useless>>num;
            
            if (isNumber(num))
            {
                //cout<<num<<endl;
                value=stoi(num);
            }
            
            else
            {
                value=variable[(int)num[0]-'A'];
            }
            char sign;
            //cout<<value<<endl;
            if(ss>>sign){
            string b;
            ll n;
            ss>>b;
                if (isNumber(b)) n=stol(b);
                else n=variable[b[0]-'A'];
            
            if (sign=='+')
            {
                value+=n;
            }
            else if(sign=='-')
            {
                value-=n;
            }
            else if (sign=='*') value*=n;
            else if (sign=='/') value/=n;
            }
            //cout<<varia<<" "<<num<<" "<<value<<endl;
            variable[varia-'A']=overflow(value);
            ss.str("");
        }
        else if (orderType=="IF")
        {
            istringstream ss(order);
            ll a,b,nextLabel;
            string aV,bV,sign,useless;
            ss>>aV>>sign>>bV;
            bool flag=true;
            if (isNumber(aV))
            {
                a=stol(aV);
            }
            else
            {
                a=variable[aV[0]-'A'];
            }
            if (isNumber(bV))
            {
                b=stol(bV);
            }
            else
            {
                b=variable[bV[0]-'A'];
            }
            if (sign=="=")
            {
                if (a==b) flag=true;
                else flag=false;
            }
            else if (sign==">")
            {
                if (a>b) flag=true;
                else flag=false;
            }
            else if (sign=="<")
            {
                if (a<b) flag=true;
                else flag=false;
            }
            else if (sign=="<>")
            {
                if (a!=b) flag=true;
                else flag=false;
            }
            else if (sign=="<=")
            {
                if (a<=b) flag=true;
                else flag=false;
            }
            else if (sign==">=")
            {
                if (a>=b) flag=true;
                else flag=false;
            }
            
            ss>>useless>>useless>>nextLabel;
            if (flag)
            {it=orderLis.find((int) nextLabel);
            it --;
            }
            
        }
    }

    return 0;
}
