#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int arr[100010];
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int idx = 0;
	int len = 100010;
	int start = 0;
	int sum = arr[0];

	
	while (start <= idx && idx < n) {
		if (sum < s) {
			idx++;
			sum += arr[idx];
			
		}
		else {
			len = min(len, idx - (start - 1));
			sum -= arr[start];
			start++;
		}
	}
	if (len == 100010) {
		cout << 0;
	}
	else {
		cout << len;
	}
}