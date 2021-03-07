//
//  main.cpp
//  Kattis_Conformity
//
//  Created by mcr on 25/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
//# include <string.h>
#include<math.h>

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
    int N;
    cin>>N;
    //unordered_map<int,int> popularityCourse;
    unordered_map<string,int> highestCom;
    
    vector<string> combination;
    

    cin.ignore();
    for (int i=0; i<N;i++)
    {
        string temp;
        getline(cin,temp);
        istringstream ss(temp);
        string course;
        vector<string> sortLis;
        int nums=0;
        
        while(getline(ss, course,' '))
        {
            sortLis.push_back(course);
            nums++;
        }
        sort(sortLis.begin(),sortLis.begin()+nums);
        string com="";
        for (int i=0; i<nums; i++)
        {
            com+=sortLis[i];
            //cout<<combination+tem+" a"<<" ";
        }
        combination.push_back(com);
        
        if (highestCom.count(com))
        {
            highestCom[com]++;
        }
        else
        {
            highestCom[com]=1;
        }
        
        
    }
    int maximum=0,maxi=0;
    
    for (auto c: combination)
    {
        if (highestCom[c]==maximum) maxi++;
        else if (highestCom[c]>maximum)
        {maxi=1;
         maximum=highestCom[c];
        }
    }
    cout<<maxi<<endl;

    return 0;
}

/*
 总结：
 1. map排序： map<int,int,greater<int>>
 2. 调用map iterator的元素：
 map<int,int,greater<int>>::iterator it=highestCom.begin();
 cout<<it->first<<endl; //key
 cout<<it->second<<endl; // value
 
 */
