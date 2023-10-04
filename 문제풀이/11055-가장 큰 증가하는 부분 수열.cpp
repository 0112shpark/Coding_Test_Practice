#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int arr[1010];
	int sum[1010];
	int ans=0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	for (int i = 0; i < n; i++) {
		
		sum[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				sum[i] = max(sum[i], sum[j] + arr[i]);
			}
		}
		ans = max(sum[i], ans);
	}
	cout << ans;
}