//subsequence with largest sum which is in increasing order
//we can also similarly find subsequence with largest length of increasing order
#include <bits/stdc++.h>
using namespace std;
int main() {
    
	long n;
	cin>>n;
	vector <long> a(n,0);
	    
	for(long i=0;i<n;i++){
	   cin>>a[i];
	}
	
	vector <long> dp(n,0);
	for(long i=0;i<n;i++){
	    dp[i]=a[i];
	}
	
	for(long i=1;i<n;i++){
	    for(long j=0;j<i;j++){
	        if(a[i]>a[j] &&  dp[i]<dp[j]+a[i]){
	            dp[i] = dp[j]+a[i];
	        }
	    }
	}
	
	sort(dp.begin(),dp.end());
	cout<<dp[n-1]<<endl;
	
	return 0;
}
