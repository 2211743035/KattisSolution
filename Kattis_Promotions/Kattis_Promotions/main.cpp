
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
# include <string.h>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<list>
#include<unordered_set>
#include<unordered_map>


#include<utility>
#include<tuple>

#include<algorithm>



using namespace std;

void getleastabove(queue<int> zeroin, vector<int> deg, vector<int>& leastabove, vector<vector<int>>& chi, vector<vector<int>>& par, int skip, int e) {
    vector<int> vis(e, false);
    queue<int> q;
    q.push(skip);
    vis[skip] = true;

    int above = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto next : par[curr]) {
            if(!vis[next]) {
                above++;
                vis[next] = true;
                q.push(next);
            }
        }
    }

    leastabove[skip] = above;
}

void getmostabove(queue<int> zeroin, vector<int> deg, vector<int>& mostabove, vector<vector<int>>& chi, vector<vector<int>>& par, int skip, int e) {
    int processed = 0;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        if(curr == skip) {
            continue;
        }
        processed++;

        // Process children
        for(auto next : chi[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                zeroin.push(next);
            }
        }
    }

    mostabove[skip] = processed;
}

int main() {
    int a, b, p, e;
    cin >> a >> b >> e >> p;

    vector<vector<int>> chi(e);
    vector<vector<int>> par(e);
    vector<int> deg(e, 0);
    vector<int> leastabove(e, 0);
    vector<int> mostabove(e, 0);

    for(int i = 0; i < p; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        chi[n1].push_back(n2);
        par[n2].push_back(n1);

        deg[n2]++;
    }

    queue<int> zeroin;
    for(int i = 0; i < e; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    for(int i = 0; i < e; i++) {
        getleastabove(zeroin, deg, leastabove, chi, par, i, e);
        getmostabove(zeroin, deg, mostabove, chi, par, i, e);
    }

    int guaranteed1 = 0;
    int guaranteed2 = 0;
    int impossible = 0;
    for(int i = 0; i < e; i++) {
        if(mostabove[i] < a) {
            
            guaranteed1++;
        }
        //cout<<i<<" leastabove: "<<leastabove[i]<<endl;
        //cout<<i<<" mostabove: "<<mostabove[i]<<endl;
        if(mostabove[i] < b) {
            //cout<<i<<" let me see "<<mostabove[i]<<endl;
            guaranteed2++;
        }
        if(leastabove[i] >= b) {
            impossible++;
        }
    }

    cout << guaranteed1 << endl;
    cout << guaranteed2 << endl;
    cout << impossible << endl;
}



/*
 copied from:https://github.com/mpfeifer1/Kattis/blob/master/promotions.cpp
 总结：
 1. 不连接的subgraph间无法直接比较,所以需要有mostabove(在connected graph中比自己大的）和leastabove(和自己connected graph的数量总和)
 2. 题目没说connected时一定要注意！！！！
 3. graph不完全connected的题数量比较时要考虑most above和least above
 */


