//
//  main.cpp
//  Kattis_Join Strings
//
//  Created by mcr on 21/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>

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

struct Vertex
{
    int num;
    Vertex *next;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    vector<string> nameLis(N+10);
    
    for (int i=1; i<=N; i++)
    {
        cin>>nameLis[i];
    }
    if (N==1)
    {
        cout<<nameLis[1]<<endl;
        return 0;
    }
    vector<Vertex*> sequenceLis(N+10), tails(N+10);
    set<int> headLis;
    for (int i=0; i<N+10; i++)
    {
        sequenceLis[i]=NULL;
        tails[i]=NULL;
    }
    int a, b;
    for (int i=0; i<N-1; i++)
    {
        cin>>a>>b;
        headLis.insert(a);
        Vertex *curr=sequenceLis[a];
        if (sequenceLis[a]==NULL)
        {
            Vertex *newHead =new Vertex();
            newHead->num=b;
            newHead->next=NULL;
            curr=newHead;
            sequenceLis[a]=newHead;
            //cout<<sequenceLis[a]->num<<endl;
        }
        else
        {
            //Vertex *curr=sequenceLis[a];
            /*
            while (curr->next!=NULL)
            {
                curr=curr->next;
            }
             */
            curr=tails[a];
            Vertex * newTail= new Vertex();
            newTail->num=b;
            curr->next=newTail;
            curr=newTail;
        }
        tails[a]=curr;
        if (sequenceLis[b]!=NULL)
        {
            curr->next=sequenceLis[b];
            //cout<<sequenceLis[b]->num<<endl;
            tails[a]=tails[b];
            sequenceLis[b]=NULL;
        }
        
        headLis.erase(b);
    }
    cout<<nameLis[*headLis.begin()];
    int he=*headLis.begin();
    Vertex *curr= sequenceLis[he];
    while(curr!=NULL)
    {
        cout<<nameLis[curr->num];
        curr=curr->next;
    }
    cout<<"\n";
    return 0;
}

/*
 总结：
 1. 思路：连同串问题可考虑用 hash close chaining 来做
 2. 要考虑0的问题
 3. 写hash close chaining时， 尾部是一个问题， visit会比较慢， 用另一个vector记录尾部，实现O(1)连接
 4. set的erase是有返回值的，set中有要删元素返回1，没有返回0
 */
