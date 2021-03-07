//
//  main.cpp
//  Kattis_Build Dependencies
//
//  Created by mcr on 11/11/2020.
//


//#pragma GCC optimize(3,"Ofast","inline")
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
inline ll encodeS(string s)
{
    ll output=0;
    for (int i=(int)s.length();i>=0; i--)
    {
        if (s[i]>='a' && s[i]<='z')
        {
        output=output*26+(ll)(s[i]-'a');
        }
    }
   // cout<<s<<" "<<output<<endl;
    return output;
}
inline string decodeS(ll llS)
{
    string output="";
    int c;
     while(llS>0)
    {
        c=llS%26;
        output+=(char)(c+'a');
        llS/=26;
        
    }
    return output;
}

unordered_map<string,int> visit;
//unordered_map<ll,list<ll>> adjacentLis;
unordered_map<string,list<string>> adjacentLis;
int order=0;
int enco=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    cin.ignore();
    string temp;
    for (int i=0; i<n;i++)
    {
        getline(cin,temp);
        istringstream ss(temp);
        string head;
        ss>>head;
        head=head.substr(0,head.length()-1);
      
        //ll curr=encodeS(head);
        visit[head]=0;

        
        string depen;
        while(getline(ss,depen,' '))
        {
            //kahnLis[curr]++;
            //ll dep=encodeS(depen);
            adjacentLis[depen].push_back(head);
            visit[depen]=0;
        }
        
    }

    string star;
    cin>>star;
    queue<string> bfsQ;
    bfsQ.push(star);

    while(!bfsQ.empty())
    {
        string u=bfsQ.front();
        bfsQ.pop();
        if (!visit[u])
        {
        cout<<u<<endl;
        visit[u]=1;
        }
        //rem.insert(u);
        for (auto c: adjacentLis[u])
        {
          bfsQ.push(c);
        }
    }

    return 0;
}
