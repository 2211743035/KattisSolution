//
//  main.cpp
//  Kattis_JollyJumpers_1012
//
//  Created by mcr on 12/10/2020.
//

#include <iostream>
#include<string>
#include<queue>
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string str;
    int line=0;
    while(getline(cin,str))
    {
        if (cin.eof() || line>=10) break;
        else
        {
            int min=1,max=-1,N=-1, curr=0, pre=0,sign=0;
            str+=" ";
            int i;
            for (i=0;i<str.size();i++)
            {
                if (isdigit(str[i])) curr=curr*10+(int)(str[i]-48);
                else
                {
                    N=curr;
                    curr=0;
                    break;
                }
            }
            
            for (int j=i;j<str.size();j++)
            {
                if (isdigit(str[j])) curr=curr*10+(int)(str[j]-48);
                else if (str[i]=='-') sign=-1;
                else
                {
                    curr*=sign;
                    //cout<<curr<<endl;
                    if (sign)
                    {
                        if (abs(curr-pre)>max) max=abs(curr-pre);
                        if (curr==pre) min=0;
                    }
                    pre=curr;
                    curr=0;
                    sign=1;
                }
            }
            if (max<N && max>0 && min==1 && N>0) cout<<"Jolly"<<endl;
            else cout<<"Not jolly"<<endl;
        }
        line++;
    }
    /*
    queue<string> output;
    for (int i=0;i<10;i++)
    {
        int N;
        cin>>N;
        int min=1,max=-1, curr, pre;
        cin>>pre;
        for (int t=1; t<N;t++)
        {
            cin>>curr;
            if (abs(curr-pre)>max) max=abs(curr-pre);
            if (curr==pre) min=0;
            cout<<curr<<" ";
        }
        if (max<N && max>0 && min==1 && N>0) output.push("Jolly");
        else  output.push("Not jolly");
        cout<<endl;
    }
    while(!output.empty())
    {
        cout<<output.front()<<"\n";
        output.pop();
    }
     */
    return 0;
}
