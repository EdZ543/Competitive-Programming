#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin >> N;
    vector<vector<vector<ll>>> matrices;    
    vector<vector<ll>> product;

    for (ll i = 0; i < N; i++) {
        ll r, c; cin >> r >> c;
        vector<vector<ll>> matrix(r, vector<ll>(c));
        for (ll i = 0; i < r; i++) {
            for (ll j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        matrices.push_back(matrix);
    }

    product = matrices[0];

    for (ll i = 0; i < N-1; i++) {
        vector<vector<ll>> A = product, B = matrices[i+1];
        ll rows = A.size() * B.size();
        ll cols = A[0].size() * B[0].size();
        product = vector<vector<ll>>(rows, vector<ll>(cols, 0));
        for (ll r1 = 0; r1 < rows; r1 += B.size()) {
            for (ll c1 = 0; c1 < cols; c1 += B[0].size()) {
                for (ll r2 = 0; r2 < B.size(); r2++) {
                    for (ll c2 = 0; c2 < B[0].size(); c2++) {
                        ll ar = r1 / B.size();
                        ll ac = c1 / B[0].size();
                        product[r1+r2][c1+c2] = B[r2][c2] * A[ar][ac];
                    }
                }
            }
        }
    }

    ll maxe = -LLONG_MAX, mine = LLONG_MAX, maxrs = -LLONG_MAX, minrs = LLONG_MAX, maxcs = -LLONG_MAX, mincs = LLONG_MAX;
    vector<ll> rowsums(product.size(), 0);
    vector<ll> colsums(product[0].size(), 0);
    for (ll i = 0; i < product.size(); i++) {
        for (ll j = 0; j < product[0].size(); j++) {
            maxe = max(maxe, product[i][j]);
            mine = min(mine, product[i][j]);
            rowsums[i] += product[i][j];
            colsums[j] += product[i][j];
        }
    }
    maxrs = *max_element(rowsums.begin(), rowsums.end());
    minrs = *min_element(rowsums.begin(), rowsums.end());
    maxcs = *max_element(colsums.begin(), colsums.end());
    mincs = *min_element(colsums.begin(), colsums.end());
    cout << maxe << "\n" << mine << "\n" << maxrs << "\n" << minrs << "\n" << maxcs << "\n" << mincs << "\n";
}