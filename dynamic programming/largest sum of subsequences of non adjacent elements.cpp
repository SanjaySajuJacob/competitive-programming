//largest sum of subsequence such that no two elements of subsequence are adjacent elements 
#include <bits/stdc++.h>
using namespace std;
int main() {
    
	long n;
	cin>>n;
	vector <long> a(n,0);
	    
	for(long i=0;i<n;i++){
	   cin>>a[i];
	}
	    
	vector <vector <long>> dp (n,vector <long>(2,0));
	dp[0][0]=0;
	dp[0][1]=a[0];
	    
	for(long i=1;i<n;i++){
	   dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
	   dp[i][1] = dp[i-1][0] + a[i];
	}
   
	cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	
	return 0;
}
