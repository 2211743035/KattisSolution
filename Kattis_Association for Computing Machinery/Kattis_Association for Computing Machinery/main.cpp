//
//  main.cpp
//  Kattis_Association for Computing Machinery
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
    int N,p;
    cin>>N>>p;
    vector<int> hardnessLis;
    int fir;
    for (int i=0; i<N;i++)
    {
        int hardness;
        cin>>hardness;
        if (p!=i)
            hardnessLis.push_back(hardness);
        else
            fir=hardness;
    }
    priority_queue<int,vector<int>,greater<int>> nextQ {hardnessLis.begin(),hardnessLis.end()};
    if (fir>300)
    {
        cout<<0<<" "<<0<<endl;
    }
    else if (fir==300)
    {
        cout<<1<<" "<<300<<endl;
    }
    else
    {
        int currTime=fir,penaltyTime=fir,numQ=1;;
        while(!nextQ.empty()&&300-currTime>=nextQ.top())
        {
            currTime+=nextQ.top();
            penaltyTime+=currTime;
            numQ++;
            //cout<<numQ<<" "<<nextQ.top()<<endl;
            nextQ.pop();
            
        }
        cout<<numQ<<" "<<penaltyTime<<endl;
        
    }
    return 0;
}

/*
 总结：
 1.不同的变量尽量不要用相同的名字
 2. priority_queue初始化的方式
    vector<int> temp;
    priority_queue<int> pq{temp.begin(), temp.end()}；
 */
