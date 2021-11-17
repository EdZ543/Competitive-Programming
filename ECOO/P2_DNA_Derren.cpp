#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        cout << s[i];
        if(i != s.size()-1 && ((s[i] == 'A' && s[i+1] == 'A') || (s[i] != 'A' && s[i+1] != 'A'))) cout << " ";
    }
}