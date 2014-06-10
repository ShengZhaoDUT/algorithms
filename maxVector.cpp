#include <iostream>
using namespace std;

int maxsum3(int l, int u);
int max(int a, int b);
int x[10] = {0,1,-2,3,-9,55,-30,7,8,9};

int main() {
	int result = maxsum3(0, 9);
	cout << result << endl;
}

int maxsum3(int l, int u) {
	if(l > u) {
		return 0;
	}
	else if(l == u) {
		return max(0, x[l]);
	}
	int media = (l + u) / 2;
	int sum = 0;
	int lmax = 0;
	for(int i = media; i >= l; i--) {
		sum += x[i];
		lmax = max(lmax, sum);
	}
	sum = 0;
	int rmax = 0;
	for(int i = media + 1; i <= u; i++) {
		sum += x[i];
		rmax = max(rmax, sum);
	}
	int tmp = max(lmax + rmax, maxsum3(l, media));
	return max(tmp, maxsum3(media + 1, u)); 
};

int max(int a, int b) {
	return a > b ? a : b;
};

