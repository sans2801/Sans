#include <iostream>
#include<list>
using namespace std;
int main()
{
  long t;cin>>t;
  while(t>0)
  {
    long n;cin>>n;long a[n];list<long> eve;long u=(n*(n+1))/2,del=0;
    for(long i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]%2==0&&a[i]%4!=0){eve.push_back(i);}
    }
    while(!eve.empty())
    {
      long i=eve.front();eve.pop_front();
      long j=i;long k=i;
      while(true)
      { long j1=j, k1=k;
        if((a[j-1]%2!=0)&&j>0)j--;
        if(a[k+1]%2!=0&&k<n-1) k++;
        
        if(j1==j&&k1==k) break;
      }
     
    del=del+((i-j+1)*(k-i+1));
      
    }
    
cout<<u-del<<"\n";

    t--;
  }  
}