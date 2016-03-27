
#include <iostream>
#include <stack>
#include <fstream>
#include <string>


using namespace std;

/*chuyen tu trung to qua hau to*/
string convertInfixToPostfix(string Str);

bool isPriority(char operator1, char operator2);

bool isOperator(char C);

bool isOperand(char C);

////////////////////////////////////////////////////

string convertInfixToPostfix(string Str) { //doi tu trung to sang hau to

	stack<char> myStack;//khoi tao stack
	string rePostfix = "";
	for (int i = 0; i< Str.length(); i++) {
		if (Str[i] == ' ') {//neu la khoang trang thi tiep tuc
			continue;
		}		
		else if (isOperator(Str[i])) { 
			while (!myStack.empty() && myStack.top() != '(' && isPriority(myStack.top(), Str[i])) {//
				rePostfix = rePostfix + myStack.top();
				myStack.pop();
			}
			myStack.push(Str[i]);
		}
		
		else if (isOperand(Str[i])) {// neu la toan hang, them vao postfix
			rePostfix = rePostfix + Str[i];
		}
		else if (Str[i] == '(') {
			myStack.push(Str[i]);
		}
		else if (Str[i] == ')') {
			while (!myStack.empty() && myStack.top() != '(') {
				rePostfix = rePostfix + myStack.top();
				myStack.pop();
			}
			myStack.pop();
		}
	}

	while (!myStack.empty()) {
		rePostfix = rePostfix + myStack.top();
		myStack.pop();
	}

	return rePostfix;
}



bool isOperand(char ch) {	//kiem tra xem co la so
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	return false;
}


bool isOperator(char C) {	//kiem tr xem co la toan tu
	if (C == '+' || C == '-' || C == '*' || C == '/') {
		return true;
	}
	return false;
}



int getPriority(char oper) { // tinh do uu tien toan tu
	int pri = 0;
	switch (oper) {
		case '+':
		case '-':
			pri = 1;
		case '*':
		case '/':
			pri = 2;			
	};
	return pri;
}


bool isPriority(char o1, char o2) { //
	int prio1 = getPriority(o1);
	int prio2 = getPriority(o2);

	if (prio1 >= prio2) {
		return true;
	}
	return false;	
}


int calc(int n1, int n2, char operater) {
	switch (operater) {
	case '+':
		return n2 + n1;
	case '-':
		return n2 - n1;
	case '*':
		return n2 * n1;
	case '/': 
		return n2 / n1;
	
	default: 
		return 0;
	}
}
int calcPostfix(string post) {
	int size = post.length();

	stack<int> s;// khai bao stack rong
	
	char ch;
	int result = 0;
	int i = 0;
	while (i < size) {//lap cho moi phan tu i
		ch = post[i];
		if (isdigit(ch)) {// neu post[i] la toan hang, doi ve so, push vao s
			s.push(ch - '0');
		}
		else {// neu post[i]  la toan tu, lay ra 2 so, tinh, them lai vao s
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			result = calc(op1, op2, ch);
			
			s.push(result);
		}
		i++;
	}
	return result;
}


//**************************************//
//Doc ghi file

string readFile(string FileName) {
	fstream f;
	f.open(FileName, ios_base::in);

	string data;
	getline(f, data);

	f.close();
	return data;
}

void writeFile(string FileName, string data) {
	fstream f;
	f.open(FileName, ios_base::out);
	f << data;
	f.close();
}
string toString(int num) {
	return to_string(num);
}