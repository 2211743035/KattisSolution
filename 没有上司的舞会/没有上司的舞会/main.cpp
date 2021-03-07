//
//  main.cpp
//  没有上司的舞会
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> aL;
vector<int> happiness;
int Hp[10000][2];
void dfs(int u, int pre)
{
    Hp[u][0]=0;
    Hp[u][1]=happiness[u];
    int si = (int)aL[u].size();
    for (int i=0; i<si;i++)
    {
        int v= aL[u][i];
        if (v==pre) continue;
        dfs(v,u);
        Hp[u][0]+=max(Hp[v][0],Hp[v][1]);
        Hp[u][1]+=Hp[v][0];
    }
}
int du[10000];
int main()
{
    int n;
    cin>>n;
    int temp;
    happiness.reserve(n);
    aL.reserve(n+10);
    for (int i=0;i<n+10;i++)
    {
        aL[i].reserve(n);
    }
    for (int i=1; i<n; i++)
    {
    
        cin>>temp;
        happiness[i]=temp;
    }
    int temp1, temp2;
    for (int i=2;i<=n;i++)
    {
        cin>>temp1>>temp2;
        aL[temp2].push_back(temp1);
        du[temp1]++;
    }
    int start=0;
    for (int i =1; i<=n; i++)
    {
        if(du[i]==0)
        {
            start=i;
            break;
        }
    }
    dfs(start,-1);
    cout<<max(Hp[start][0],Hp[start][1])<<"\n";
    return 0;
}








/*
#include <iostream>
#include<map>
#include<set>
//#include<vector>
using namespace std;
map<int,int> available;

int dfs(int x,int const n, map<int,int> adjacency, map<int, int> happiness,int happy)
{
    
    if (x>=n) return happy;
    int max_happy=happy;
    for (int i=1; i<=n; i++)
    {
        if (available[i]==true)
        {
            //unwanted.insert(adjacency[i]);
            //unwanted.insert(i);
            available[i]=false;
            available[adjacency[i]]=false;
            x++;
            happy+=happiness[i];
            //cout<<happy<<endl;
            max_happy=happy>max_happy ? happy:max_happy;
            int over=dfs(x,n,adjacency, happiness,happy);
            max_happy=over>max_happy? over:max_happy;
            happy-=happiness[i];
            x--;
            //unwanted.erase(adjacency[i]);
            //unwanted.erase(i);
            available[i]=true;
            available[adjacency[i]]=true;
        }
        else continue;
    }
    //cout<<max_happy<<endl;
    return max_happy;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin>>N;
    map<int,int> happiness, adjacency;
    for (int i=0; i<=N; i++) adjacency[i]=0;
    for (int i=0; i<=N; i++) available[i]=true;
    int temp1,temp2;
    for (int i=1; i<=N;i++)
    {
        cin>>temp1;
        happiness[i]=temp1;
        //cout<<happiness[i]<<endl;
        
    }
    for (int i=2; i<=N;i++)
    {
        cin>>temp1>>temp2;
        adjacency[temp1]=temp2;
        //cout<<temp1<<" "<<temp2;
    }
    
    int output=dfs(0,N,adjacency, happiness, 0);
    cout<<output<<endl;
    
    return 0;
}
*/
