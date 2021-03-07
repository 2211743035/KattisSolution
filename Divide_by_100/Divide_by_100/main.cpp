//
//  main.cpp
//  Divide_by_100
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include<stack>
#include <vector>
#include<string>
#include<sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string N,M;
    cin>>N>>M;
    istringstream ss(N);
    stack<char> smaller;
    int lenM=(int) M.length()-1;
    int lenbigger=(int) N.length()-lenM;
    int lenN=(int) N.length();
    int zeroTail=0;
    if (lenN<=lenM)
    {
        cout<<"0.";
        int zeros=lenM-lenN;
        for (int i=0;i<zeros;i++) cout<<'0';
        for (int i=lenN-1; i>0; i--)
        {
            if (N[i] =='0') zeroTail++;
            else break;
        }
        char c;
        int i=0;
        while(ss>>c)
        {
            cout<<c;
            i++;
            if (i+zeroTail>=lenN) break;
        }
        cout<<"\n";
    }
    else
    {
    for (int i=lenN-1; i>=lenbigger; i--)
    {
        if (N[i] =='0') zeroTail++;
        else break;
    }
    //cout<<zeroTail<<endl;
    char c;
    int i=0;
    while(ss>>c)
    {
        cout<<c;
        i++;
        if (i+zeroTail>=lenN) break;
        if (i==lenbigger) cout<<'.';
    }
    cout<<"\n";
    }
    return 0;
}
/*
 需要注意的点
 1. 大数运算用字符串进位
 2. 要消除结尾的0，所以要实现统计
 3. 除数大于被除数时情况会不同，需先考虑在首个non-zero number前的0的个数，再计算N之后的trival zero， 把non-triaval char of N逐个打出
 */
