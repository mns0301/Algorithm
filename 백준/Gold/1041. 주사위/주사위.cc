#include <stdio.h>

long long cat(long long a, long long b) {
	if (a < b) return a;
	else return b;
}

long long cube(long long n[6]) {
	long long sum = 0;
	long long max = 0;
	for (int i = 0; i < 6; i++) {
		sum += n[i];
		if (n[i] > max) max = n[i];
	}
	sum -= max;
	return sum;
}

long long corner(long long n[6]) {
	long long temp = 2e9;
	temp = cat(temp, n[0] + n[1] + n[2]);
	temp = cat(temp, n[0] + n[2] + n[3]);
	temp = cat(temp, n[0] + n[3] + n[4]);
	temp = cat(temp, n[0] + n[4] + n[1]);
	temp = cat(temp, n[5] + n[1] + n[2]);
	temp = cat(temp, n[5] + n[2] + n[3]);
	temp = cat(temp, n[5] + n[3] + n[4]);
	temp = cat(temp, n[5] + n[4] + n[1]);
	return temp;
}

long long edge(long long n[6]) {
	long long temp = 2e9;
	temp = cat(temp, n[0] + n[1]);
	temp = cat(temp, n[0] + n[2]);
	temp = cat(temp, n[0] + n[3]);
	temp = cat(temp, n[0] + n[4]);
	//temp = cat(temp, n[0] + n[5]);
	temp = cat(temp, n[1] + n[2]);
	//temp = cat(temp, n[1] + n[3]);
	temp = cat(temp, n[1] + n[4]);
	temp = cat(temp, n[1] + n[5]);
	temp = cat(temp, n[2] + n[3]);
	//temp = cat(temp, n[2] + n[4]);
	temp = cat(temp, n[2] + n[5]);
	temp = cat(temp, n[3] + n[4]);
	temp = cat(temp, n[3] + n[5]);
	temp = cat(temp, n[4] + n[5]);
	return temp;
}

long long surface(long long n[6]) {
	long long temp = 2e9;
	temp = cat(temp, n[0]);
	temp = cat(temp, n[1]);
	temp = cat(temp, n[2]);
	temp = cat(temp, n[3]);
	temp = cat(temp, n[4]);
	temp = cat(temp, n[5]);
	return temp;
}

int main() {
	long long n;
	long long nums[6];
	scanf("%lld", &n);
	scanf("%lld %lld %lld %lld %lld %lld", &nums[0], &nums[1], &nums[4], &nums[2], &nums[3], &nums[5]);

	long long c = corner(nums);
	long long e = edge(nums);
	long long s = surface(nums);
	long long cu = cube(nums);
	if (n == 1) {
		printf("%lld", cu);
	}
	else {
		long long sum = 0;
		long long cc = sum += 4 * c + 4 * e;
		long long ee = (n - 2) * 8 * e + 4 * (n - 2) * s;
		long long ss = 5 * (n - 2) * (n - 2) * s;
		sum = cc + ee + ss;
		printf("%lld\n", sum);
	}
	return 0;
}