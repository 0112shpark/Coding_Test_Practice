#include <iostream>
#include <algorithm>


using namespace std;
int arr[2001];
int dp[2001][2001];


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = 1;
		if (i!=1 && arr[i] == arr[i - 1]) {
			dp[i - 1][i] = 1;
		}
	}
	cin >> k;
	

	for (int i = 2; i <= n-1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]==1) {
				dp[j][j + i] = 1;
			}
		}
	}

	int a, b;
	for (int i = 0; i < k; i++) {
		
		cin >> a >> b;
		cout << dp[a][b] << endl;
	}

}