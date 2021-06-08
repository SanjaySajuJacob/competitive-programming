#include <bits/stdc++.h>
using namespace std;
int buildseg(int l, int r, vector <long> &a, vector <long> &s, int i){
    if(r==l){
        s[i]=a[r];
        return 0;
    }
    
    long mid = l + (r-l)/2;
    buildseg(l, mid, a, s, 2*i);
    buildseg(mid+1, r, a, s, 2*i+1);
    s[i] = min(s[2*i], s[2*i+1]);
    
    return 0;
}
int main() {
    long n;
    cin>>n;
    vector <long> a(n+1,0);
    vector <long> s(2*n+2,0);
     
    for(long i=0;i<n;i++){
         cin>>a[i+1];
    }
     
    buildseg(1,n,a,s,1);
    
    for(long i=1;i<2*n+2;i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
    
	return 0;
}