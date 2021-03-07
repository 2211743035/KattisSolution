//
//  main.cpp
//  Kattis_2048
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include<map>
using namespace std;
int matrix[4][4];
int main(int argc, const char * argv[]) {
    map<int, bool> merged;
    for (int i=0; i<4;i++)
    {
        for (int j=0; j<4; j++)
        {
            merged[i*5+j]=1;
        }
    }
    for (int i=0;i<4;i++)
    {
        for (int j=0; j<4; j++) cin>>matrix[i][j];
    }
    int N;
    cin>>N;
    if (N==0)
    {
        for (int i=0; i<4; i++)
        {
            //bool unmerge=true;
            for (int j=1;j<4;j++)
            {
                if (matrix[i][j]==0) continue;
                else
                {
                    int t=j;
                    while (t>0 && matrix[i][t-1]==0)
                    {
                        matrix[i][t-1]=matrix[i][t];
                        matrix[i][t]=0;
                        t=t-1;
                    }
                    if (t>0 && matrix[i][t-1]==matrix[i][t] && merged[i*5+t-1])
                    {
                        matrix[i][t-1]*=2;
                        matrix[i][t]=0;
                        //unmerge=false;
                        merged[i*5+t-1]=0;
                    }
                    
                }
            }
        }
    }
    else if (N==2)
    {
        for (int i=0; i<4; i++)
        {
            //bool unmerge=true;
            for (int j=2;j>=0;j--)
            {
                if (matrix[i][j]==0) continue;
                else
                {
                    int t=j;
                    while (t<3 && matrix[i][t+1]==0)
                    {
                        matrix[i][t+1]=matrix[i][t];
                        matrix[i][t]=0;
                        t=t+1;
                    }
                    if (t<3 && matrix[i][t+1]==matrix[i][t] && merged[i*5+t+1])
                    {
                        matrix[i][t+1]*=2;
                        matrix[i][t]=0;
                        //unmerge=false;
                        merged[i*5+t+1]=0;
                    }
                    
                }
            }
        }
    }
    else if (N==3)
    {
        for (int j=0; j<4; j++)
        {
            //bool unmerge=true;
            for (int i=2;i>=0;i--)
            {
                if (matrix[i][j]==0) continue;
                else
                {
                    int t=i;
                    while (t<3 && matrix[t+1][j]==0)
                    {
                        matrix[t+1][j]=matrix[t][j];
                        matrix[t][j]=0;
                        t=t+1;
                    }
                    if (t<3 && matrix[t+1][j]==matrix[t][j] && merged[t*5+j+5])
                    {
                        matrix[t+1][j]*=2;
                        matrix[t][j]=0;
                        //unmerge=false;
                        merged[t*5+j+5]=0;
                    }
                    
                }
            }
        }
    }
    else
    {
        for (int j=0; j<4; j++)
        {
            //bool unmerge=true;
            for (int i=1;i<4;i++)
            {
                if (matrix[i][j]==0) continue;
                else
                {
                    int t=i;
                    while (t>0 && matrix[t-1][j]==0)
                    {
                        matrix[t-1][j]=matrix[t][j];
                        matrix[t][j]=0;
                        t=t-1;
                    }
                    if (t>0 && matrix[t-1][j]==matrix[t][j] && merged[t*5+j-5])
                    {
                        matrix[t-1][j]*=2;
                        matrix[t][j]=0;
                        //unmerge=false;
                        merged[t*5+j-5]=0;
                    }
                    
                }
            }
        }
    }
    for (int i=0;i<4;i++)
    {
        for (int j=0; j<4; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
 总结：
 1. hash表把二维hash一维,用的进位比边长大1
 2. 细节shift时除了新的位置赋老位置的值,还要把老位置的值清零
 3. 表不大知道大小用array
 */
