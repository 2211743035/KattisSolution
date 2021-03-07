//
//  main.cpp
//  Kattis_DisastrousDowntime_1011
//
//  Created by mcr on 12/10/2020.
//

#include <iostream>
#include<queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,K,tim,serverNum=1;
    cin>>N>>K;
    queue<int> processing;
    while(N--)
    {
        cin>>tim;
        if (processing.empty())
        {processing.push(tim);
            continue;}
        else if (processing.size()>=K*serverNum)
            {
                
                if (processing.front()+1000>tim)
                {
                    serverNum++;
                    processing.push(tim);
                }
                else
                {
                    while(!processing.empty() &&processing.front()+1000<=tim)
                    processing.pop();
                    processing.push(tim);
                }
            }
        else
        {
            processing.push(tim);
        }
        
        
    }
    
    cout<<serverNum<<"\n";
    return 0;
}
