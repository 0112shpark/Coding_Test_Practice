#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	//int dp[10010] = { 0 };
	int coin[110];
	int cnt[100010];
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;

	cin >> n >> k;
	for (int i = 0; i < 10010; i++) {
		cnt[i] = 99999999;
	}
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		cnt[coin[i]] = 1;
	}

	
	//cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (1 + cnt[j - coin[i]] < cnt[j]) {
				cnt[j] = 1 + cnt[j - coin[i]];
			}
			//dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	if (cnt[k] == 99999999) {
		cout << -1;
	}
	else { cout << cnt[k]; }
}