#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        double price,quantity,discount,ans=0;
        for(int i=0;i<n;i++) {
            cin>>price>>quantity>>discount;
            double tdiscount = (price*discount)/100;
            double tprice=price+tdiscount;
            tdiscount=(tprice*discount)/100;
            tprice=tprice-tdiscount;
            ans=ans+quantity*(price-tprice);
        }
        cout<<setprecision(20)<<ans<<"\n";
    }
    return 0;
}
