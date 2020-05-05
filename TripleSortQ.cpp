#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<utility>
#include<vector>
typedef long long int ll;
using namespace std;
int main() 
{
  int t;cin>>t;
  while(t>0)
  {
    ll n,limit;cin>>n>>limit;
    ll a[n],s[n];
    ll shifts=0;
    unordered_map<ll,ll> nos;
    vector<ll> moves;
    bool np=true;

    for(ll i=0;i<n;i++)
    {
      cin>>a[i];
      s[i]=a[i];
      nos.insert(pair<ll,ll>(a[i],i));
    }

    sort(s,s+n);
    
    for(ll p=0;p<n;p++)
    {
      
      if(a[p]!=s[p])
      {
        ll i=p;
        ll j=nos.find(s[i])->second;
        ll k=nos.find(s[j])->second;

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
          nos.find(a[i])->second=k;
          nos.find(a[k])->second=j;
          nos.find(a[j])->second=i;

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
            cout<<-1<<"\n";
            np=false;
            break;
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
          nos.find(a[i])->second=k;
          nos.find(a[k])->second=j;
          nos.find(a[j])->second=i;

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

        
      if(shifts>limit) {cout<<-1<<"\n";np=false;break;}
      }
    }
    
      if(np)
    {
    	cout<<shifts<<"\n";
      for(auto it=moves.begin();it!=moves.end();it++)
      {
        cout<<*it+1<<" ";
        it++;
        cout<<*it+1<<" ";
        it++;
        cout<<*it+1<<" "<<"\n";
      }
      
      }

      cout<<"\n";
    
    t--;
  }
}
