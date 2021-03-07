//
//  main.cpp
//  hardQ
//
//  Created by mcr on 2/11/2020.
//

#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <algorithm>

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
bool visited[1000];
int inDegree[1000];
vector<int> top;
int cnt[1000];
int ans;

bool check(int x) {
    vis[x] = -1;
    for (auto i = D[x].cbegin(); i != D[x].cend(); )
    {
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

void gettop() {
    for (int i = 0; i < N; i++)
        for (const auto& j : G[i])
            inDegree[j.first.first]++;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        top.push_back(x);
        for (const auto& i : G[x]) {
            int y = i.first.first;
            if (!--inDegree[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

void getans() {
    for (int i = 0; i < N; i++)
        cnt[i] = 0;
    cnt[0] = 1;
    for (const auto& i : top) {
        for (const auto& j : G[i]) {
            if (j.second) {
                int to = j.first.first;
                cnt[to] = (cnt[to] + 1LL * j.first.second * cnt[i]) % M;
            }
        }
        ans = (ans + cnt[i]) % M;
    }
}

int main() {
    rd(N, M);
    for (int i = 0; i < N; i++) {
        int C;
        for (rd(C); C--; ) {
            int x;
            rd(x);
            D[i].push_back(x);
        }
        sort(D[i].begin(), D[i].end());
    }
    for (rd(Q, T); Q--; ) {
        Y.emplace_back();
        int X;
        for (rd(X); X--; ) {
            int x;
            rd(x);
            Y.back().push_back(x);
        }
    }
    if (!check(0))
        printf("Invalid\n");
    else {
        if (T == 0) {
            gettop();
            flush();
            for (int i = 0; i < N; i++)
                for (auto& j : G[i])
                    j.second = true;
            getans();
            printf("%d\n", ans % M);
            for (const auto& i : Y) {
                bool flag = false;
                for (const auto& j : i)
                    if (vis[j])
                        flag = true;
                if (!flag) {
                    printf("%d\n", 0);
                    continue;
                }
                flush();
                for (const auto& j : i)
                    goal[j] = true;
                dfs1(0);
                dfs2(1000);
                for (int j = 0; j < N; j++)
                    for (const auto& k : invG[j])
                        if (k.second)
                            to[k.first.first].push_back(j);
                for (int j = 0; j < N; j++) {
                    sort(to[j].begin(), to[j].end());
                    auto it = G[j].begin();
                    for (const auto& k : to[j]) {
                        while (it->first.first != k)
                            it++;
                        it->second = true;
                    }
                }
                for (int j = 0; j < N; j++)
                    to[j].clear();
                getans();
                printf("%d\n", ans % M);
            }
        }
        else
            printf("Valid\n");
    }
    return 0;
}
