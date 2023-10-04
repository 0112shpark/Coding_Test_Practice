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
			// i��° ���� �տ� �ִ� �� Ž��

			if (arr[j] < arr[i]) {
				//���� ���̰� arr[i]���� ���� ������
				//arr[j]�� dp��+1�� dp[i]�� �� ū �� ����
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
		
		ans = max(ans, dp[i]);
	}
	cout << ans;
}