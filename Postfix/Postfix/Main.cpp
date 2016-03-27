#include <iostream>
#include <stack>
#include "lib.h"
using namespace std;


void main(int argc, char* argv[]) {
	char* Fin = argv[1];
	char* Fout = argv[2];
	string infix = readFile(Fin);
	writeFile(Fout, toString(calcPostfix(convertInfixToPostfix(infix))));
	
	cout << "OK";
	
}