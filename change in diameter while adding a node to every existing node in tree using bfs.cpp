#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    vector <vector <long>> a(n+1,vector <long>(0));
    
    for(long i=1;i<n;i++){
        long c,b;
        cin>>c>>b;
        a[b].push_back(c);
        a[c].push_back(b);
    }
    
    queue <long> q;
    vector <long> v(n+1,false);
    vector <long> d1(n+1,0);
    q.push(1);
    v[1]=true;
    d1[1]=0;
    
    while(!q.empty()){
        long f = q.front();
        q.pop();
        
        for(auto i:a[f]){
            if(!v[i]){
                q.push(i);
                v[i]=true;
                d1[i]=d1[f]+1;
            }
        }
    }
    
    long maxi=-1,ind=-1;
    for(long i=1;i<n+1;i++){
        if(d1[i]>maxi){
            maxi=d1[i];
            ind=i;
        }
    }
    
    for(long i=1;i<n+1;i++){
        v[i]=false;
        d1[i]=0;
    }
    
    q.push(ind);
    v[ind]=true;
    d1[ind]=0;
    
    while(!q.empty()){
        long f=q.front();
        q.pop();
        for(auto i:a[f]){
            if(!v[i]){
                v[i]=true;
                q.push(i);
                d1[i]=d1[f]+1;
            }
        }
    }
    
    maxi=-1, ind=-1;
    for(long i=1;i<n+1;i++){
        if(d1[i]>maxi){
            maxi=d1[i];
            ind=i;
        }
    }
    
    for(long i=1;i<n+1;i++){
        v[i]=false;
    }
    vector <long> d2(n+1,0);
    
    q.push(ind);
    v[ind]=true;
    d2[ind]=0;
    
    while(!q.empty()){
        long f=q.front();
        q.pop();
        for(auto i:a[f]){
            if(!v[i]){
                v[i]=true;
                q.push(i);
                d2[i]=d2[f]+1;
            }
        }
    }
    
    for(long i=1;i<n+1;i++){
        if(d1[i]==maxi || d2[i]==maxi){
            cout<<maxi+1<<"\n";
        }
        else{
            cout<<maxi<<"\n";
        }
    }
    
	return 0;
}
