#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector <priority_queue<int, vector<int>>>arr(12);
int player[12];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p, w;
		cin >> p >> w;
		arr[p].push(w);
	}
	for (int c = 0; c < k; c++) {
		
		for (int i = 1; i <= 11; i++) {
			if (!arr[i].empty()) {
				player[i] = arr[i].top();
				arr[i].pop();
			}
			else {
				player[i] = 0;
			}
			if (player[i] - 1 >= 0) {
				player[i] -= 1;
			}
			arr[i].push(player[i]);
		}

		for (int i = 1; i <= 11; i++) {
			
				player[i] = arr[i].top();
			
		}
	}

	for (int i = 1; i <= 11; i++) {
		sum += player[i];
	}
	cout << sum;
}