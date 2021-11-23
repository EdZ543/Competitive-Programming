#include <bits/stdc++.h>
using namespace std;

int s, n, c;
map<string, int> fspam, fnonspam;

double similarity(map<string, int> f1, map<string, int> f2){
    double sum1 = 0;
    for(auto [trigram, freq]:f1){
        sum1 += freq * f2[trigram];
    }

    double sum2 = 0;
    for(auto [trigram, freq]:f1){
        sum2 += pow(freq, 2);
    }

    double sum3 = 0;
    for(auto [trigram, freq]:f2){
        sum3 += pow(freq, 2);
    }

    double ret = sum1/(sqrt(sum2)*sqrt(sum3));
    return ret;
}

int main(){
    cin >> s >> n >> c;
    cin.ignore();

    for(int i=0;i<s;i++){
        while(true){
            string line; getline(cin, line);
            if(line == "ENDMESSAGE") break;
            if(line.size() < 3) continue;

            for(int j=0;j<line.size()-2;j++){
                string trigram = line.substr(j, 3);
                if(trigram[0] == '\n' || trigram[1] == '\n' || trigram[2] == '\n') continue;
                fspam[trigram]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        while(true){
            string line; getline(cin, line);
            if(line == "ENDMESSAGE") break;
            if(line.size() < 3) continue;

            for(int j=0;j<line.size()-2;j++){
                string trigram = line.substr(j, 3);
                if(trigram[0] == '\n' || trigram[1] == '\n' || trigram[2] == '\n') continue;
                fnonspam[trigram]++;
            }
        }
    }

    for(int i=0;i<c;i++){
        map<string, int> fmessage;

        while(true){
            string line; getline(cin, line);
            if(line == "ENDMESSAGE") break;
            if(line.size() < 3) continue;

            for(int j=0;j<line.size()-2;j++){
                string trigram = line.substr(j, 3);
                if(trigram[0] == '\n' || trigram[1] == '\n' || trigram[2] == '\n') continue;
                fmessage[trigram]++;
            }
        }

        double spamSim = similarity(fmessage, fspam), nonspamSim = similarity(fmessage, fnonspam);
        string classification = spamSim > nonspamSim ? "spam" : "non-spam";
        cout << fixed << setprecision(5) << spamSim << ' ' << nonspamSim << "\n" << classification << "\n";
    }
}