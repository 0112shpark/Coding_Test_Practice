#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	string b;
	int ans = 0;
	
	
	cin >> a >> b;

	int** dp = new int* [b.length()+1];
	for (int i = 0; i < b.length() + 1; i++) {
		dp[i] = new int[a.length() + 1];
	}
	for (int i = 0; i < b.length() + 1; i++) {
		for (int j = 0; j < a.length() + 1; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			
			if (b[i] == a[j]) {
				dp[i+1][j+1] = dp[i][j]+1;
				
			}
			ans = max(ans, dp[i+1][j+1]);
		}
	}
	cout << ans;
}