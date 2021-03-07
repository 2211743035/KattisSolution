//
//  main.cpp
//  Kattis_What_does_the_fox_say
//
//  Created by mcr on 14/10/2020.
//

#include <iostream>
#include <set>
#include<string>
#include<queue>
#include<sstream>
using namespace std;
int main(int argc, const char * argv[]) {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    cin.ignore();
    while (N--)
    {
        string wordRecord;
        set<string> words;
        vector<string> origin;
        getline(cin,wordRecord);
        /*
        
        for (auto c: wordRecord)
        {
            
            if (c<'a' || c>'z')
            {
                
                //words.insert(word);
                //cout<<word<<endl;
                origin.push_back(word);
                word="";
            }
            else
            {
                word+=c;
            }
        }
        origin.push_back(word);
         */
        istringstream iss(wordRecord);
        string word;
        while(iss>>word)origin.push_back(word);

        while(1)
        {
            getline(cin, word);
            
            if (word=="what does the fox say?") break;
            /*
            if (word1=="what" && word2=="does" && word3=="the")
            {
                getline(cin, word);
                
                cin>>word1>>word2;
                break;
            }
             */
            else
            {
                string word1, word2,word3;
                istringstream iss(word);
                iss>>word1>>word2>>word3;
                words.insert(word3);
                cin>>word1>>word2>>word3;
                //cout<<word3;
            }
            
        }
        //cout<<wordRecord;
        string wo;
        bool flag=false;
        for (auto wo: origin)
        {
            if (!words.count(wo) )
            {
                if (flag) cout<<" ";
                cout<<wo;
                flag=true;
            }
        }
        cout<<"\n";
    }
    return 0;
}
