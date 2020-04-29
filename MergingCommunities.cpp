#include <iostream>
#include <unordered_set>
#include<utility>
typedef long long int ll;
using namespace std;

class com{
    public:
    ll num;
    unordered_set<ll>*set;
};

int main() {
    ll n,q;cin>>n>>q;
    com people[n];
    for(ll i=0;i<n;i++)
    {
        people[i].num=i+1;
        people[i].set=new unordered_set<ll>;
        people[i].set->insert(i+1);
    }
    
    for(ll i=0;i<q;i++)
    {
        char query;cin>>query;
        if(query=='M')
        {
                ll a,b;cin>>a>>b;
                if(a==b) continue;
                
                unordered_set<ll>* set2=new unordered_set<ll>();
                set2->insert(people[a-1].set->cbegin(),people[a-1].set->cend());
                set2->insert(people[b-1].set->cbegin(),people[b-1].set->cend());
                
                for(auto k=set2->cbegin();k!=set2->cend();k++)
                {
                    people[*k-1].set=set2;
                }
             
            
        }
        
        else if(query=='Q')
        {
            ll a;
            cin>>a;
            cout<<people[a-1].set->size()<<"\n";
            
        }
            
    }
    
}
