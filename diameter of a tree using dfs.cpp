#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    vector <vector <long>> a(n+1,vector <long> (0));
    
    for(long i=0;i<n-1;i++){
        long nd,c;
        cin>>nd>>c;
        a[nd].push_back(c);
        a[c].push_back(nd);
    }
    
    vector <long> d(n+1,0);
    vector <bool> v(n+1,false);
    stack <long> s;
    
    //starting b fs from 1
    s.push(1);
    v[1]=true;
    d[1]=0;
    
    while(!s.empty()){
        long f = s.top();
        s.pop();
        
        for(auto i: a[f]){
            if(!v[i]){
                d[i] = d[f]+1;
                s.push(i);
                v[i]=true;
            }
        }
    }
    
    long max = -1, ind = -1;
    for(long i=1;i<n+1;i++){
        if(d[i]>max){
            max = d[i];
            ind = i;
        }
    }
    
    for(long i=1;i<n+1;i++){
        v[i]=false;
        d[i]=0;
    }
    
    s.push(ind);
    v[ind] = true;
    d[ind] = 0;
    
    while(!s.empty()){
        long f = s.top();
        s.pop();
        
        for(auto i: a[f]){
            if(!v[i]){
                d[i] = d[f]+1;
                s.push(i);
                v[i] = true;
            }
        }
    }
    
    max = -1;
    for(long i=1;i<n+1;i++){
        if(d[i]>max){
            max = d[i];
        }
    }
    
    cout<<max<<"\n";
    
	return 0;
}