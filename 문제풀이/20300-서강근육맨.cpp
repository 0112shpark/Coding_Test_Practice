#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <long long> arr;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	long long ans = 0;
	
	if (arr.size() % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			
			ans = max(arr[i] + arr[n - i - 1], ans);
		}
	}
	else {
		ans = arr[n - 1];
		for (int i = 0; i < n / 2; i++) {
			
			ans = max(arr[i] + arr[n - i - 2], ans);
		}
	}
	cout << ans;
}