#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

struct tip{
    int type; // 0: normal, 1: good, 2: excellent
    int dir; // 0: LT, 1: UP, 2: RT, 3: DN
    int r;
    int c;
};

vi get_combos(vector<string> board, int i, int j){
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vi lengths(4, 0);
    vi ret;

    for(int dir=0;dir<4;dir++){
        int r = i+dirs[dir].fi;
        int c = j+dirs[dir].se;
        while(true){
            if(r < 0 || r >= 8 || c < 0 || r >= 8 || board[r][c] != board[i][j]){
                break;
            }
            lengths[dir]++;
            r += dirs[dir].fi;
            c += dirs[dir].se;
        }
    }

    int hor = lengths[0]+lengths[2]+1;
    int ver = lengths[1]+lengths[3]+1;
    if(hor >= 3) ret.pb(hor);
    if(ver >= 3) ret.pb(ver);

    return ret;
}

bool tip_cmp(tip a, tip b){
    if(a.type != b.type){
        return a.type < b.type;
    }else{
        if(a.r != b.r){
            return a.r < b.r;
        }else{
            if(a.c != b.c){
                return a.c < b.c;
            }else{
                return a.dir < b.dir;
            }
        }
    }
}

void print_tip(vector<string> board, tip t){
    if(t.type == 0){
        cout << "Norm: ";
    }else if(t.type == 1){
        cout << "Good: ";
    }else if(t.type == 2){
        cout << "Excl: ";
    }
    cout << board[t.r][t.c];
    cout << ".";
    if(t.dir == 0){
        cout << "LT";
    }else if(t.dir == 1){
        cout << "UP";
    }else if(t.dir == 2){
        cout << "RT";
    }else if(t.dir == 3){
        cout << "DN";
    }
    cout << "@";
    cout << t.r << "," << t.c << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 10;
    while(t--){
        vector<string> board(8);
        for(int i=0;i<8;i++) cin >> board[i];
        vector<tip> tips;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
                for(int dir=0;dir<4;dir++){
                    int si = i+dirs[dir].fi;
                    int sj = j+dirs[dir].se;
                    if(si >= 0 && si < 8 && sj >= 0 && sj < 8){
                        vector<string> swapped_board = board;
                        swap(swapped_board[i][j], swapped_board[si][sj]);
                        vi combos = get_combos(swapped_board, si, sj);
                        if(!combos.empty()){
                            vi other_combos = get_combos(swapped_board, i, j);
                            combos.insert(combos.end(), other_combos.begin(), other_combos.end());
                        }

                        tip t;
                        if(combos.empty()){
                            continue;
                        }else if(combos.size() >= 2 || combos[0] > 5){
                            t.type = 2; 
                        }else if(combos[0] == 4){
                            t.type = 1;
                        }else if(combos[0] == 3){
                            t.type = 0;
                        }
                        t.dir = dir;
                        t.r = i; 
                        t.c = j;
                        tips.pb(t);
                    }
                }
            }
        }

        if(tips.empty()){
            cout << "Game Over\n";
        }else{
            sort(tips.begin(), tips.end(), tip_cmp);
            print_tip(board, tips[0]);
        }
    }
}