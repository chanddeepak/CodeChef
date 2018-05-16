#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        long c=0;
        for(int i=0;i<s.size();i++) {
            vector<bool> b(5);
            b['c']=false;b['h']=false;b['e']=false;b['f']=false;
            int f=0;
            for(int j=i;j<i+4;j++) {
                if(s[j]=='c'&&b[s[j]]==false) {
                    b[s[j]]=true;
                    f++;
                } else if(s[j]=='h'&&b[s[j]]==false) {
                    b[s[j]]=true;
                    f++;
                } else if(s[j]=='e'&&b[s[j]]==false) {
                    b[s[j]]=true;
                    f++;
                } else if(s[j]=='f'&&b[s[j]]==false) {
                    b[s[j]]=true;
                    f++;
                } else {
                    break;
                }
                if(f==4) {
                    c++;
                }
            }
        }
        if(c!=0) {
            cout<<"lovely "<<c<<"\n";
        } else {
            cout<<"normal\n";
        }

    }
    return 0;
}
