//
//  main.cpp
//  Kattis_Greeting Card
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
ll adjacentLis[12][2]={{2018,0},{0,2018}, {-2018,0}, {0, -2018}, {1680,1118}, {1680, -1118}, {-1680,1118},{-1680,-1118},{1118,1680},{-1118,1680},{1118,-1680},{-1118,-1680} };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    unordered_set<ll> points;
    unordered_map<ll, int> pointsUnvisited;
    int N;
    cin>>N;
    for (int i=0; i<N; i++)
    {
        ll x, y;
        cin>>x>>y;
        points.insert((x<<32)+y);
        pointsUnvisited[(x<<32)+y]=1;
    }
    int output=0;
    for (auto  c=points.begin(); c!=points.end(); c++)
    {
        ll cu=*c;
        if (pointsUnvisited[cu])
        {
            pointsUnvisited[cu]=0;
            for (auto d:adjacentLis)
            {
                if( points.find(cu+(d[0]<<32)+d[1])!=points.end() && pointsUnvisited[cu+(d[0]<<32)+d[1]])
                {
                    output++;
                    //pointsUnvisited[cu+(d[0]<<32)+d[1]]=0;
                }
            }
        }
    }
    cout<<output<<endl;
    return 0;
}

/*
 总结：
 1. 默认情况unordered_set和unordered_map不能用pair或者tuple作为key
 
 unordered_*容器需要哈希函数。默认情况下，他们使用std::hash，但标准库中提供的std::hash没有std::pair<T1,T2>专门化。另一方面，有序容器依赖std::less（默认情况下），std::pair 提供operator<。这就是它起作用的原因。

 为了拥有一个pair的无序容器，您必须自己提供一个哈希仿函数。例如：

 struct SimpleHash {
     size_t operator()(const std::pair<int, int>& p) const {
         return p.first ^ p.second; //hash函数
     }
 };
 std::unordered_set<std::pair<int, int>, SimpleHash> S;
 S.insert(std::make_pair(0, 1));
 
 2. 看一个数据中有多少对： n+（n-1)+...+1
 */
