//
//  main.cpp
//  Kattis_Srednji
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N, B, t=0,num,tB,iB;
    int output=0;
    cin>>N>>B;
    set<int> numLis;
    vector<int> firstHalf,secondHalf;
    unordered_map<int,int> firstH, secondH;
    bool flag=false;
    for (int i=0; i <N; i++)
    {
        cin>>num;
        
        if (num==B)
        {
            flag=true;
            iB=i;
            continue;
        }
        
        if (flag)
        {
            secondHalf.push_back(t);
            if (num<B)
            {
                t--;
            }
            else
            {
                t++;
            }
            if (t==0) output++;
            if (secondH.count(t))
            {
                secondH[t]++;
            }
            else
            {
                secondH[t]=1;
            }
        }
        else
        {
            firstHalf.push_back(num);
        }
        
    }
    t=0;
    for (int i=iB-1; i>=0; i--)
    {
        if (firstHalf[i]>B)
        {
            t--;
        }
        else t++;
        if (t==0) output++;
        if (firstH.count(t))
        {
            
            firstH[t]++;
        }
        else
        {
            firstH[t]=1;
        }
    }
  
    unordered_map<int,int> ::iterator it=firstH.begin();
    for (;it!=firstH.end(); it++)
    {
        if (secondH.count(it->first))
        {
            output+=firstH[it->first]*secondH[it->first];
        }
    }
    cout<<output+1<<endl;
    return 0;
}

/*
 总结：
 1. 找两类和相同的区间
 2. 因为某个元素一定包含， 以一定包含的元素作为起点
 3. 只要两类差互补的点都可取
 */
