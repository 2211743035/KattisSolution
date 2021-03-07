//
//  main.cpp
//  Kattis_FlagQuiz
//
//  Created by mcr on 18/10/2020.
//

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include<vector>
using namespace std;
int elements[100][100];
int difference[100][100];
map<int,string> decoder;
map<string, int> incoder;
int output[100][2];

inline void updata_output(int max_val,int max_ind, int &numMax )
{
    if (max_val==output[numMax-1][0])
    {
        output[numMax][0]=max_val;
        output[numMax][1]=max_ind;
        numMax++;
        return;
    }
    else
    {
        output[0][0]=max_val;
        output[0][1]=max_ind;
        numMax=1;
    }
}
inline int encoder(int &i,string word)
{
    if (incoder.count(word)>0) return incoder[word];
    else
    {
        incoder[word]=i;
        decoder[i]=word;
        i=i+1;
        return i-1;
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    string temp;
    int N;
    getline(cin,temp);
    cin>>N;
    //elements[100].reserve(N);
    cin.ignore();
    int index=0,n=0;
    for (int i=0; i<N; i++)
    {
        int t=0;
        getline(cin, temp);
        //cout<<temp<<endl;
        istringstream ss(temp);
        
        string word;
        /*
        for (auto c: temp)
        {
            if (c==' ')
            {
                elements[i][t++]=encoder(index,temp);
                temp="";
            }
            //else if (c==' ' ) continue;
            else temp+=c;
        }
         
        elements[i][t++]=encoder(index,temp);
        n=t;
        temp="";
        */
        while(getline (ss,word,','))
        {
            //cout<<word<<endl;;
            elements[i][t++]=encoder(index,word);
            //cout<<word<<" ";
            
        }
        n=t;
    }
    /*
    for (int i=0;i<N;i++)
    {
        for (int j=0; j<n;j++)
        cout<<decoder[elements[i][j]]<<", ";
        cout<<"\n";
        
    }
     */
    int minRow=0, minVal=10000,numMin=0;
    for (int i=0; i<N; i++)
    {
        int Max=0;
        for (int j=0; j<N; j++)
        {
            if (i==j) continue;
            else
            {
                int sum=0;
                for (int t=0;t<n;t++)
                {
                    if (elements[i][t]-elements[j][t]==0) continue;
                    else sum++;
                }
                Max=max(Max,sum);
                
            }
        }
        if (Max<=minVal)
        {
            minVal=Max;
            minRow=i;
            updata_output(minVal, i, numMin);
        }
    }
    
    bool firstV=false;
    for (int j=0; j<numMin;j++)
    {
    for(int i=0;i<n; i++)
    {
        
        if (firstV) cout<<",";
        cout<<decoder[elements[output[j][1]][i]];
        //cout<<elements[output[j][1]][i];
        firstV=true;
    }
        //cout<<output[j][0];
    firstV=false;
        cout<<"\n";
        
    }
    //cout<<"\n";
}

/*
 总结：
 1. 遇到频繁比较字符串的情况可以考虑将字符串on-hot编码，用两个map
 2. 看清输入和输出！！
 3. 看清比较的条件！！
 */
