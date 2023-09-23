#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

char arr[51][51];
int MAX = 0;
int n;
void check_row(int row) {
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		if (arr[row][i] == arr[row][i + 1]) {
			cnt++;
		}
		else {
			if (cnt + 1 > MAX) {
				//cout << row << i<<cnt+1<<endl;
				MAX = cnt+1;
			}
			cnt = 0;
		}
		
	}
	if (cnt + 1 > MAX) {
			
			MAX = cnt+1;
		}
}
void check_col(int col) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i][col] == arr[i+1][col]) {
			cnt++;
		}
		else {
			if (cnt + 1 > MAX) {
				//cout << col << i;
				MAX = cnt + 1;
			}
			cnt = 0;
		}
		
	}
	if (cnt + 1 > MAX) {
			
			MAX = cnt + 1;
		}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	//가로 체인지
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = tmp;
			check_row(i);
			check_col(j);
			check_col(j + 1);
			tmp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = tmp;
		}
	}

	
	//세로 체인지
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			int tmp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;
			check_col(i);
			check_row(j);
			check_row(j + 1);
			tmp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;
		}
	}

	cout << MAX;
}