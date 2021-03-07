//
//  main.cpp
//  Kattis_Working at the Restaurant
//
//  Created by mcr on 20/10/2020.
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    bool nobegin=false;
    while(1)
    {
    cin>>N;
    if (N==0) break;
    string order;
    int stack1=0, stack2=0,index=2, num=0;
    queue<string> output;
        if (nobegin) cout<<"\n";
    while(N--)
    {
        
        
        if (stack1==0&&stack2==0) index=2;
        cin>>order>>num;
        if (order=="DROP")
        {
            
                output.push("DROP 2 "+to_string(num));
                stack2+=num;
            /*
            else
            {
                output.push("MOVE 1->2 "+to_string(stack1));
                stack2=stack1;
                stack1=0;
                output.push("DROP 2 "+to_string(num));
                stack2+=num;
                index=2;
            }
             */
            
        }
        else
        {
        
                if(num<=stack1)
                {
                output.push("TAKE 1 "+to_string(num));
                stack1-=num;
                }
                else
                {
                    if(stack1>0)
                    
                    output.push("TAKE 1 "+to_string(stack1));
                    int t=stack1;
                    stack1=0;
                    output.push("MOVE 2->1 "+to_string(stack2));
                    stack1=stack2;
                    stack2=0;
                    output.push("TAKE 1 "+to_string(num-t));
                    stack1-=(num-t);
                    
                }
            
            /*
            else
            {
                output.push("MOVE 2->1 "+to_string(stack2));
                stack1=stack2;
                stack2=0;
                index=1;
                if(num<stack1)
                {
                output.push("TAKE 1 "+to_string(num));
                stack1-=num;
                }
                else
                {
                    output.push("TAKE 1 "+to_string(stack1));
                    stack1=0;
                }
            }
             */
        }
    }
      
    while(!output.empty())
    {
        cout<<output.front()<<endl;
        output.pop();
    }
        nobegin=true;
        
}
    return 0;
}

/*
 总结：
 用两个stack做一个queue两种思路：
 假设stack1承担pop和front
 stack2承担push和back()
 1. enqueue costly:
    也就是每次enque前把stack1中元素全部移到stack2再enqueue,enqueue完后再把stack2全部元素移到stack2  O(2N)=O(N) 复杂度
    deque O(1)
 2. deque costly:
    两条逻辑：
    A.凡是enque直接插入stack2 O(1)
    B. deque:
        i. 先从stack1中pop(),如果够就ok O(1)
        ii. 如果stack1中元素全被pop()完了, 把stack2中元素先全移动到stack1, 再继续从stack1中pop  O(N)+O(1)=O(N)
 
 总体方法2更优
 因为可能需要移动到次数和每次动需要移动的次数都更少
 */
