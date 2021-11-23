#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using T = pair<int, int>;

typedef tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e6+1;

int n;
int ra[MAXN];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	ordered_set tr;

	while(n--){
		char op; cin>>op;
		if(op == 'N'){
			int x, r; cin>>x>>r;
			tr.insert({r, x});
			ra[x] = r;
		}else if(op == 'M'){
			int x, r; cin>>x>>r;
			tr.erase({ra[x], x});
			tr.insert({r, x});
			ra[x] = r;
		}else{
			int k; cin>>k;
			cout<<(*tr.find_by_order(k-1)).second<<"\n";
		}
	}
}

