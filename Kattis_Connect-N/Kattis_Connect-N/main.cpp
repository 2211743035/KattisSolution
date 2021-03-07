//
//  main.cpp
//  Kattis_Connect-N
//
//  Created by mcr on 28/10/2020.
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

/*
const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;
*/
//int board[100+10][100+10];
int horizontalR[100+10], horizontalB[100+10],verticalR[100+10],verticalB[100+10],horizontalFlag[100+10],verticalFlag[100+10];
vector<int> piediagonalR(200+10, 0),piediagonalB(200+10, 0),piediagonalFlag(200+10, -1);
unordered_map<int,int> nadiagonalR, nadiagonalB, nadiagonalFlag;
bool flag=true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int X,Y,N;// (i.e., 2⩽𝑋⩽100 and 2⩽𝑌⩽100). (i.e., 𝑁⩽𝑋, and 𝑁⩽𝑌). X: rows
    cin>>X>>Y>>N;
    char chess;
    for (int i=0; i<110; i++)
    {
        horizontalR[i]=0;
        horizontalB[i]=0;
        verticalR[i]=0;
        verticalB[i]=0;
        horizontalFlag[i]=-1;
        verticalFlag[i]=-1;
       
    }
    for (int i=-110; i< 110; i++)
    {
    nadiagonalR[i]=0;
    nadiagonalB[i]=0;
    nadiagonalFlag[i]=-1;
    }
    
    for(int i=0; i<X; i++)
    {
        for (int j=0; j<Y; j++)
        {
            cin>>chess;
            if (chess=='O') continue;
            else if (chess=='R')
            {
                
                horizontalR[i]++;
                verticalR[j]++;
                piediagonalR[i+j]++;
                nadiagonalR[i-j]++;
                
                if (horizontalFlag[i]==1)
                {
                    horizontalB[i]=0;
                }
                horizontalFlag[i]=0;
                if (verticalFlag[j]==1)
                {
                    verticalB[j]=0;
                }
                verticalFlag[j]=0;
                if (piediagonalFlag[i+j]==1)
                {
                    piediagonalB[i+j]=0;
                }
                piediagonalFlag[i+j]=0;
                if (nadiagonalFlag[i-j]==1)
                {
                    nadiagonalB[i-j]=0;
                }
                nadiagonalFlag[i-j]=0;
                
                if (flag&&(horizontalR[i]>=N||verticalR[j]>=N||piediagonalR[i+j]>=N||nadiagonalR[i-j]>=N))
                {
                    //cout<<horizontalR[i]<<" "<<j<<" "<<verticalR[j]<<" "<<piediagonalR[i+j]<<" "<<nadiagonalR[i+j]<<" "<<i+j<<endl;
                    cout<<"RED WINS"<<endl;
                    flag=false;
                    
                }
            }
            else
            {
                horizontalB[i]++;
                verticalB[j]++;
                piediagonalB[i+j]++;
                nadiagonalB[i-j]++;
             
                if (horizontalFlag[i]==0)
                {
                    horizontalR[i]=0;
                }
                horizontalFlag[i]=1;
                if (verticalFlag[j]==0)
                {
                    verticalR[j]=0;
                }
                verticalFlag[j]=1;
                if (piediagonalFlag[i+j]==0)
                {
                    piediagonalR[i+j]=0;
                }
                piediagonalFlag[i+j]=1;
                if (nadiagonalFlag[i-j]==0)
                {
                    nadiagonalR[i-j]=0;
                }
                nadiagonalFlag[i-j]=1;
                
                if (flag&&(horizontalB[i]>=N||verticalB[j]>=N||piediagonalB[i+j]>=N||nadiagonalB[i-j]>=N))
                {
                    cout<<"BLUE WINS"<<endl;
                    //cout<<horizontalB[i]<<" "<<verticalB[j]<<" "<<piediagonalB[i+j]<<" "<<nadiagonalB[i+j]<<endl;
                    flag=false;
            }
            
        }
    }
    }
    if (flag) cout<<"NONE"<<endl;
    return 0;
}

/*
 总结：
 1.七皇后问题延伸版本
 2. 注意： 在不同线上要考虑相销问题，可能是连续可能是间隔， 也可能只是出现
 3. 考虑清楚每条线取值，一般撇为i+j因此是[0,2n]，捺为i-j因此为[-n,n]
 */
