#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	long long t, n ,A[100005], B[100005], dp[100005], incl[100005];
	scanf("%lld", &t);
	while(t--) {
	    scanf("%lld", &n);
	    for (int i=0;i<n;i++) {
	        scanf("%lld", &A[i]);
	        B[i] = 0;
	    }
	    vector<long long int> V;
	    for (long long int i = 0;i<n;i++) {
	       // printf("%d ", A[i]);
	        if ((i == n-1 || A[i] < A[i+1]) && (!i || A[i-1] > A[i])) {
	           if (i-2<0 || B[i-2] > 0 || (A[i-2] + A[i] < A[i-1])) {
	               B[i] = -A[i];
	           } else {
	               V.push_back(i-2);
	               V.push_back(i);
	           }
	        }
	        else {
	            B[i] = A[i];
	        }
	       // printf("%d\n", B[i]);
	    }
	    long long int len = V.size();
	    long long int i = 0;
	   // for (int j = 0;j<len;j++){
	   //     printf("%d ", V[j]);
	   // }
	   // printf("\n");
	    while (i < len) {
	        vector<long long int> newV;
	        long long int k;
	       // printf("i= %d\n", i);
	        for (k = i; k<len; k++) {
	           // printf("k=%d, k+1=%d\n", k, k+1);
	            if (k==i || k+1 == len || V[k+1]== V[k]) {
	                newV.push_back(V[k]);
	               // printf("pushing : %d: %d\n", V[k], V[k+1]);
	                if (k!=i)
	                    k++;
	            } else if (newV.size()> 0) {
	                newV.push_back(V[k]);
	                break;
	            } else
	                break;
	        }
	        
	        long long int c = k+1;
	       // for (k = 0;k<newV.size();k++)
	       //     printf("%d ", newV[k]);
	       // printf("\n");
	        
	        for (k = 0; k<newV.size(); k++) {
	            if (k==0) {
	                dp[k] = A[newV[k]];
	                incl[k] = 1;
	            } else if (k==1) {
	                if (dp[k-1] > A[newV[k]]){
	                    dp[k] = dp[k-1];
	                    incl[k] = 0;
	                } else {
	                    dp[k] = A[newV[k]];
	                    incl[k] = 1;
	                }
	            }
	            else if (dp[k-2]+ A[newV[k]] > dp[k-1]) {
	                dp[k] = dp[k-2] + A[newV[k]];
	                incl[k] = 1;
	            } else {
	                dp[k] = dp[k-1];
	                incl[k] = 0;
	            }
	           // printf("include: %d, max: %lld\n", incl[k], dp[k]);
	        }
	        k = newV.size()-1;
            while (k>=0) {
                if (incl[k]) {
                    B[newV[k]] = -A[newV[k]];
                    if (k-1 >= 0) {
                        B[newV[k-1]] = A[newV[k-1]];
                    }
                    k-=2;
                } else {
                    B[newV[k]] = A[newV[k]];
                    k--;
                }
            }
            i = c;
	    }
	    for (long long int i=0;i<n;i++) {
	        printf("%lld ", B[i]);
	    }
	    printf("\n");
	}
	return 0;
}
