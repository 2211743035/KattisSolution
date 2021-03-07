//
//  main.cpp
//  Kattis_Pivot
//
//  Created by mcr on 17/10/2020.
//

#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> initialLis(n);
    set<int> sortedLis, beforeLis;
    int dig;
    for (int i=0;i<n;i++)
    {
        cin>>dig;
        initialLis[i]=dig;
        sortedLis.insert(dig);
        
    }

    int output=0;
    
    for (int i=0;i<n;i++)
    {
        sortedLis.erase(initialLis[i]);
        if (sortedLis.upper_bound(initialLis[i])==sortedLis.begin() && beforeLis.upper_bound(initialLis[i])==beforeLis.end())
        {
            output++;
        }
        beforeLis.insert(initialLis[i]);
    }

    cout<<output<<"\n";
    return 0;
}

/*
 总结：
 1. set的upper_bound 返回first >输入值（输入值后优先级下一位的first element)的pointer；
 2. 利用set可以判断前方元素是否都比后方小,具体思想分两部分:
        a. 如果在一个排序set中, upper_bound(val) 返回的是set的begin,说明剩下set中所有元素一定比val大
        b. 如果一个排序set中, upper_bound(val) 返回的是set的end, 说明set中所有元素一定比val小
 3. 讨论: 除了set是否能用其他数据结构： eg. priority_queue（不好erase),可以用map做lazy delete, 一个大顶一个小顶堆来写
 4. set idea reference from： https://repl.it/@lyc/Kattis-Pivot#main.cpp
 */
