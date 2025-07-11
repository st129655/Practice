#include<iostream>
int fib(int a) {
	if (a == 1) {
		return 1;
	}
	else if (a == 2) {
		return 1;
	}
	else if (a > 2) {
		return (fib(a - 2) + fib(a - 1));
	}
}
int fact(int a) {
	if (a == 0) {
		return 1;
	}
	if (a > 1) {
		return a * fact(a - 1);
	}
}
void hanoi(int height, int from, int to) {
	if (height == 1) {
		printf("%d %d %d\n", 1, from, to);
		return;
	}
	int reserve = 6 - from - to;
	hanoi(height - 1, from, reserve);
	printf("%d %d %d\n", height, from, to);
	hanoi(height - 1, reserve, to);
}
int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	hanoi(n, 1, 3);
	return 0;
}