#include <iostream>
#include <unordered_map>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main() 
{
  int t;cin>>t;
  while(t>0)
  {
    int n,limit;cin>>n>>limit;
    int a[n],s[n];
    int shifts=0;
    unordered_map<int,int> nos;
    vector<int> moves;

    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      s[i]=a[i];
      nos.insert(pair<int,int>(a[i],i));
    }

    sort(s,s+n);
    
    for(int p=0;p<n;p++)
    {
      
      if(a[p]!=s[p])
      {
        int i=p;
        int j=nos.find(s[i])->second;
        int k=nos.find(s[j])->second;

        if(i<k&&k<j)
        {
          nos.find(a[i])->second=k;
          nos.find(a[k])->second=j;
          nos.find(a[j])->second=i;

          swap(a[k],a[j]);
          swap(a[i],a[k]);shifts++;
          moves.push_back(i);moves.push_back(k);moves.push_back(j);
        }
        else if(i<j&&j<k) 
        {
          nos.find(a[i])->second=j;
          nos.find(a[j])->second=k;
          nos.find(a[k])->second=i;

          swap(a[i],a[j]);
          swap(a[j],a[k]);
          shifts+=2;

          moves.push_back(i);
          moves.push_back(j);
          moves.push_back(k);
          moves.push_back(i);
          moves.push_back(j);
          moves.push_back(k);
          
        }

        else if(i==k){
          k++;
          
          while(k<n&&(a[k]==s[k]||k==j))
         { k++;}

          
          
          if(k==n)
          {
            cout<<-1;break;
          }
          
           if(i<k&&k<j)
        {
          nos.find(a[i])->second=k;
          nos.find(a[k])->second=j;
          nos.find(a[j])->second=i;
          swap(a[k],a[j]);
          swap(a[i],a[k]);shifts++;

          moves.push_back(i);moves.push_back(k);moves.push_back(j);
        }
        else if(i<j&&j<k) 
        {
          nos.find(a[i])->second=j;
          nos.find(a[j])->second=k;
          nos.find(a[k])->second=i;

          swap(a[i],a[j]);
          swap(a[j],a[k]);
          shifts+=2;

          moves.push_back(i);
          moves.push_back(j);
          moves.push_back(k);
          moves.push_back(i);
          moves.push_back(j);
          moves.push_back(k);

        }

        }

        
      if(shifts>limit) {cout<<-1<<"\n";break;}
      }
    }
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    
      for(auto it=moves.begin();it!=moves.end();it++)
      {
        cout<<*it<<" ";
        it++;
        cout<<*it<<" ";
        it++;
        cout<<*it<<" "<<"\n";
      }
    
    t--;
  }
}
