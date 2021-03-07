//
//  main.cpp
//  kattis_ps03
//
//  Created by mcr on 8/10/2020.
//

#include <iostream>
#include<map>
#include<queue>
#include<string>
#include<utility>
#define ll long long
using namespace std;
class BinaryHeap
{
private:
    map <string,int> fast_visit;
    vector<pair<string,int>>  bh;
    int nums;
    
public:
    BinaryHeap()
    {
        bh.reserve(100);
        nums=1;
        fast_visit.clear();
        
    }
    
    void reMod( int pos)
    {
        while (pos>=2&&((bh[pos].second>bh[pos>>1].second)|| ((bh[pos].second==bh[pos>>1].second)&&(bh[pos].first<bh[pos>>1].first))) )
        {
            swap(bh[pos],bh[pos>>1]);
            fast_visit[bh[pos].first]=pos>>1;
            fast_visit[bh[pos>>1].first]=pos;
            pos=pos>>1;
        }
    }
    
    void Delete(string name)
    {
        int pos=fast_visit[name];
        bh[pos]=make_pair(bh[pos].first,10000001);
        reMod( pos);
        ExtractMax();
        
    }
    void Insert(pair<string,int> v)
    {
        if (nums==1)
        {
            bh.push_back(v);
            nums++;
        }
        else
        {
            bh[nums++]=v;
            reMod(nums-1);
        }
    }
    
    bool sortFirst(pair<string,int> left, pair<string,int> right)
    {
        if (((left.second<right.second)|| ((left.second==right.second)&&(left.first>right.first)))) return 1;
        return 0;
    }
    
    void ExtractMax()
    {
        nums--;
        swap(bh[nums],bh[1]);
        int temp=1;
        while(sortFirst(bh[temp],bh[temp<<1])|| sortFirst(bh[temp],bh[(temp<<1)+1]))
        {
            
            if (sortFirst(bh[temp<<1],bh[(temp<<1)+1]) && ((temp<<1)+1)<nums)
            {
                fast_visit[bh[temp].first]=(temp<<1)+1;
                fast_visit[bh[(temp<<1)+1].first]=temp<<1;
                swap(bh[temp],bh[(temp<<1)+1] );
                temp=(temp<<1)+1;
            }
            else if (sortFirst(bh[(temp<<1)+1],bh[(temp<<1)]) && (temp<<1)<nums)
                
            {   fast_visit[bh[temp].first]=(temp<<1);
                fast_visit[bh[(temp<<1)].first]=temp<<1;
                swap(bh[temp],bh[(temp<<1)] );
                temp=(temp<<1);
            }
            else if ((bh[temp<<1]>bh[temp]) && (temp<<1)<nums)
            {
                swap(bh[temp],bh[(temp<<1)] );
                    temp=(temp<<1);
            }
            else break;
        }
        
    }
    
    string top_name()
    {
        if (nums!=1) return bh[1].first;
        else return "";
    }
    
    int top_server()
    {
        if (nums!=1) return bh[1].second;
        else return 10000001;
    }
    
    
    
    
    
};

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll N,K,Q,T,S;
    string M;
    cin>>N>>K;
    while(N--)
    {
        cin>>Q>>T;
        if (Q==1)
        {
            cin>>M>>S;
        }
        else if (Q==2)
        {
            
        }
        else if (Q==3)
        {
            cin>>M;
        }
        
        
    }
    return 0;
}
