#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int player[11][11];

int arr[11] = { 0 };
int sum = 0;
int temp_sum = 0;
int n;

void dfs(int cnt,int i) {

	if (cnt == 11) {
		sum = max(sum, temp_sum);
		return;
	}


	//i 번째 선수
	
		
		//j 번째 포지션
		for (int j = 0; j < 11; j++) {
			if (player[i][j] != 0 && !arr[j]) {
				temp_sum += player[i][j];
				arr[j] = 1;
				dfs(cnt + 1,i+1);
				temp_sum -= player[i][j];
				arr[j] = 0;
			}
		}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int c = 0; c < n; c++) {

		// input
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				
				cin >> player[i][j];
			}
		}
		for (int i = 0; i < 11; i++) {
			arr[i] = 0;
		}
		sum = 0;
		temp_sum = 0;
		dfs(0,0);
		cout << sum << " ";
		
	}

	
	
}