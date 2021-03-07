//
//  main.cpp
//  Kattis_Music Your Way
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include<vector>
#include<map>
#include<sstream>
#include <algorithm>
using namespace std;
int t;
bool cmp(const vector<string> & a, const vector<string> & b)
    {
        return a[t]<b[t];
    }

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    map<string,int> cmper;
    vector<string> fac(21);
    
    int n=0;
    string temp,word;
    getline(cin,temp);
    istringstream ss(temp);
    while (ss>>word)
    {
        fac[n]=word;
        cmper[word]=n++;
        
    }
    int N;
    cin>>N;
    cin.ignore();
    //vector<vector<string>> nameLis(N,vector<string> (20));
    vector<vector<string>> nameLis(N);
    //ss.clear();
    //ss.str("");
    vector<string> mod(n);
    nameLis.resize(N,mod);
    for (int j=0; j<N;j++)
    {
        nameLis[j].reserve(n+10);
        getline(cin,temp);
        //ss.str(temp);
        istringstream s2(temp);
        //cout<<temp;
        for (int i=0; i<n; i++)
        {
            string s;
            s2>>s;
            nameLis[j][i]=s;
            //cout<<nameLis[j][i];
            //cout<<s;
        }
    }
    
    int c;
    cin>>c;
    vector<int> stand(c+10);
    for (int i=0; i<c; i++)
    {
        cin>>temp;
        stand[i]=cmper[temp];
    }
    
    for (int i=0; i<c; i++)
    {
        t=stand[i];
        //t=0;
        stable_sort(nameLis.begin(), nameLis.end(),cmp);
        
        for (int i=0; i<n; i++)
        {
            cout<<fac[i]<<" ";
        }
        
        cout<<"\n";
        for (int i=0; i<N; i++)
        {
            
            for (int j=0; j<n; j++)
            {
                cout<<nameLis[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(i!=c-1)
        cout<<"\n";
    }
     
    
    
    
    return 0;
}


/*
 总结：
 1. 字符串流：每次使用用不同名字单独宣告，用完的字符串流用ss.str("");清空，
 2. 宣告二维vector： vector<vector<type>> V(M,vector<type> (N)) //M为外围大小,N为内vector大小
 */
