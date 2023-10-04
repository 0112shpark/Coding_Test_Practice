#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1010];
	int ans = 0;
	int dp[1010];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i ; j++) {
			// i번째 보다 앞에 있는 값 탐색

			if (arr[j] < arr[i]) {
				//만약 앞이고 arr[i]보다 값이 작으면
				//arr[j]의 dp값+1과 dp[i]값 중 큰 값 선택
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
		
		ans = max(ans, dp[i]);
	}
	cout << ans;
}