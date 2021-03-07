//
//  main.cpp
//  Kattis_GreedilyIncreasingSubsequence_1011
//
//  Created by mcr on 12/10/2020.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> permutationA(N);
    for (int i=0;i<N;i++)
    {
        cin>>permutationA[i];
    }
    queue<int> GIS;
    vector<int>::iterator it=permutationA.begin();
    int pre=*it;
    GIS.push(pre);
    it++;
    while(it!=permutationA.end())
    {
        if(*it>pre)
        {
            pre=*it;
            GIS.push(pre);
        }
        it++;
    }
    cout<<GIS.size()<<"\n";
    int flag=0;
    while(!GIS.empty())
    {
        if (flag) cout<<" ";
        cout<<GIS.front();
        GIS.pop();
        flag=1;
    }
    cout<<"\n";
    return 0;
}
