#include<iostream>
using namespace std;
int main(){
     int k2,k3,k5,k6; cin>>k2>>k3>>k5>>k6; 
     long long n256 =min(k2, min(k5,k6)); k2-=n256;
     long long n32=min(k3,k2); 
     long long ans= n32*32;
     ans += n256*256;
     cout<<ans<<endl;
 }
