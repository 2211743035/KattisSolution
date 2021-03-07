// Example program
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include<queue>
#include<vector>
#include<utility>
#include<string>
#include<sstream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ask_price;
  priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> bid_price;
  string temp;
  cin.ignore();
  queue<string> output;
  for (int  i=0;i<n;i++)
  {
      getline(cin,temp);
      istringstream ss(temp);
      string order_type,useless,xS,yS;
      int x,y;
      ss>>order_type>>xS>>useless>>useless>>yS;
      //cout<<order_type<<" "<<xS<<" "<<yS<<endl;
      x=stoi(xS);
      y=stoi(yS);
      //cout<<x<<" "<<y<<endl;
      if (order_type=="sell")
      {
          ask_price.push(make_pair(y,x));
      }
      else
      {
          bid_price.push(make_pair(y,x));
      }
      string askP="-",bidP="-", stockP="-";
      while(!bid_price.empty()&& !ask_price.empty()&&bid_price.top().first>=ask_price.top().first)
      {
          if (bid_price.top().second>ask_price.top().second)
          {
              stockP=to_string(ask_price.top().first);
              int price=bid_price.top().first, num=bid_price.top().second-ask_price.top().second;
              ask_price.pop();
              bid_price.pop();
              bid_price.push(make_pair(price,num));
              
          }
          
          else if (bid_price.top().second<ask_price.top().second)
          {
              stockP=to_string(ask_price.top().first);

              int price=ask_price.top().first, num=ask_price.top().second-bid_price.top().second;
              bid_price.pop();
              ask_price.pop();
              ask_price.push(make_pair(price,num));
              
          }
          
          else
          {
              stockP=to_string(ask_price.top().first);
              ask_price.pop();
              //int price=bid_price.top().first, num=bid_price.top().second;
              bid_price.pop();
          }
              
              
      }
      if (!ask_price.empty()) askP= to_string(ask_price.top().first);
      else askP="-";
      if (!bid_price.empty()) bidP=to_string(bid_price.top().first);
      else bidP="-";
      string out;
      out=askP+" "+bidP+" "+stockP;
      cout<<out<<endl;
      //output.push(out);
      
  }

  /*
  while(!output.empty())
  {
     cout<<output.front()<<endl;
     output.pop();
  }
    */
  }
    return 0;
}
