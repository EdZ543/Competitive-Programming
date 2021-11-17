#include <bits/stdc++.h>
using namespace std;

int t, n, k, w;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k >> w;
        vector<int> pins(n);
        for(int i=0;i<n;i++) cin >> pins[i];

        vector<int> sums(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i == 0){
                for(int j=0;j<w;j++){
                    sum += pins[j];
                }
            }else{
                sum -= pins[i-1];
                if(i+w-1 < n) sum += pins[i+w-1];
            }
            sums[i] = sum;
        }
        
        int dp[k+1][n];
        for(int i=0;i<k+1;i++){
            for(int j=n-1;j>=0;j--){
                if(i == 0){
                    dp[i][j] = 0;
                }else{
                    int a = 0;
                    if(j != n-1) a = dp[i][j+1];

                    int b = sums[j];
                    if(i != 0 && j+w < n) b += dp[i-1][j+w];

                    dp[i][j] = max(a, b);
                }
            }
        }

        cout << dp[k][0] << "\n";
    }
}