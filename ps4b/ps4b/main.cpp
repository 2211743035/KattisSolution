//
//  main.cpp
//  ps4b
//
//  Created by mcr on 10/10/2020.
//

#include <iostream>
#include <queue>
#include<vector>
#include<utility>
using namespace std;
pair<int,int>moves[8]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
inline int trans(char a)
{
    if (a=='.')
    {
        return 0;
    }
    if (a=='#')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

 bool check(pair<int, int>& x,int N,vector<vector<int> > &mp) {
    if (x.first < 0 || x.second < 0 || x.first >= N || x.second >= N )
        return false;
    if (mp[x.first][x.second] == -1)
        return false;
    if (mp[x.first][x.second] == 0 || mp[x.first][x.second] == -2)
        return true;
    return false;
    

}
/*
int move_step(int matrix[], int step, int currRow, int currColum, int rowMov,int colMov)
{
    
    matrix[currRow+rowMov][currRow]
}
 */

 void bfs(queue<pair<int, int> >& q1,vector<vector<int> > &mp,int N) {
     int ans = 1;
     while (!q1.empty()) {
         queue<pair<int, int> >q2;
         while (!q1.empty()) {
             pair<int, int> top = q1.front(); q1.pop();
             for(auto c:moves){
                         pair<int, int> n(top.first + c.first, top.second + c.second);
                         if (check(n,N,mp)) {
                             if (mp[n.first][n.second] == -2) {
                                 cout << ans << endl;
                                 return;
                             }
                             mp[n.first][n.second] = ans;
                             q2.push(n);
                         }
                     }
         }
         ans++;
         q1 = q2;
     }
     cout << -1 << endl;
 }

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio();
    int N;
    cin>>N;
    
    string rows;
    //int matrix[N][N];
    vector<vector<int> > matrix;
            matrix.resize(N);//r行
            for (int k = 0; k < N; ++k){
                matrix[k].resize(N);//每行为c列
            }
    queue<pair<int, int> > q;
    for (int i=0; i<N; i++)
    {
        cin>>rows;
        for (int j=0; j<N;j++)
        {
            
            int note=trans(rows[j]);
            matrix[i][j]=note;
            if (note==1)
            {
                q.push({ i,j });
            }
        }
        
    }
    
    if (matrix[0][0]==1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    matrix[0][0]=-2;
    bfs( q,matrix, N);
    
    
    return 0;
}
