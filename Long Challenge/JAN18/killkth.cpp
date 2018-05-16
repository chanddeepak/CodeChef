#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,s2="";
    cin>>s;
    long j=0;
    vector<string> s1;
    for (int i = 0; i < s.size(); i++)
        for (int len = 1; len <= s.size() - i; len++) {
            s1.push_back(s.substr(i, len));
            j++;
        }
    sort(s1.begin(),s1.end());
    for(long i=0;i<j;i++)
        s2+=s1[i];
    long q,p,m,k,g=0;
    cin>>q;
    while(q--) {
        cin>>p>>m;
        k=(p*g)%m+1;
        //cout<<k;
        cout<<s2[k-1]<<"\n";
        g+=s2[k-1];
        //cout<<g;
    }

    return 0;
}
