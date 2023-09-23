#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int x;

	scanf("%d %d", &n, &x);

	int* arr = (int*)malloc(sizeof(int) * n);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i < x) {
			sum += arr[i];
		}
	}

	int ans = sum;
	int cnt = 1;

	for (int i = x; i < n; i++) {
		sum = sum + arr[i] - arr[i - x];
		if (sum >= ans) {
			if (sum == ans) {
				cnt++;
			}
			else {
				cnt = 1;
				ans = sum;
			}
		}
	}
	if (ans == 0) {
		printf("SAD");
	}
	else {
		printf("%d\n%d", ans, cnt);
	}



	free(arr);
}