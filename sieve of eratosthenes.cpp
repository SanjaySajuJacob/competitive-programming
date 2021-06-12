#include <bits/stdc++.h>
using namespace std;
int main() {
    long n;
    cin>>n;
    vector <bool> isprime(n+1,true);
    
    for(long i=2;i<n+1;i++){
        if(isprime[i]==true){
            for(long j=i*i;j<n+1;j+=i){
                isprime[j]=false;
            }
        }
    }
    
    vector <long> prim;
    for(long i=0;i<n+1;i++){
        if(isprime[i]){
            prim.push_back(i);
        }
    }

	return 0;
}
