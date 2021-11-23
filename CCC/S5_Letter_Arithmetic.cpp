#include <bits/stdc++.h>
using namespace std;

vector<string> word(3);

int letterToInt(vector<char> &perm, int w, int position, int number){
    char letter;
    int j = word[w].size()-position;
    if(j < 0) return 0;
    letter = word[w][j];
    for(int i=0;i<10;i++){
        if(perm[i] == letter) return i;
    }
    if(perm[number] == ' '){
        perm[number] = letter;
        return number;
    }
    return -1;
}

int doPosition(vector<char> perm, int position, int carry) {
    vector<char> thisPerm(10);
    vector<int> hashTable(1000);
    int sum, hash, a, b, c;
    for(int i=0;i<10;i++) thisPerm[i] = perm[i];
    for(int i=0;i<1000;i++) hashTable[i] = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                a = letterToInt(perm, 0, position, i);
                b = letterToInt(perm, 1, position, j);
                c = letterToInt(perm, 2, position, k);
                hash = a*100+b*10+c;
                if(a >= 0 && b >= 0 && c >= 0 && hashTable[hash] == 0){
                    sum = carry+a+b-c;
                    if(sum % 10 == 0){
                        if(position == word[2].size()){
                            if(sum == 0 && c > 0){
                                for(int w=0;w<3;w++){
                                    for(int d=word[w].size();d>0;d--){
                                        cout << letterToInt(perm, w, d, 0);
                                    }
                                    cout << "\n";
                                }
                                return 1;
                            }
                        }else if(doPosition(perm, position+1, sum/10) == 1) return 1;
                    }
                    hashTable[hash] = 1;
                }
                for(int p=0;p<10;p++) perm[p] = thisPerm[p];
            }
        }
    }
    return 0;
}

int main(){
    vector<char> perm(10);

    int n; cin >> n;
    while(n--){
        for(int i=0;i<3;i++) cin >> word[i];
        for(int j=0;j<10;j++) perm[j] = ' ';
        doPosition(perm, 1, 0);
    }
}
