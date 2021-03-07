//
//  main.cpp
//  ImageProcessing
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
using namespace std;
int originalImage[20][20],kernel[20][20];
inline int convol( int i, int j, int N, int M)
{
    int output=0;
    for (int t=0; t<N; t++)
    {
        for (int d=0; d<M; d++)
        {
            output+=originalImage[i+t][j+d]*kernel[t][d];
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int H,W,N,M;
    cin>>H>>W>>N>>M;
    for (int i=0; i<H;i++)
    {
        for (int j=0; j<W;j++)
        {
            cin>>originalImage[i][j];
        }
    }
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M;j++)
        {
            cin>>kernel[N-1-i][M-1-j];
        }
    }
    int oH=H+1-N,oW=W+1-M;
    for (int i=0; i<oH; i++)
    {
        for (int j=0; j<oW; j++)
        {
            cout<<convol( i, j, N, M)<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
