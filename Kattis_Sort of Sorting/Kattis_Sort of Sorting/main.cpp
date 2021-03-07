//
//  main.cpp
//  Kattis_Sort of Sorting
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (1)
    {
        int n;
        cin>>n;
        
        if (n==0) break;
        vector<string> nameLis(n);
        for (int i=0; i<n; i++)
        {
            cin>>nameLis[i];
        }
        stable_sort(nameLis.begin(),nameLis.end(), []  (const string a ,const string b){if (a[0]==b[0]) return a[1]<b[1]; return a[0]<b[0];} );
        for (vector<string> ::iterator it=nameLis.begin() ;it!=nameLis.end(); it++)
        {
            cout<<*it<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
