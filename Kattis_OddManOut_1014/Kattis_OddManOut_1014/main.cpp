//
//  main.cpp
//  Kattis_OddManOut_1014
//
//  Created by mcr on 14/10/2020.
//

#include <iostream>
#include <unordered_set>
#define ll long long
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N, cases=1;
    cin>>N;
    while(N--)
    {
        int G;
        cin>>G;
        unordered_set<ll> invitationCodes;
        ll code;
        while(G--)
        {
            cin>>code;
            if (invitationCodes.find(code)==invitationCodes.end())
            invitationCodes.insert(code);
            else
            invitationCodes.erase(code);
        }
        unordered_set<ll>::iterator it=invitationCodes.begin();
        cout<<"Case #"<<cases<<": "<<*it<<"\n";
        cases++;
    }
    return 0;
}
