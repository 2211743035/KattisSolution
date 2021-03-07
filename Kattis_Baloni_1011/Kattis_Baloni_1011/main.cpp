//
//  main.cpp
//  Kattis_Baloni_1011
//
//  Created by mcr on 12/10/2020.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> ballons(N);
    for (int i=0;i<N;i++)
    {
        cin>>ballons[i];
    }
    int totalArrow=0;
    for (int i=0; i<N; i++)
    {
        if (ballons[i]==-1) continue;
        int pos=i;
        int height=ballons[i];
        totalArrow++;
        while(pos<N)
        {
            if(height==ballons[pos])
            {
                ballons[pos]=-1;
                height--;
            }
            pos++;
        }
    }
    //O(N^2)
    cout<<totalArrow<<"\n";
    return 0;
}
