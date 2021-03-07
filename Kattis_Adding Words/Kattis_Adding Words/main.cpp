//
//  main.cpp
//  Kattis_Adding Words
//
//  Created by mcr on 26/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
//# include <string.h>
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
    string temp;
    unordered_map<string,int> strToInt;
    unordered_map<int,string> intToStr;
    while (getline(cin,temp))
    {
       
        istringstream ss(temp);
        string order,variable1;
        ss>>order;
        if (order=="def")
        {
            int t;
            ss>>variable1>>t;
            //cout<<"variable1: "<<variable1<<" t: "<<t<<endl;
            
            if (strToInt.count(variable1))
                
            {
                intToStr.erase(strToInt[variable1]);
                strToInt.erase(variable1);
            }
            strToInt[variable1]=t;
            
            //if (intToStr.count(t)) strToInt.erase(intToStr[t]);
            intToStr[t]=variable1;
             
        }
        else if (order=="calc" )
        {
            string out="";
            string sign="+";

            bool flag=true;
            int output=0;
            ss>>variable1;
            //cout<<variable1<<" ";
            out+=variable1;
            while(ss>>sign)
            {
                
                if (sign=="=") break;
                else
                {
                    string variable2;
                    ss>>variable2;
                    if (variable2=="=")
                    {   variable2="";
                        break;
                        
                    }
                    
                    if (strToInt.find(variable1)==strToInt.end()|| strToInt.find(variable2)==strToInt.end())
                    {
                        flag=false;
                        //cout<<sign<<" "<<variable2<<endl;
                        out+=(" "+sign+ " "+ variable2);
                    }
                    
                    else
                    {
                        out+=(" "+sign+ " "+ variable2);
                        //cout<<sign<<" "<<variable2<<" ";
                        if (sign=="-") output-=strToInt[variable2];
                        else if (sign=="+") output+=strToInt[variable2];
                    }
                    
                }
            }
            
            if( strToInt.find(variable1)!= strToInt.end()&& flag)
            {
            output+=strToInt[variable1];
            }
            else
            {
                flag=false;
            }
            
            if (flag)
            {
                if (intToStr.count(output))
                {
                    cout<<out<<" = "<<intToStr[output]<<endl;
                }
                else
                {
                    cout<<out<<" = unknown\n";
                }
            }
            else
            {
                cout<<out<<" = unknown\n";
            }
            
        }
        else if (order=="clear")
        {
            intToStr.clear();
            strToInt.clear();
        }
        
        ss.str("");
        if (cin.eof()) break;
    }
    return 0;
}

/*
 def foo 3
 calc foo + bar =
 def bar 7
 def programming 10
 calc foo + bar =
 def is 4
 def fun 8
 calc programming - is + fun =
 def fun 1
 calc programming - is + fun =
 clear
 */

/*
 foo + bar = unknown
 foo + bar = programming
 programming - is + fun = unknown
 programming - is + fun = bar
 */

/*
 总结：
 1. 条件判断一定要自洽
 2. map和set中的find和count（找key：
        find()方法返回值是一个迭代器，成功返回迭代器指向要查找的元素，失败返回的迭代器指向end。
        count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素。
 */
