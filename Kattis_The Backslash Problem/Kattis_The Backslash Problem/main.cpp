//
//  main.cpp
//  Kattis_The Backslash Problem
//
//  Created by mcr on 28/10/2020.
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int level;
    string intendedWords;
    while(cin>>level)
    {
       
        
        //cin>>level;
        cin.ignore();
        getline(cin, intendedWords);
        string outputWords="";
        int times=pow(2,level)-1;
        string temp(times,'\\');

             
            for (auto c: intendedWords)
            {
               
                if ((c>='!'&&c<='*')||(c>='['&&c<=']'))//! up to and including * are special. Also, characters from [ up to and including ] are considered special.
                {
                    
                    
                    //for (int i=0;i<times; i++)
                    cout<<temp;
                    cout<<c;
                }
                else
                {
                    cout<<c;
                }
            }
            
           
        
        
        cout<<endl;
    }
    
    return 0;
}

/*
 总结：
 1. 同时用cin和getline时不要用cin.eof(), 直接while(cin>>val)
 2. 字符串处理尽量用字符串公示
 */
