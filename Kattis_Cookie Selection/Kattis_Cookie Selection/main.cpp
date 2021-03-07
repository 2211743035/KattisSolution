//
//  main.cpp
//  Kattis_Cookie Selection
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
    string inp;
    int num,largerNum=0, smallerNum=0;
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> largerHalf;
    /*
    set<int,greater<int>>  smallerHalf;
    set<int> largerHalf;
     */
    while(true)
    {
        if (cin.eof()) break;
        cin>>inp;
        if (inp=="#")
        {
            if (!largerHalf.empty())
            {
            /*
            cout<<*largerHalf.begin()<<endl;
            largerHalf.erase( * largerHalf.begin());
             */
                cout<<largerHalf.top()<<endl;
                largerHalf.pop();
                //cout<<"size: "<<largerHalf.size()<<endl;
                largerNum--;
            }
        }
        else
        {
            num=stoi(inp);
        if (largerHalf.empty())
        {
            //largerHalf.insert(num);
            largerHalf.push(num);
            largerNum++;
            
        }
        else if (smallerHalf.empty())
        {
        
                /*
                smallerHalf.insert(*largerHalf.begin());
                largerHalf.erase(largerHalf.begin());
                largerHalf.insert(num);
                 */
                largerHalf.push(num);
                smallerHalf.push(largerHalf.top());
                largerHalf.pop();
                smallerNum++;
          
        }
        else
        {
            if (num>= largerHalf.top())
            {
                //largerHalf.insert(num);
                largerHalf.push(num);
                largerNum++;
            }
            else
            {
                //smallerHalf.insert(num);
                smallerHalf.push(num);
                smallerNum++;
            }
        }
            
        }
     
        while(smallerNum && smallerNum>largerNum)
        {
            //largerHalf.insert(*smallerHalf.begin());
            largerHalf.push(smallerHalf.top());
            //smallerHalf.erase(smallerHalf.begin());
            //cout<<"larger: "<<*largerHalf.begin()<<endl;
            smallerHalf.pop();
            smallerNum--;
            largerNum++;
        }
        while(largerNum && largerNum-smallerNum>1)
        {
            smallerHalf.push(largerHalf.top());
            largerHalf.pop();
            //smallerHalf.insert(* largerHalf.begin());
            //largerHalf.erase(largerHalf.begin());
            smallerNum++;
            largerNum--;
            //cout<<largerHalf.top()<<" "<<smallerHalf.top()<<endl;
        }
        while((smallerNum && ! largerNum) ||(smallerNum&& smallerHalf.top() > largerHalf.top()))
        {
            int temp=largerHalf.top();
            //cout<<largerHalf.size()<<" "<<smallerHalf.size()<<endl;
            //cout<<largerNum<<" "<<smallerNum<<endl;
            largerHalf.pop();
            largerHalf.push(smallerHalf.top());
            smallerHalf.push(temp);
            

            //cout<<*largerHalf.begin()<<" "<<*smallerHalf.begin()<<endl;
        }
        
    }
    
    return 0;
}

/*
 只要两边的情况堆比bbst效率更高
 */
