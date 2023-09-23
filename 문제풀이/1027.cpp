#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int max = 0;
	double build[60];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> build[i];
	}
	for (int i = 0; i < n; i++) {
		int left_cnt = 0;
		int right_cnt = 0;
		double max_slope = -9999999999;
		
		for (int j = i - 1; j >= 0; j--) {
			double slope = (double)(build[j] - build[i]) / ((i - j));
			//cout << build[i] << " " << build[j] << endl;
			//cout << slope << " "<<max_slope<<endl;
			if (slope > max_slope) {
				left_cnt++;
				max_slope = slope;
			}
		}
		
		max_slope = -9999999999;
		for (int j = i + 1; j <n ; j++) {
			double slope = (double)(build[j] - build[i]) / ((j - i));

			if (slope > max_slope) {
				right_cnt++;
				max_slope = slope;
			}
		}
		//cout << build[i] <<left_cnt<<right_cnt<<endl;
		if (right_cnt + left_cnt > max) {
			
			max = right_cnt + left_cnt;
		}
	}
	cout << max;

}
