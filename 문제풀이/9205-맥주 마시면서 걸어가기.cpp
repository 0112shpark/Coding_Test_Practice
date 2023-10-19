#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int suc_flag = 0;

int t, n;
/*void bfs(int a, int b) {
	q.push({ a,b });

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (abs(dest.first - x) + abs(dest.second - y) <= 1000) {
			cout << "happy"<<endl;
			suc_flag = 1;
			return;
		}
		for (int i = 0; i < store.size(); i++) {
			int store_x = store[i].first.first;
			int store_y = store[i].first.second;
			if (store[i].second == 0) {
				if (abs(store_x - x) + abs(store_y - y) <= 1000) {
					q.push({ store_x,store_y });
					store[i].second = 1;
				}
			}
		}
	}

}*/

int main() {
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		int x1, y1;
		cin >> x1 >> y1;
		queue<pair<int, int>> q;
		//x,y,visited
		vector<pair<pair<int, int>, int>> store;
		pair<int, int> dest;
		for (int i = 0; i < n; i++) {
			int store_x, store_y;
			cin >> store_x >> store_y;
			store.push_back({ {store_x,store_y},0 });
		}
		
		cin >> dest.first>>dest.second;

		suc_flag = 0;
		q.push({ x1,y1 });

		while (!q.empty()) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (abs(dest.first - x) + abs(dest.second - y) <= 1000) {
				cout << "happy" << endl;
				suc_flag = 1;
				break;
			}
			for (int i = 0; i < store.size(); i++) {
				int store_x = store[i].first.first;
				int store_y = store[i].first.second;
				if (store[i].second == 0) {
					if (abs(store_x - x) + abs(store_y - y) <= 1000) {
						q.push({ store_x,store_y });
						store[i].second = 1;
					}
				}
			}
		}
		if (!suc_flag) {
			cout << "sad" << endl;
		}
	}
}
