//
//  main.cpp
//  Kattis_Continuous Median
//
//  Created by mcr on 26/10/2020.
//

#include <iostream>
#include<queue>
using namespace std;
#define ll long long
//void biInsert(vector<int> numLis, int num)

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N, median,leftSize=0,rightSize=0;
        ll sum=0;
        cin>>N;
        priority_queue<int> smaller_half;
        priority_queue<int, vector<int>, greater<int> > bigger_half;
        for (int i=0; i<N;i++)
        {
            int temp;
            cin>>temp;
            if (smaller_half.empty())
            {
                smaller_half.push(temp);
                leftSize++;
                sum+=temp;
                continue;
                
            }
            else if (bigger_half.empty())
            {
                if (temp<smaller_half.top())
                {
                    smaller_half.push(temp);
                    temp=smaller_half.top();
                    bigger_half.push(temp);
                    smaller_half.pop();
                    rightSize++;
                    
                }
                else{
                bigger_half.push(temp);
                rightSize++;
                }
                median=(smaller_half.top()+bigger_half.top())/2;
                sum+=median;
                continue;
            }
            else
            {
                if (temp<=smaller_half.top())
                {
                    smaller_half.push(temp);
                    leftSize++;
                }
                else
                {
                    bigger_half.push(temp);
                    rightSize++;
                }
                
            }
            while ((rightSize-leftSize>0))
            {
                temp=bigger_half.top();
                smaller_half.push(temp);
                leftSize++;
                bigger_half.pop();
                rightSize--;
            }
            while ((leftSize-rightSize>1))
            {
                temp=smaller_half.top();
                bigger_half.push(temp);
                rightSize++;
                smaller_half.pop();
                leftSize--;
            }
            
            if ((leftSize+rightSize)&1)
            {
                median=smaller_half.top();
            }
            else
            {
                median=(smaller_half.top()+bigger_half.top())>>1;
            }
            sum+=median;
        }
        cout<<sum<<endl;
        
    }
}

/*
 总结：
 1. 用两个priority_queue一个大顶一个小顶不断调整
 2. 注意： 不能先只插入一边再向另一头移动， 一定要保证大顶最小的比小顶最大的大！！！！！
 */
