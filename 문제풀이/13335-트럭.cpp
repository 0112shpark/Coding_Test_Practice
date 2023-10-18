#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int n, w, l;
//#, time
deque< int>bridge;
vector<int> truck;
vector<int> finish;
int ans = 0;


int main() {

	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		truck.push_back(temp);
	}

	int weight = 0;
	for (int i = 0; i < n; i++) {
		
		while (1) {
			
			if (bridge.size() == w) {
				weight -= bridge.front();
				bridge.pop_front();
			}
			if (weight + truck[i] <= l) {
				break;
			}
			bridge.push_back(0);
			ans++;
		}
		bridge.push_back(truck[i]);
		weight += truck[i];
		ans++;
	}

	cout << ans+w;
	
}