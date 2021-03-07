//
//  main.cpp
//  Kattis_Quick Brown Fox
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

inline char trans(char a)
{
    if (a>='a' && a<='z') return a;
    else if (a>='A' &&a<='Z') return a-'A' +'a';
    else return 'z'+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    cin.ignore();
    for (int i=0;i<N; i++)
    {
        
        int hashLetter[27];
        for (int i=0; i<27;i++) hashLetter[i]=0;
        string temp;
        
        getline(cin, temp);
        for (auto c: temp)
        {
            char real=trans(c);
            hashLetter[real-'a']++;
        }
        string output="";
        for (int i=0; i<26; i++)
        {
            if (hashLetter[i]==0) output+=(i+'a');
        }
        if (output=="") cout<<"pangram"<<endl;
        else cout<<"missing "<<output<<endl;
        
    }
 
    return 0;
}

/*
 总结：
 1. cin后用getline前要用 cin.ignore()
 2. 数组需要初始化
 */
