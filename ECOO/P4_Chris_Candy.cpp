#include <bits/stdc++.h>
using namespace std;

bool prime(long long x){
    for(long long i=2;i<=sqrt(x);i++){
        if(x % i == 0) return false;
    }
    return true;
}

vector<long long> getFactors(long long x){
    vector<long long> factors;
    long long factor = 2;
    while(factor <= sqrt(x)){
        if(x % factor == 0){
            factors.push_back(factor);
            x /= factor;
        }else{
            factor += factor == 2 ? 1 : 2;
        }
    }
    factors.push_back(x);
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k; cin >> k;
    // take k and add 1
    k += 1;
    // get prime factors of k+1
    vector<long long> factors = getFactors(k); 
    // take each of those factors and subtract 1
    long long sum = 0;
    for(auto x:factors) sum += x-1;
    if(sum > 1e5){
        cout << "Sad Chris";
        return 0;
    }
    // number of candies is sum of those factors
    cout << sum << "\n";
    for(long long i=0;i<factors.size();i++){
        for(long long j=0;j<factors[i]-1;j++){
            cout << i+1 << " ";
        }
    }
}