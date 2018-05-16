#include<bits/stdc++.h>
using namespace std;
vector<int> index(string &s,char a) {
    vector<int> v;
    for(int i=0;i<s.size();i++) {
        if(s[i]==a) {
            v.push_back(i+1);
        }
    }
    return v;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        long n=s.size();
        map<char,long> m;
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
        }
        map<char,long>::iterator it;
        vector<long> v(n);
        vector<int> v1;
        int j=0,k=n-1,o=0,f=0;
        for(it=m.begin();it!=m.end();it++) {
            long p=it->second;
            if(p%2!=0)
                o++;
            if(o>1) {
                f=1;
                break;
            }
        }
        if(f==1) {
            cout<<-1<<"\n";
        } else {
            if(m.size()==1) {
                for(int i=1;i<=n;i++) {
                    cout<<i<<" ";
                }
                cout<<"\n";
            } else {
                for(it=m.begin();it!=m.end();it++) {
                    char c=it->first;
                    v1=index(s,c);
                    int i=0,q=0;
                    while(i<v1.size()) {
                        if(v1.size()%2!=0&&q==0) {
                            v[n/2]=v1[i];
                            i++;
                            q=1;
                        } else {
                            v[j]=v1[i];
                            i++;
                            j++;
                            v[k]=v1[i];
                            k--;
                            i++;
                        }
                    }
                }
                for(int i=0;i<n;i++) {
                    cout<<v[i]<<" ";
                }
                cout<<"\n";
            }

        }

    }
    return 0;
}
