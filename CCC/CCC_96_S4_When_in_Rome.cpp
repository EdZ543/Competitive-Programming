#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<char, int> rn = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
map<int, string> hundreds = {{9, "CM"}, {8, "DCCC"}, {7, "DCC"}, {6, "DC"}, {5, "D"}, {4, "CD"}, {3, "CCC"}, {2, "CC"}, {1, "C"}, {0, ""}};
map<int, string> tens = {{9, "XC"}, {8, "LXXX"}, {7, "LXX"}, {6, "LX"}, {5, "L"}, {4, "XL"}, {3, "XXX"}, {2, "XX"}, {1, "X"}, {0, ""}};
map<int, string> ones = {{9, "IX"}, {8, "VIII"}, {7, "VII"}, {6, "VI"}, {5, "V"}, {4, "IV"}, {3, "III"}, {2, "II"}, {1, "I"}, {0, ""}};

int rom_to_num(string rom){
	int ret = 0;
	for(int i=0;i<rom.size();i++){
		if(
			(rom[i] == 'I' && (rom[i+1] == 'V' || rom[i+1] == 'X')) ||
			(rom[i] == 'X' && (rom[i+1] == 'L' || rom[i+1] == 'C')) ||
			(rom[i] == 'C' && (rom[i+1] == 'D' || rom[i+1] == 'M'))
		){
			ret -= rn[rom[i]];
		}else{
			ret += rn[rom[i]];
		}
	}
	return ret;
}

string num_to_rom(int num){
	string s = "";
	int m = num/100;
	num %= 100;
	string s1 = s+hundreds[m];
	m = num/10;
	num %= 10;
	string s2 = s1+tens[m];
	string s3 = s2+ones[num];
	return s3;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	for(int i=0;i<n;i++){
		string line; cin >> line;
		regex re("[+=]");
		sregex_token_iterator first{line.begin(), line.end(), re, -1}, last;
		vector<string> tokens{first, last};

		cout << line;
		int sum = rom_to_num(tokens[0])+rom_to_num(tokens[1]);
		if (sum > 1000) {
			cout << "CONCORDIA CUM VERITATE";
		} else {
			cout << num_to_rom(sum);
		}
		cout << "\n";
	}
}