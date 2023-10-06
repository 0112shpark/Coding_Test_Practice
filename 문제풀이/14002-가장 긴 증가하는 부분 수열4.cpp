#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	int n;
	int arr[1010];
	int dp[1010];
	int ans = 0;
	stack <int> st;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max_idx = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
			max_idx = i;
		}
	}
	int temp = dp[max_idx];
	
	for (int i = max_idx; i >= 0; i--) {
		if (temp == 0) {
			break;
		}

		if (dp[i] == temp) {
			
			st.push(arr[i]);
			temp--;
		}
		
	}
	cout << ans << endl;
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	
}