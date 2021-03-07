//
//  main.cpp
//  Kattis_A Classy Problem
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include <stack>
#include <queue>
#include<string>
#include<utility>
#include<sstream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
struct seq
{
    bool operator() (pair<ll,string>  l,pair<ll,string>  r)
    {
        if ( l.first==r.first) return l.second>r.second;
        return l.first < r.first;
    }
};

inline int trans(string cla)
{
    if (cla=="upper") return 3;
    else if (cla=="middle") return 2;
    else  return 1;
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        cin.ignore();
        stack<string> classes;
        string name,temp;
        priority_queue<pair<ll,string>,vector<pair<ll,string>>,seq> sequence;
        while(N--)
        {
            getline(cin,temp);
            //temp.replace(temp.find(":"),1,"");
            string eachClass,classStr;
            istringstream ss(temp);
            ss>>name;
            name=name.substr(0,name.length()-1);
            ss>>classStr;
            ss>>eachClass;
            istringstream sc(classStr);
            
            while(getline(sc,eachClass,'-'))
            {
                classes.push(eachClass);
            }
            int n=10;
            ll classVal=0;
            while (!classes.empty())
            {
                classVal+=trans(classes.top())*(1<<(2*n));
                n--;
                classes.pop();
            }
            while (n!=0)
            {
                classVal+=2*(1<<(2*n));
                n--;
            }
            
            sequence.push(make_pair(classVal,name));
        }
        while(!sequence.empty())
        {
            cout<<sequence.top().second<<"\n";
            sequence.pop();
        }
        cout<<"==============================\n";
        
    }
    return 0;
}

/*
 总结：
 1. hash时还是不要用复数做a，可能产生意想不到的状况
 2. 利用stack来逆比较
 3. hash实现hierachy比较
 4. 字符串流多个分隔符号可以分段进行
 5. 自定义priority_queue排序方式
 struct cmp{
 bool operator()(type a, type b)
 {
 return a<b;
 }
 };
 为大顶堆；
 */
