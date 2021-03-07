
//  main.cpp
//  PE_QA
//
//  Created by mcr on 28/10/2020.
//


#pragma GCC optimize(3,"Ofast","inline")
//#include <bits/stdc++.h>
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
 struct node
 {
     
     int energy;
     int gold;
     node() {}
     node(int ener, int gol )
     {
         gold=gol;
         energy=ener;
     }
 };
 bool operator <(const node & left, const node & right)
 {
     if (left.energy==right.energy) return left.gold>right.gold;
     return left.energy>right.energy;
 }

*/
//vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<ll,ll>> >>facultyArea;
vector<vector<pair<ll,ll>>> facultyArea;
//vector<map<ll,pair<ll,ll>,less<ll>>> studentPos;
vector<vector<tuple<int,int,int>>> studentPos;
int facultyStudentNum[200],facultyT[200];
//vector<priority_queue<ll>> eachFacultyChoice;
vector<vector<ll>> eachFacultyChoice;
vector<bool> faculty(200, false);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll R;//𝑅  rows [1,E9]
    ll C;// COL [1,E9]
    int F;//𝐹  faculties [1,100]
    int S;//𝑆 students, [1,E5]
    int G;//There must be at least 𝐺 faculties with their compliance target met.
    cin>>R>>C>>F>>S>>G;
    
    facultyArea.resize(F+100);
    studentPos.resize(F+100);
    eachFacultyChoice.resize(F+100);
    
    for (int i=1; i<=F; i++)
    {
        
        int K;//1≤𝐾≤103
        
        facultyStudentNum[i]=0;
        facultyT[i]=0;
        cin>>K;
       
        ll a,b;
        for (int j=0; j<K; j++)
        {
            cin>>a>>b;
            facultyArea[i].push_back(make_pair(a,b));
        }
        
    }
    for (int i=0; i<S; i++)
    {
        int r,c,D,f;
        cin>>r>>c>>D>>f;
        if (f<=100)
        {
        facultyStudentNum[f]++;
        studentPos[f].push_back(make_tuple(D,r,c));
        }
    }
    for (int i=1; i<=F; i++)
    {
        //

        //vector<tuple<int,int,int>> sPos=studentPos[i];
        sort(studentPos[i].begin(), studentPos[i].end(),[] (tuple<int,int,int>  lef, tuple<int,int,int>   righ) {int a=get<0>(lef);int b=get<0> (righ); return a<b;});
        
        vector<tuple<int,int,int>>::iterator it=studentPos[i].begin();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > areaSequence{facultyArea[i].begin(),facultyArea[i].end()};
        while (it!=studentPos[i].end())
        {
           
            
            ll studentR,studentC;
            studentR=get<1>(*it);
            studentC=get<2>(*it);
            pair<ll,ll> targetPos=areaSequence.top();
            //cout<<areaSequence.size()<<endl;
            areaSequence.pop();
            //ll targetR=targetPos.first,targetC=targetPos.second;
            eachFacultyChoice[i].push_back(abs(targetPos.first-studentR)+abs(targetPos.second-studentC));
            //cout<<"haha "<<i<<" "<<studentR<<" "<<studentC<<" "<<targetR<<" "<<targetC<<" "<<abs(targetPos.first-studentR)+abs(targetPos.second-studentC)<<endl;
            it++;
    
        }
    }
    for (int i=1; i<=F; i++)
    {
        cin>>facultyT[i];
    }
    ll minimumMove=0;
    priority_queue<ll,vector<ll>,greater<ll>> choiceBetweenFaculty;
    for (int i=1; i<=F; i++)
    {
        ll minimumMoveinFaculty=0;
        int t=facultyT[i];
        priority_queue<ll,vector<ll>, greater<ll>> facultyChoice{eachFacultyChoice[i].begin(), eachFacultyChoice[i].end()};
        for (int j=0; j<t; j++)
        {
            if (!facultyChoice.empty())
            {
              
               minimumMoveinFaculty+=facultyChoice.top();
              facultyChoice.pop();
            }
        }
        choiceBetweenFaculty.push(minimumMoveinFaculty);
    }
    for (int i=0; i<G; i++)
    {
        minimumMove+=choiceBetweenFaculty.top();
        choiceBetweenFaculty.pop();
    }
    
    cout<<minimumMove<<endl;
    return 0;
}

/*
 shit, 
 */
