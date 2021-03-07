//
//  main.cpp
//  Kattis_Running MoM
//
//  Created by mcr on 27/10/2020.
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
string cities[1010];
unordered_map<string, int> citiesStatus;
unordered_map<string,list<string>> adjacentLis;
string flag="1";
stack<string> path;

void dfs(string startCity,string lastCity)
{
    if(citiesStatus[startCity]==0) citiesStatus[startCity]=1;
    else if(citiesStatus[startCity]==3) return;
    
    for (auto c: adjacentLis[startCity])
    {
        if (citiesStatus[startCity]==2) continue;
        
        else if(citiesStatus[c]==1||citiesStatus[c]==3)
        {
            flag=c;
            citiesStatus[c]=3;
            stack<string>temp;
            while(!path.empty())
            {
                if (path.top()==c) break;
                citiesStatus[path.top()]=3;
                temp.push(path.top());
                path.pop();
            }
            while(!temp.empty())
            {
                path.push(temp.top());
                temp.pop();
            }
        }
        
        path.push(c);
        dfs(c,startCity);
        path.pop();
        
    }
    if (citiesStatus[startCity]!=3) citiesStatus[startCity]=2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;//1≤𝑛≤5000
    cin>>n;
    string city1, city2;
    for (int i=0;i<n; i++)
    {
        cin>>city1>>city2;
        adjacentLis[city1].push_back(city2);
    }
    int numCity=0;
    while(1)
    {
        if (cin.eof()) break;
        cin>>cities[numCity];
        citiesStatus[cities[numCity]]=0;
        numCity++;
   
        
    }
    for (int i=0; i<numCity; i++)
    {
        if (citiesStatus[cities[i]]==0)
        {
            path.push(cities[i]);
            dfs(cities[i],"");
            path.pop();
        }
    }
    for (int i=0 ; i<numCity;i++)
    {
        if (cities[i]!="")
        {
        cout<<cities[i]<<" ";
        if (citiesStatus[cities[i]]==3) cout<<"safe"<<endl;
        else cout<<"trapped"<<endl;
        }
    }
    return 0;
}

/*
 总结：
 1. 非常经典的graph travel题： 找环
 2. 如果确定了：4个状态：unvisit, visited_and_hopeless, visited_and_may_have_hope, in_loop
 3. 更新loop状态可用stack来记path
 4. 父节点在directed graph中不能轻易排除， 考虑"travel loop“ 还是不考虑要想清楚
 5. 针对字符串类型的数据用unordered_map代替vector做adjacentLis
 6. 几种特殊情况：
    (i).    5
            a b
            c b
            d b
            e b
            f b
            a b c d e f
 
    (ii).   2
            a b
            b a
            a b c
 
    (iii).  5
            a b
            b c
            c a
            c d
            d b
            a b c d e
 
    
 */
