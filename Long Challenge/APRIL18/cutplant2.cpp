#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
#define inf 0x7fffffff
long long int A[100003], B[100003];
int tree[500005];
void build_tree(int node, int a, int b) {
    if(a > b) return;
    
    if(a == b) {
            tree[node] = a;
        return;
    }
    
    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);
    
    tree[node] = B[tree[node*2]] >  B[tree[node*2+1]] ? tree[node*2] : tree[node*2 + 1]; // Init root value
}
 
int query_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return -1;
 
    if(a >= i && b <= j)
        return tree[node];
 
    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
    if(q1 == -1)
        return q2;
    else if (q2 == -1)
        return q1;
    int res = B[q1] > B[q2] ? q1 : q2;
    
    return res;
}
 
int solve(int l, int r, int n) {
    if (l>r) return 0;
    if (l == r) {
        if (A[l] == B[l])
            return 0;
        else if (A[l] < B[l])
            return -1;
        return 1;
    }
    
    int max_in = query_tree(1, 0, n-1, l, r);
    int mid = (r-l)/2, ansl, ansr, ans;
    int L = max_in, R = max_in;
    if(A[max_in] < B[max_in])
        return -1;
    else if (A[max_in] == B[max_in]) {
        ansl = solve(max_in + 1, r, n);
        ansr = solve(l, max_in-1, n);
        if (ansr == -1 || ansl == -1)
            return -1;
        ans = ansl + ansr;
    } else {
        for(int i = max_in+1; i< r; i++) {
            if (A[i] >= B[max_in]){
                R++;
                A[i] = B[max_in];
            }
            else
                break;
        }
        for(int i = max_in-1; i>= l; i--) {
            if (A[i] >= B[max_in]){
                L--;
                A[i] = B[max_in];
            }
            else
                break;
        }
        ansl = solve(max_in + 1, r, n);
        ansr = solve(l, max_in-1, n);
        if (ansr == -1 || ansl == -1)
            return -1;
        ans = ansl + ansr + 1;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for (int i = 0; i<n; i++)
            cin>>A[i];
            
        for (int i = 0; i<n; i++)
            cin>>B[i];
        build_tree(1, 0, n-1);
        cout << solve(0, n-1, n) << endl;
    }
    return 0;
}
 