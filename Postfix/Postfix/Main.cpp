#include <iostream>
#include <stack>
using namespace std;

float PostCalc(char* Ex, int n) {
	stack<int> S;
	for (int i = 0; i < n; i++) {
		if (Ex[i] >= '0' && Ex[i] <= '9') {
			S.push((int)Ex[i]);
		}
		else {
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			switch (Ex[i]) {
			case '+':
				break;
			case '-':
				break;
			case '*':
				break;
			case ':':
				break;
			}
		}
	}
}
