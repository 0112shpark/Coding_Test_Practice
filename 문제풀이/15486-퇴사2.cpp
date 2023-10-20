#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1500010] = { 0 };
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<pair<int, int>> arr;
	
	arr.push_back({ 0,0 });
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int weight;
		int pay;
		cin >> weight >> pay;
		arr.push_back({ weight,pay });
		dp[i] = 0;

	}
	for (int i = n; i > 0; i--) {

		//마지막 날까지는 일할 수 있으므로 다시 일 시작하는 날은 n+1까지 가능=>마지막 다음날 퇴사
		if (i + arr[i].first > n + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[arr[i].first + i] + arr[i].second);
		}
	}


	cout << dp[1];
}