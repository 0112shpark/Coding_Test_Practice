#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int amt[3];
int arr[3];
vector <int> ans; 
int check[210][210][210] = {0};
queue <vector<int>> q;

int mov[6][2] = {
	{0,1},{0,2},{1,0},{1,2},{2,1},{2,0}
};



void bfs() {

	while (!q.empty()) {
		vector<int> water = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int from = mov[i][0];
			int to = mov[i][1];
			vector<int> temp = water;
			if (water[from] == 0) {
				continue;
			}
			if (amt[to] - water[to] < water[from]) {
				temp[to] = amt[to];
				temp[from] = water[from]-(amt[to] - water[to]);
			}
			else {
				temp[from] = 0;
				temp[to] = water[from] + water[to];
			}
			
			
			if (check[temp[0]][temp[1]][temp[2]] != 1) {
				//cout << from << to << endl;
				//cout << temp[0] << temp[1] << temp[2] << endl;
				q.push(temp);
				check[temp[0]][temp[1]][temp[2]] = 1;
				if (temp[0] == 0) {
					ans.push_back(temp[2]);
				}
			}
			
		}
	}

}

int main() {

	
	cin >> amt[0] >> amt[1] >> amt[2];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = amt[2];
	ans.push_back(amt[2]);
	check[0][0][amt[2]] = 1;
	vector <int> temp;
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(amt[2]);
	q.push(temp);
	bfs();
	
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}