//
//  main.cpp
//  Kattis_Flip Five
//
//  Created by mcr on 20/11/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
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

vector<int> adjLis={0,0,1,0,-1,0,0,1,0,-1};
inline bool match(char a[][3],char b[][3])
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (a[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}


inline bool match(char a[][3],vector<char> b)
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (a[i][j]!=b[i*3+j]) return false;
        }
    }
    return true;
}

inline bool inborder(int r,int c )
{
    if (r>=0&&r<3&&c>=0&&c<3) return true;
    else return false;
}

inline string change(string initialMap, int r,int j)
{

    for (int i=0; i<5; i++)
    {
        int r_=r+adjLis[2*i],c_=j+adjLis[2*i+1];
        if (inborder(r_,c_))
        {
            initialMap[r_*3+c_]=initialMap[r_*3+c_]=='.'?  '*':'.';
        }
    }
    return initialMap;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int P;
    cin>>P;
 
        
       // char destination[3][3],ini[3][3];
        string destination="", ini(9,'.');

    
        queue<string> mapS;
        mapS.push(ini);
        int times=100000000,curr=0;
       
        unordered_map<string,int> visited;
        visited[ini]=0;
        while(!mapS.empty())
        {
            curr++;
            queue<string>temp;
            while(!mapS.empty())
            {
                string u=mapS.front(); mapS.pop();
                for (int i=0; i<3; i++)
                {
                    for (int j=0; j<3; j++)
                    {
                        string candi=change(u, i,j);
                       
                        if (!visited.count(candi))
                        {
                            //cout<<candi<<" "<<curr<<endl;
                            visited[candi]=curr;
                            temp.push(candi);
                        }
                        else if (curr<visited[candi])
                        {
                            //cout<<candi<<" "<<curr<<endl;
                            visited[candi]=curr;
                            temp.push(candi);
                        }
                    }
                   
                }
                //cout<<curr<<endl;
                
               
            }
            mapS=temp;
        }
    while(P--)
    {
        destination="";
    for (int i=0 ; i<9; i++)
    {
        char c;
        cin>>c;
        destination=destination+c;
    }
        cout<<visited[destination]<<endl;
    }
    return 0;
}

/*
 总结：
 1.类似魔方问题
 2. 首先分析问题的复杂程度（会有多少量的计算，一共有多少种情况
 3. 选择适合的数据
 */
