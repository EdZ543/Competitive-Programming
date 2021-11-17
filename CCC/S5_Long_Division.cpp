#include <bits/stdc++.h>
using namespace std;

int n;

bool lessthan(string a, string b){
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    for(int i=0;i<a.size();i++){
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }
    return false;
}

string subtract(string a, string b){
    for(int i=0;i<b.size();i++){
        int indA = a.size()-1-i;
        int indB = b.size()-1-i;

        int digitA = a[indA]-'0';
        int digitB = b[indB]-'0';

        int dif = digitA-digitB;
        if(dif < 0){
            dif += 10;
            int nextDigit = a[indA-1]-'0';
            nextDigit--;
            a[indA-1] = nextDigit+'0';
        }
        a[indA] = dif+'0';
    }
    return a;
}

string divide(string a, string b){
    string quotient = "";

    for(int i=0;i+b.size()<=a.size();i++){
        int count = 0;
        while(!lessthan(a.substr(0, i+b.size()), b)){
            a = subtract(a.substr(0, i+b.size()), b)+a.substr(i+b.size());
            count++;
        }
        char countChar = count+'0';
        quotient += countChar;
    }

    quotient.erase(0, quotient.find_first_not_of('0'));
    a.erase(0, a.find_first_not_of('0'));
    if(quotient == "") quotient = "0";
    if(a == "") a = "0";
    return quotient+'\n'+a+'\n';
}

int main(){
    cin >> n;
    while(n--){
        string a, b; cin >> a >> b;
        cout << divide(a, b) << "\n";
    }
}