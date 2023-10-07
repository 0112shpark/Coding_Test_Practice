#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int dp[1001][1001];
string a;
string b;

void find(int i, int j) {
	if (dp[i][j] == 0) {
		return;
	}

	if (b[i - 1] == a[j - 1]) {
		find(i - 1, j - 1);
		cout << a[j-1];
	}
	else {
		if (dp[i - 1][j] > dp[i][j - 1]) {
			find(i - 1, j);
		}
		else {
			find(i, j - 1);
		}
	}

}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<int,int> idx;


	cin >> a >> b;


	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (b[i] != a[j]) {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				
			}
			else {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				
			}
			
			
		}
		
	}
	

	cout << dp[b.length()][a.length()] << endl;
	find(b.length(), a.length());
}