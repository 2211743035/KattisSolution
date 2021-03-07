//
//  main.cpp
//  cryp_2020_1216
//
//  Created by mcr on 16/12/2020.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    string painText;
    cin>>painText;
    int a=19990209,n=painText.length();
    int b=a;
    string output="";
    for (int i=0; i<n; i++)
    {
        char temp=painText[i]+a%7;
        output=output+temp;
        a/=7;
        if (a<=0) a=b;
    }
    cout<<output<<endl;
    return 0;
}
