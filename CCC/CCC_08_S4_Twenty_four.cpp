#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<char> ops = {'+', '-', '*', '/'};

int operate(int a, char op, int b){
	int ret;
	if(op == '+'){
		ret = a+b;
	}else if(op == '-'){
		ret = a-b;
	}else if(op == '*'){
		ret = a*b;
	}else if(op == '/'){
		if(b != 0 && a%b == 0){
			ret = a/b;
		}else{
			ret = INT_MAX;
		}
	}
	return ret;
}

int rec(vector<int> cards){
	if(cards.size() == 1){
		return cards.front() <= 24 ? cards.front() : INT_MAX;
	}
	int ret = INT_MIN;
	for(int card1=0;card1<cards.size();card1++){
		for(auto op : ops){
			for(int card2=0;card2<cards.size();card2++){
				if(card1 == card2) continue;
				vector<int> next_cards;
				int combine = operate(cards[card1], op, cards[card2]);
				if(combine == INT_MAX) continue;
				next_cards.push_back(combine);
				for(int i=0;i<cards.size();i++){
					if(i != card1 && i != card2) next_cards.push_back(cards[i]);
				}	
				int next_rec = rec(next_cards);
				if(next_rec != INT_MAX) ret = max(ret, next_rec);
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	for(int i=0;i<n;i++){
		vector<int> cards(4);
		for(int j=0;j<4;j++) cin >> cards[j];
		cout << rec(cards) << "\n";
	}
}