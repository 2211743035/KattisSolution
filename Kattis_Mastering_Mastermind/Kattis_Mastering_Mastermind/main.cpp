//
//  main.cpp
//  Kattis_Mastering_Mastermind
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n;
    cin>>n;
    string first,second;
    cin>>first>>second;
    istringstream fir(first);
    istringstream sec(second);
    map<char,int> firMap,secMap;
    for (int i=0; i<26; i++)
    {
        firMap['A'+i]=0;
        secMap['A'+i]=0;
    }
    char code,guess;
    int r=0;
    for (int i=0; i<n;i++)
    {
        fir>>code;
        sec>>guess;
        if (code==guess) r++;
        firMap[code]++;
        secMap[guess]++;
    }
    int mapped=0;
    for (int i=0; i<26;i++)
    {
        mapped+=min(firMap['A'+i],secMap['A'+i]);
    }
    cout<< r<<" "<<mapped-r<<"\n";
    return 0;
}
