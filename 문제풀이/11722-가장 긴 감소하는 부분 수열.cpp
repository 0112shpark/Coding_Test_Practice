#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1010];
int dp[1010];
int ans = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		
		ans = max(dp[i], ans);
	}

	cout << ans;
}