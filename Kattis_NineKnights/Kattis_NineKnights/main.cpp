//
//  main.cpp
//  Kattis_NineKnights
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include <map>

using namespace std;
map<int,int> influenced;

inline void record(int i,int j)
{
    influenced[(i-2)*10+j-1]+=1;
    influenced[(i-2)*10+j+1]+=1;
    influenced[(i-1)*10+j-2]+=1;
    influenced[(i-1)*10+j+2]+=1;
    influenced[(i+1)*10+j-2]+=1;
    influenced[(i+1)*10+j+2]+=1;
    influenced[(i+2)*10+j-1]+=1;
    influenced[(i+2)*10+j+1]+=1;
    return;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    bool flag=false;
    //for (int i=-13;i<38;i++) influenced[i]=0;
    for (int i=-1;i<=7;i++)
    {
        for (int j=-1; j<=7;j++)
        {
            influenced[i*10+j]=0;
        }
    }
    char temp;
    int count=0;
    for (int i=1; i<=5; i++)
    {
        for (int j=1;j<=5;j++)
        {
        cin>>temp;
        if (temp=='.') continue;
        else
        {
            count++;
            if (influenced[i*10+j]>0)
            {
                flag=true;
            }
            record(i,j);
        }
        }
    }
    /*
    for (int i=0; i<25; i++)
    {
        if (influenced[i]>1)
        {
            cout<<"invalid"<<"\n";
            return 0;
        }
    }
    */
    if (flag||count!=9) cout<<"invalid"<<"\n";
    else cout<<"valid"<<"\n";
    return 0;
}


/*
 总结：
 1. 二维矩阵还是要用两个坐标来表示
 2. 可以用一个索引， 但是要错位hash防止collision
 3. 思考，在本题中不一定要用10来错列， 但最少需要10进位，因为每行有五个元 素，因为表面表位5*5，边列各可向外延伸2个格，真实的矩阵是9*9， 要用一个坐标hash时就得用10进位才能保证行列分开

 */
