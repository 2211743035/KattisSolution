//
//  main.cpp
//  Kattis_Spam
//
//  Created by mcr on 23/10/2020.
//

/*
 A preprocessing step has already transformed all whitespace characters to underscores (_), and the line will consist solely of characters with ASCII codes between 33 and 126 (inclusive).

 Output
 Output four lines, containing the ratios of whitespace characters, lowercase letters, uppercase letters, and symbols (in that order). Your answer should have an absolute or relative error of at most 10−6
 */


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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string temp;
    cin>>temp;
    double white_space=0, lower_case=0, upper_case=0, symble=0;
    for (auto c: temp)
    {
        
        if (c>='a' &&c<='z') lower_case++;
            else if (c>='A' && c<='Z') upper_case++;
            else if (c=='_') white_space++;
            else symble++;
    }
    double sum=white_space+upper_case+lower_case+symble;
    cout<<fixed<<setprecision(20)<<white_space/sum<<endl;
    cout<<fixed<<setprecision(20)<<lower_case/sum<<endl;
    cout<<fixed<<setprecision(20)<<upper_case/sum<<endl;
    cout<<fixed<<setprecision(20)<<symble/sum<<endl;
    return 0;
}
