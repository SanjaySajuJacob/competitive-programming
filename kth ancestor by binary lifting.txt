#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    long l = log2(n);
    vector <vector <long>> a(n+1,vector <long>(0));
    vector <bool> v(n+1,false);
    queue <long> q;
    vector <long> parent(n+1,-1);
    
    for(long i=1;i<n;i++){
        long n1,n2;
        cin>>n1>>n2;
        a[n1].push_back(n2);
        a[n2].push_back(n1);
    }
    
    vector <vector <long>> s(n+1,vector <long> (l-1,-1));
    q.push(1);
    v[1] = true;
    while(!q.empty()){
        long f = q.front();
        q.pop();
        for(auto u: a[f]){
            if(v[u]==false){
                q.push(u);
                v[u] = true;
                parent[u] = f;
            }
        }
    }
    
    for(long i=1;i<n+1;i++){
        s[i][0] = parent[i];
    }
    
    for(long i=1;i<l;i++){
        for(long j=1;j<n+1;j++){
            if(s[j][i-1]==-1){
                s[j][i]=-1;
                continue;
            }
            s[j][i] = s[s[j][i-1]][i-1];
        }
    }
    
    long anc,nod,ans;
    cin>>nod>>anc;
    ans=nod;
    long la = log2(anc);
    
    for(long i=la;anc>0;i--){
        if(i<=anc){
            anc=anc-(long)pow(2,i);
            ans = s[ans][i];
        }
    }
    
    cout<<ans<<"\n";
	return 0;
}