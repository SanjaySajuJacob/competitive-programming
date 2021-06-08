#include <bits/stdc++.h>
using namespace std;
int buildseg(int l, int r, vector <long> &b, vector <long> &a, int i){
    if(r==l){
        a[i]=b[r];
        return 0;
    }
    
    long mid = l + (r-l)/2;
    buildseg(l, mid, b, a, 2*i);
    buildseg(mid+1, r, b, a, 2*i+1);
    a[i] = min(a[2*i], a[2*i+1]);
    
    return 0;
}

long query(long lq, long rq, vector <long> &a, long ls, long rs,long i){
    
    if(lq<=ls && rs<=rq){
        return a[i];
    }
    
    long mid=ls +(rs-ls)/2;
    
    if(rs<lq || ls>rq){
        return 10000;
    }
    
    long c1 = query(lq,rq,a,ls,mid,2*i);
    long c2 = query(lq,rq,a,mid+1,rs,2*i+1);
    return min(c1,c2);
}

int main() {
    long q;
    cin>>q;
    long n;
    cin>>n;
    vector <long> b(n+1,0);
    vector <long> a(4*n+1,0);
     
    for(long i=0;i<n;i++){
         cin>>b[i+1];
    }
    
    buildseg(1,n,b,a,1);
    
    while(q--){
        long l,r;
        cin>>l>>r;
        long mini;
        mini=query(l,r,a,1,n,1);
        cout<<mini<<"\n";
    }
	return 0;
}