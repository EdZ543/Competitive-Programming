#include <bits/stdc++.h>
using namespace std;

int r, c;

vector<string> removeLines(vector<string> board){
	vector<string> newBoard = board;

	for(int i=0;i<r;i++){
		int consec = 1;
		for(int j=1;j<c;j++){
			if(board[i][j] == board[i][j-1]) consec++;
			else consec = 1;

			if(consec == 3){
				newBoard[i][j-2] = ' ';
				newBoard[i][j-1] = ' ';
				newBoard[i][j] = ' ';
			}else if(consec > 3){
				newBoard[i][j] = ' ';
			}
		}
	}

	for(int j=0;j<c;j++){
		int consec = 1;
		for(int i=1;i<r;i++){
			if(board[i][j] == board[i-1][j]) consec++;
			else consec = 1;

			if(consec == 3){
				newBoard[i-2][j] = ' ';
				newBoard[i-1][j] = ' ';
				newBoard[i][j] = ' ';
			}else if(consec > 3){
				newBoard[i][j] = ' ';
			}
		}
	}

	return newBoard;
}

bool solved(vector<string> board){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(board[i][j] != ' ') return false;
		}
	}
	return true;
}

bool solvable(vector<string> board){
	if(solved(board)) return true;

	for(int i=0;i<r;i++){
		for(int j=0;j<c-1;j++){
			if(board[i][j] != ' ' && board[i][j+1] != ' '){
				vector<string> swapped = board;
				swap(swapped[i][j], swapped[i][j+1]);
				vector<string> removed = removeLines(swapped);
				if(swapped != removed){
					if(solvable(removed)) return true;
				}
			}
		}
	}

	for(int j=0;j<c;j++){
		for(int i=0;i<r-1;i++){
			if(board[i][j] != ' ' && board[i+1][j] != ' '){
				vector<string> swapped = board;
				swap(swapped[i][j], swapped[i+1][j]);
				vector<string> removed = removeLines(swapped);
				if(swapped != removed){
					if(solvable(removed)) return true;
				}
			}
		}
	}


	return false;
}

int main(){
	ios::sync_with_stdio(0);

	int cases = 10;
	while(cases--){
		cin >> r >> c;
		string line = "";
		for(int i=0;i<5;i++){
			vector<string> board(r);
			for(int j=0;j<r;j++) cin >> board[j];

			line += solvable(board) ? 'S' : 'N';
		}
		cout << line << '\n';
	}
}
