//
//  main.cpp
//  ps4
//
//  Created by mcr on 10/10/2020.
//
#include <iostream>
#include<utility>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define ll long long
struct comp
{
    bool operator() (const pair<ll, string>& left, const pair<ll, string>& right) const
    {
        if (left.first==right.first) return left.second<right.second;
        else return left.first>right.first;
    }
};
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    int groups=N/3;
    string name;
    ll S1,S2,S3;
    set<pair<ll,string>,comp> skill1;
    set<pair<ll,string>,comp> skill2;
    set<pair<ll,string>,comp> skill3;
    map<string,bool> remainList;
    while(N--)
    {
        cin>>name>>S1>>S2>>S3;
        skill1.insert(make_pair(S1,name));
        skill2.insert(make_pair(S2,name));
        skill3.insert(make_pair(S3,name));
        remainList[name]=true;
    }
    priority_queue<string,vector<string>, greater<string> > nameList;
    while(groups--)
    {
        
        while (remainList[(skill1.begin())->second]==false) skill1.erase(skill1.begin());
        remainList[(skill1.begin())->second]=false;
        //cout<<skill1.begin()->second<<" ";
        nameList.push(skill1.begin()->second);
        skill1.erase(skill1.begin());
        while (remainList[(skill2.begin())->second]==false) skill2.erase(skill2.begin());
        remainList[(skill2.begin())->second]=false;
        //cout<<skill2.begin()->second<<" ";
        nameList.push(skill2.begin()->second);
        skill2.erase(skill2.begin());
        while (remainList[(skill3.begin())->second]==false) skill3.erase(skill3.begin());
        remainList[(skill3.begin())->second]=false;
        //cout<<skill3.begin()->second<<"\n";
        nameList.push(skill3.begin()->second);
        skill3.erase(skill3.begin());
        cout<<nameList.top()<<" ";
        nameList.pop();
        cout<<nameList.top()<<" ";
        nameList.pop();
        cout<<nameList.top()<<"\n";
        nameList.pop();
    }
    
    return 0;
}
