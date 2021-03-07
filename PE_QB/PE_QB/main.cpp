//u^D_m?_>dMCfBtY7FTBV:wdu=`T]wp..H;#BZZL`5,_H{#HNqW(KatTg(e~B/"Eh}~4kFK*dQ~T;6
//  main.cpp
//  PE_QB
//
//  Created by mcr on 28/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;

typedef pair<int, int> Pii;
typedef pair<Pii, bool> PP;

template<typename T>
inline void rd(T& x) {
    x = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) ;
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
}

template<typename T, typename... other>
inline void rd(T& x, other&... y) {
    rd(x);
    rd(y...);
}

int N, M;
vector<int> D[1000];
int Q, T;
vector<vector<int>> Y;
int vis[1000];
vector<PP> G[1000];
vector<PP> invG[1001];
vector<int> to[1000];
bool goal[1000];
int mem1[1000];
int mem2[1001];
int ans;

bool check(int x) {
    vis[x] = -1;
    for (auto i = D[x].cbegin(); i != D[x].cend(); ) {
        auto j = i;
        while (j != D[x].cend() && *i == *j)
            j++;
        G[x].emplace_back(Pii(*i, distance(i, j)), false);
        invG[*i].emplace_back(Pii(x, distance(i, j)), false);
        if (!~vis[*i] || !vis[*i] && !check(*i))
            return false;
        i = j;
    }
    if (G[x].empty())
        invG[1000].emplace_back(Pii(x, 0), false);
    vis[x] = 1;
    return true;
}

void flush() {
    for (int i = 0; i < N; i++) {
        for (auto& j : G[i])
            j.second = false;
        for (auto& j : invG[i])
            j.second = false;
        goal[i] = false;
        mem1[i] = mem2[i] = 0;
    }
    for (auto& i : invG[1000])
        i.second = false;
    mem2[1000] = 0;
    ans = 0;
}

bool dfs1(int x) {
    bool ret;
    if (mem1[x])
        ret = ~mem1[x];
    else {
        ret = goal[x];
        for (auto& i : G[x]) {
            if (dfs1(i.first.first)) {
                i.second = true;
                ret = true;
            }
        }
    }
    mem1[x] = ret ? 1 : -1;
    return ret;
}

bool dfs2(int x) {
    bool ret;
    if (mem2[x])
        ret = ~mem2[x];
    else {
        ret = goal[x];
        for (auto& i : invG[x]) {
            if (dfs2(i.first.first)) {
                i.second = true;
                ret = true;
            }
        }
    }
    mem2[x] = ret ? 1 : -1;
    return ret;
}

void dfs3(int x, int y) {
    for (const auto& i : G[x]) {
        if (i.second) {
            ans = (ans + 1LL * i.first.second * y) % M;
            dfs3(i.first.first, 1LL * i.first.second * y % M);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //rd(N, M);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        int C;
        cin>>C;
        for (int j=0; j<C; j++) {
            int x;
            //rd(x);
            cin>>x;
            D[i].push_back(x);
        }
        sort(D[i].begin(), D[i].end());
    }
    cin>>Q>>T;
    for (int i=0; i<Q;i++ ) {
        Y.emplace_back();
        int X;
        cin>>X;
        for (int j=0; j<X; j++) {
            int x;
            //rd(x);
            cin>>x;
            Y.back().push_back(x);
        }
    }
    if (!check(0))
        //printf("Invalid\n");
        cout<<"Invalid\n";
    else {
        if (T == 0) {
            flush();
            for (int i = 0; i < N; i++)
                for (auto& j : G[i])
                    j.second = true;
            dfs3(0, 1);
            ans++;
            cout<<ans % M<<endl;
            //printf("%d\n", ans % M);
            for (const auto& i : Y) {
                flush();
                for (const auto& j : i)
                    goal[j] = true;
                dfs1(0);
                dfs2(1000);
                for (int i = 0; i < N; i++)
                    for (const auto& j : invG[i])
                        if (j.second)
                            to[j.first.first].push_back(i);
                for (int i = 0; i < N; i++) {
                    sort(to[i].begin(), to[i].end());
                    auto it = G[i].begin();
                    for (const auto& j : to[i]) {
                        while (it->first.first != j)
                            it++; 
                        it->second = true;
                    }
                }
                for (int i = 0; i < N; i++)
                    to[i].clear();
                dfs3(0, 1);
                if (ans)
                    ans++;
                //printf("%d\n", ans % M);
                cout<<ans % M<<endl;
            }
        }
        else
            //printf("Valid\n");
            cout<<"Valid\n";
    }
    return 0;
}
