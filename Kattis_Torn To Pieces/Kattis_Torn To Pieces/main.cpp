//
//  main.cpp
//  Kattis_Torn To Pieces
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

unordered_map<string,list<string>> adjacentLis;
unordered_map<string, int> visited;
deque<string> path;
string startPos, destination;
stack<string> dfsS;
bool flag=false;
stack<int> n;
void dfs (string currPos)
{
    
    visited[currPos]=1;
    for (auto c: adjacentLis[currPos])
    {
        if (c==destination)
        {
            path.push_back(c);
            flag=1;
            return;
        }
        if(visited[c]) continue;
        path.push_back(c);
        dfs(c);
        if (flag) return;
        path.pop_back();
    }
}

void NonReccur_dfs()
{
    dfsS.push(startPos);
    path.push_back(startPos);
    while(!dfsS.empty())
    {
        string p=dfsS.top();
        dfsS.pop();
        path.push_back(p);
        visited[p]=1;
        int prepe=0;
        for (auto c: adjacentLis[p])
        {
            
            if (c==destination)
            {
                path.push_back(c);
                while(!path.empty())
                {
                    cout<<path.front()<<" ";
                    path.pop_front();
                    
                }
                flag=true;
                cout<<endl;
                return;
                
            }
            else if (visited[c]==0)
            {
                
                dfsS.push(c);
                prepe++;
            }
            
        }
        int te=n.top();
        n.pop();
        te--;
        if (te<=0) path.pop_back();
        else n.push(te);
        n.push(prepe);
        
        
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;//2≤𝑁≤32
    cin>>N;
    cin.ignore();
    string temp, a, b;
 
    for (int i=0 ;i< N;i++)
    {
        getline(cin,temp);
        istringstream ss(temp);
        ss>>a;
        visited[a]=0;
        while(ss>>b)
        {
            visited[b]=0;
            adjacentLis[a].push_back(b);
            adjacentLis[b].push_back(a);
        }
    }
    
    cin>>startPos>>destination;
    if (!visited.count(startPos)||!visited.count(destination))
    {
        cout<<"no route found"<<endl;
        return 0;
    }
    path.push_back(startPos);
    
    dfs(startPos);
    if (flag==false)
    {
        cout<<"no route found"<<endl;
    }
    else
    {
        while(!path.empty())
        {
            cout<<path.front()<<" ";
            path.pop_front();
            
        }
        cout<<endl;
    }
    return 0;
}


/*
 总结：
 1. dfs寻找路径一般使用recursion版
 2. 非recursion版保留完整路径较困难， 需要多一个stack维护每一层个数
 3. 非递归实现 dfs逻辑：
    非递归实现
    非递归实现需要借助堆栈(先入后出，后入先出)，在C++中使用stack容器即可。

    问题
    若给定一个序列，需要找到其中的一个子序列，判断是否满足一定的条件。下面将程序实现DFS对子序列的搜索过程。

        实现步骤：
        1、首先将根节点放入堆栈中。
        2、从堆栈中取出第一个节点，并检验它是否为目标。如果找到目标，则结束搜寻并回传结果。否则将它某一个尚未检验过的直接子节点栈中。
        3、重复步骤2。
        4、如果不存在未检测过的直接子节点。将上一级节点加入堆栈中。重复步骤2。
        5、重复步骤4。
        6、若堆栈为空，表示整张图都检查过了——亦即图中没有欲搜寻的目标。结束搜寻并回传“找不到目标”。
 
 4. 思考： 用非递归的方法做路径追踪：
        a. 用一个map保存（ordered, fifo) 是哪个元素从过来的（如a到了b记住）, 遇到正确结果就逆向追踪；
        b. 除此之外还要多一个map（unordered）， 记录每个node向外扩展了几个node， 当有子node结束时， 要把ta扩展数减少， 当减为零时. erase
 
 */
