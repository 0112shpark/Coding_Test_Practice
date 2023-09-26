#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,b,c;
	
	vector <int> arr;
	cin >> n;
	long long ans = n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		
		int rest = arr[i] - b;
		if (rest <= 0) {
			continue;
		}
		ans = ans + (rest / c);
		if (rest % c != 0) {
			ans++;
		}
	}

	cout << ans;
}