//
//  main.cpp
//  Kattis_Shiritori
//
//  Created by mcr on 25/10/2020.
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
    unordered_set<string> wordLis;
    int N;
    cin>>N;
    string preS, currS;
    cin>>preS;
    wordLis.insert(preS);
    for (int i=2; i<=N; i++)
    {
        cin>>currS;
        if (currS[0]==preS[preS.length()-1] && wordLis.find(currS)==wordLis.end())
        {
            preS=currS;
            wordLis.insert(preS);
        }
        else
        {
            if (i&1)
            {
                for (int j=i+1; j<N; j++) cin>>preS;
                cout<<"Player 1 lost"<<endl;
                return 0;
            }
            else
            {
                for (int j=i+1; j<N; j++) cin>>preS;
                cout<<"Player 2 lost"<<endl;
                return 0;
            }
        }
        
    }
    cout<<"Fair Game"<<endl;
    return 0;
}
