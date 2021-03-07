//
//  main.cpp
//  Kattis_EpigDanceOff
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include <map>
#include<sstream>
using namespace std;
inline int trans(char a)
{
    if (a=='$') return 1;
        else return 0;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    map<int,int> judger;
    for (int i=0; i< M; i++) judger[i]=0;
    cin.ignore();
    string line;
    for (int i=0; i< N; i++)
    {
        getline(cin,line);
        istringstream ss(line);
        char c;
        for (int j=0;j<M;j++)
        {
            ss>>c;
            judger[j]+=trans(c);
        }
    }
    int output=0;
    for (int i=0; i<M; i++)
    {
        if (judger[i]==0) output++;
    }
    cout<<output+1<<"\n";
    return 0;
}

/*
 总结：
 八皇后问题简化版
 */
