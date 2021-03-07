//
//  main.cpp
//  Kattis_Competitive Arcade Basketball
//
//  Created by mcr on 25/10/2020.
//

#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<iomanip>

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

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

/*
const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int numPlayer, threshold, round;
    bool flag=false;
    unordered_map<string, int> scoreRecord,win;
    cin>>numPlayer>>threshold>>round;
    for (int i=0; i<numPlayer;i++)
    {
        string name;
        cin>>name;
        scoreRecord[name]=0;
        win[name]=0;
    }
    for (int i=0; i<round; i++)
    {
        string name;
        int score;
        cin>>name>>score;
        scoreRecord[name]+=score;
        if ( win[name]==0 && scoreRecord[name]>=threshold)
        {
            flag=true;
            win[name]=1;
            cout<<name<<" wins!"<<endl;
        }
        
    }
    if (flag==false)
    {
        cout<<"No winner!"<<endl;
    }
    return 0;
}

/*
 总结：
 map, set, multimap, and multiset
 上述四种容器采用红黑树实现，红黑树是平衡二叉树的一种。不同操作的时间复杂度近似为:
 插入: O(logN)

 查看:O(logN)

 删除:O(logN)

 unordered_map, unordered_set, unordered_multimap,  unordered_multiset
 上述四种容器采用哈希表实现，不同操作的时间复杂度为：
 插入:O(1)，最坏情况O(N)。

 查看:O(1)，最坏情况O(N)。

 删除:O(1)，最坏情况O(N)。

 记住，如果你采用合适的哈希函数，你可能永远不会看到最坏情况。但是记住这一点是有必要的。
 
 所以如果不考虑有序的情况：
 unordered_set和unordered_map在hash好的情况访存效率更高
 */
