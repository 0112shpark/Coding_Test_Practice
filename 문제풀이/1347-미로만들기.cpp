#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> mov;
string str;
char map[110][110];
//dir 1,2,3,4= 위 오른 아래 왼

int turn_r(int dir) {
	if (dir < 4) {
		return dir + 1;
	}
	else {
		return 1;
	}
}
int turn_l(int dir) {
	if (dir > 1) {
		return dir - 1;
	}
	else {
		return 4;
	}
}
void go(int dir) {
	if (dir == 1) {
		mov.push_back({ -1,0 });
	}
	else if (dir == 2) {
		mov.push_back({ 0,1 });
	}
	else if (dir == 3) {
		mov.push_back({ 1,0 });
	}
	else {
		mov.push_back({ 0,-1 });
	}
}

int main() {

	int n;
	cin >> n;
	cin >> str;
	int dir = 3;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			dir =turn_r(dir);
		}
		else if (str[i] == 'L') {
			dir=turn_l(dir);
		}
		else {
			
			go(dir);
		}
	}
	int ver_min = 55;
	int hor_min = 55;
	int ver_max = 55;
	int hor_max = 55;
	map[55][55] = '.';
	int k = 55;
	int j = 55;

	for (int i = 0; i < mov.size(); i++) {
		
		k += mov[i].first;
		j += mov[i].second;
		map[k][j] = '.';
		ver_min = min(k, ver_min);
		hor_min = min(j, hor_min);
		ver_max = max(k, ver_max);
		hor_max = max(j, hor_max);
	}

	
	for (int i = ver_min; i <= ver_max; i++) {
		for (int j = hor_min; j <= hor_max; j++) {
			if (map[i][j] == '.') {
				cout << '.';
			}
			else {
				cout << '#';
			}
		}
		cout << endl;
	}
	

}