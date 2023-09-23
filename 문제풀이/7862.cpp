#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

	int board[3][3];
	string input = " ";
	int ocnt = 0;
	int xcnt = 0;
	int total_cnt = 0;
	vector<string> ans;

	while (1) {
		cin >> input;
		if (input == "end") {

			for (int i = 0; i < ans.size(); i++) {

				cout << ans[i] << endl;

			}
			return 0;
		}
		int ocnt = 0;
		int xcnt = 0;
		int total_cnt = 0;
		for (int i = 0; i < 9; i++) {
			board[i / 3][i % 3] = input[i];
			if (input[i] == 'O') {
				ocnt++;
				total_cnt++;
			}
			else if (input[i] == 'X') {
				xcnt++;
				total_cnt++;
			}
		}
		int xflag = 0;
		// x win
		if (xcnt == ocnt + 1) {
			

			// 가로체크
			for (int i = 0; i < 3; i++) {
				if (board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
					xflag++;
				}
			}

			//세로체크
			for (int i = 0; i < 3; i++) {
				if (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
					xflag ++;
				}
			}

			//대각선 체크

			if (board[0][0] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
				xflag++;
			}
			if (board[0][2] == 'X' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
				xflag++;
			}

			//비긴경우
			if (total_cnt == 9) {
				xflag = 1;
			}
			
		}

		//o wins
		if (xcnt == ocnt||xflag) {
			

			// 가로체크
			for (int i = 0; i < 3; i++) {
				if (board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
					xflag++;
				}
			}

			//세로체크
			for (int i = 0; i < 3; i++) {
				if (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
					xflag++;
				}
			}

			//대각선 체크

			if (board[0][0] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
				xflag ++;
			}
			if (board[0][2] == 'O' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
				xflag ++;
			}
			
		}
		if (xflag ==1 ) {
				ans.push_back("valid");
				continue;
		}
		else{
			ans.push_back("invalid");
			continue;
		}
		
	}


}