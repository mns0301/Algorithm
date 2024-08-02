#include <stdio.h>
int hanoi1(int n, int start, int nontarget, int target); //홀수
int hanoi2(int n, int start, int nontarget, int target); //짝수
int count(int n);

int main() {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", count(n));
	if (n % 2 == 0) hanoi2(n, 1, 2, 3);
	else hanoi1(n, 1, 2, 3);
	return 0;
}

int hanoi1(int n, int start, int nontarget, int target) {
	//f(홀수) = start > target, start > target, nontarget > start
	if (n == 1) {
		printf("%d %d\n", start, target);
		return 0;
	}

	hanoi2(n - 1, start, target, nontarget);
	printf("%d %d\n", start, target);
	hanoi2(n - 1, nontarget, start, target);
	return n;
}

int hanoi2(int n, int start, int nontarget, int target) {
	//f(짝수) = start > nontarget, start > target, nontarget > target
	hanoi1(n - 1, start, target, nontarget);
	printf("%d %d\n", start, target);
	hanoi1(n - 1, nontarget, start, target);
	return n;
}

int count(int n) {
	if (n == 1) return 1;
	return count(n - 1) * 2 + 1;
}
