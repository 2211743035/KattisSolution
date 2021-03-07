//
//  main.cpp
//  life_game
//
//  Created by mcr on 13/10/2020.
//

#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll N,K,cd, sumInCommon=0;
    cin>>N>>K;
    do {
    queue<ll> JackLis;
    queue<ll> JillLis;
    
    for (ll i=0;i<N;i++)
    {
        cin>>cd;
        JackLis.push(cd);
    }
        
    for (ll i=0;i<K;i++)
        {
            cin>>cd;
            JillLis.push(cd);
            
        }
        
    for (ll i=0;i<K;i++)
    {
        
        while(!JackLis.empty() && JackLis.front()<JillLis.front())
        {
            JackLis.pop();
        }
        if (JackLis.empty()) break;
        if (JillLis.front()==JackLis.front())
        {
            sumInCommon++;
            JackLis.pop();
            
        }
        JillLis.pop();
        
    }
    cin>>N;
    cin>>K;
    cout<<sumInCommon<<endl;
    }while(N!=0 || K!=0);
    return 0;
}
