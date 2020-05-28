

#include <iostream>
#include "Calculator.h"

using namespace std;

ostream& operator<<(ostream& os, String& s) {
	char* c = new char[s.Length()];
	c = s.getBuffer();
	c[s.Length()] = '\0';
	cout << c;
	return os;
}

int main(void) {
	Calculator c;

		char expr[1000];
		cout << "수식을 입력하시오 : ";
		cin.getline(expr, 1000);

		try {
			c.setExpression(expr);
			String postfix = c.getPostFix();
			cout <<"후위표기식 : "<< postfix<< " 결과값 : " << c.getValue() << endl;

		}
		catch (const char* msg) {
			cout << "x" << endl;
			cout << msg << endl;
			return 0;
		}
		return 0;
 }