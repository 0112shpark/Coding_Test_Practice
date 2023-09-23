#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int dp[1010];
	cin >> n;

	vector<pair<int, int>> arr;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j].second < arr[i].second && dp[j]>max) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	sort(dp, dp + n, greater<>());
	cout << n - dp[0];

}