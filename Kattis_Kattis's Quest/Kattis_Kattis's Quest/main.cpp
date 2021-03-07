//
//  main.cpp
//  Kattis_Kattis's Quest
//
//  Created by mcr on 28/10/2020.
//


//#pragma GCC optimize(3,"Ofast","inline")1
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
struct node
{
    
    int energy;
    int gold;
    node() {}
    node(int ener, int gol )
    {
        gold=gol;
        energy=ener;
    }
};
bool operator <(const node & left, const node & right)
{
    if (left.energy==right.energy) return left.gold>right.gold;
    return left.energy>right.energy;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;//𝑁 (1≤𝑁≤2⋅105)
    cin>>N;
    //set<pair<int,int>,greater<pair<int,int>>> queries; // E/ G
    map<node,int> queries;
    cin.ignore();
    string temp;
    for (int i=0; i<N; i++)
    {
        string orders;
        int a, b;
        //cout<<"hi"<<endl;
        //cin>>order>>a;
        getline(cin,temp);
        istringstream ss(temp);
        ss>>orders>>a;
        orders+='i';
        //cout<<" hi "<<orders<<" "<<a<<endl;
        if (orders=="addi" || orders=="ADD")
        {
            ss>>b;
            //cin.ignore();
            //cout<<" hi "<<a<<" "<<b<<endl;
            if (queries.count(node(a,b)))
            {
                queries[node(a,b)]++;
            }
            else queries[node(a,b)]=1;
            //map<node,int>::iterator it=queries.find(node(a,b));
           // cout<<it->first.energy<<" "<<it->first.gold<<endl;
            continue;
        }
        else if (orders=="queryi")
        {
            ll gold=0;
            //cin.ignore();
            map<node,int>::iterator it=queries.lower_bound(node(a,100000+10));
            while((a-(it->first.energy))>=0 &&it!=queries.end())
            {
                
                
               // cout<<a<<" "<<it->first.energy<<" "<<it->first.gold<<endl;
                gold+=it->first.gold;
                a=a-it->first.energy;
                it->second--;
                if (it->second<=0)
                {
                map<node,int>::iterator temp=it;
                it++;
                queries.erase(temp);
                }
            }
            cout<<gold<<endl;
            
            
        }
    }
    return 0;
    
}
