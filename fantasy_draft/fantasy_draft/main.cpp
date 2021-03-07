//
//  main.cpp
//  fantasy_draft
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct preferenceLis
{
    string name;
    preferenceLis *next;
};


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<preferenceLis*> prefLiss(n);
    for(int i=0;i<n;i++)
    {
        prefLiss[i]=NULL;
    }
    int q;
    for (int i=0;i<n;i++)
    {
        cin>>q;
        string nam;
        preferenceLis *head=NULL;
        preferenceLis * curr=new preferenceLis;
        for (int j=0;j<q;j++)
        {
            cin>>nam;
            if (head==NULL)
            {
                
                curr->name=nam;
                head=curr;
            }
            else
            {
                preferenceLis * newEle=new preferenceLis;
                newEle->name=nam;
                curr->next=newEle;
                curr=newEle;
                curr->next=NULL;
            }
            
        }
        prefLiss[i]=head;
    }
    int p;
    cin>>p;
    map<string,bool> selectedName;
    queue<string> nameLis;
    string nam;
    for (int i=0;i<p;i++)
    {
        cin>>nam;
        selectedName[nam]=false;
        nameLis.push(nam);
    }
    vector<vector<string>> finalLis(n);
    for (int i=0;i<n;i++)
    {
        finalLis.reserve(k);
    }
    for (int t=0;t<k;t++)
    {
        for (int i=0; i< n; i++)
        {
            while(selectedName[nameLis.front()]==true)
            {
                nameLis.pop();
            }
            if (nameLis.empty()) break;
            while(prefLiss[i]!=NULL&& selectedName[prefLiss[i]->name])
                {
                    prefLiss[i]=prefLiss[i]->next;
                }
            if (prefLiss[i]==NULL)
            {
                selectedName[nameLis.front()]=true;
                finalLis[i].push_back(nameLis.front());
                nameLis.pop();
            }
            else
            {
                selectedName[prefLiss[i]->name]=true;
                finalLis[i].push_back(prefLiss[i]->name);
                prefLiss[i]=prefLiss[i]->next;
            }
            
        
        }
    }
    for (int i=0; i<n;i++)
    {
        for(vector<string>::iterator it=finalLis[i].begin();it!=finalLis[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
