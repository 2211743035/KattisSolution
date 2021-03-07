//
//  main.cpp
//  Kattis_Mall Mania
//
//  Created by mcr on 19/11/2020.
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

int iif=1000000000;
vector<int> adjLis={1,0,-1,0,0,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int M1,M2;
    cin>>M1;
    
    while(1)
       
    {   if (M1==0) break;
        int a,s;
        int minNum=1000000000;
        
        //int mapS[2000][2000];
        vector<vector<int>> mapS(2010, vector<int> (2010, iif));
        queue<pair<int,int>> bfsQ;
    
        for (int i=0; i<M1; i++)
        {
            cin>>a>>s;
            mapS[a][s]=0;
            bfsQ.push({a,s});
        }
        cin>>M2;
    
        for (int i=0; i<M2;i++)
        {
            cin>>a>>s;
            mapS[a][s]=-1;
        }
    
        bool flag=true;
    
        while(!bfsQ.empty()&& flag)
        {
            
            auto [aT,sT]=bfsQ.front();

            bfsQ.pop();
            for (int i=0; i<4; i++)
            {
                int a_=aT+adjLis[2*i],s_=sT+adjLis[2*i+1];
                if (a_>=0&&a_<2001&&s_>=0&&s_<2001)
                {
                    if (mapS[a_][s_]==-1)
                    {
                        //cout<<mapS[aT][sT]+1<<endl;
                        flag=false;
                        minNum=min(mapS[aT][sT]+1,minNum);
                        //break;
                    }
                    else if (mapS[a_][s_]>mapS[aT][sT]+1)
                    {
                        mapS[a_][s_]=mapS[aT][sT]+1;
                        bfsQ.push({a_,s_});
                    }
                }
            }
        }
        cout<<minNum<<endl;
        cin>>M1;
    
    }
    
    return 0;
}
