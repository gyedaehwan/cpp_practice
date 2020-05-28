#include "Calculator.h"
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


Calculator::Calculator() {
	errCode = 0;
}

Calculator::~Calculator() {
}

//���� postFix�� ���ڸ� �߰��ϴ� �Լ�
void Calculator::editPostFix(String tokenString) {
	
	//���� postFix�� \0 �� �ִ� ��� ����� �ٲ���
	if (postFix.getBuffer()[postFix.Length() - 1] == '\0')
		postFix.getBuffer()[postFix.Length() - 1] = ' ';


	for (int i = 0; i < tokenString.Length(); i++) {
		postFix.setBuffer(tokenString.getBuffer()[i]);
	}

	//�� ���� \0�� ������
	postFix.setBuffer('\0');

}

//postFix�� ����� �Լ�
String Calculator::makePostFix() {
	//���� ���� (��ȣ�� �ֱ�����)
	Stack<String> stack;

	//tokens�� string���� ,stringCount
	int stringCount = tokens.returnStringCount();
	
	//0���� stringCount ���� 
	for (int i = 0; i < stringCount; i++) {
		
		//��ū�� �� String�� ��Ƶ� String ��ü����
		String tokenString = tokens.getString(i);

		// ���ڰ� + �ΰ��
		if (strcmp(tokenString.getBuffer(), "+") == 0) {
			//isp 2�� ����
			tokenString.setIsp(2);

			//top������ ����ִ��� Ȯ�� (stack �� stringcount ==0)
			if (stack.returnStringCount() == 0 ) {
				//������ ���ÿ� + �߰�
				stack.addString(tokenString.getBuffer(), 1);
				//������ ������ top�� isp�� 2�� ����
				stack.setIsp(2);
			}

			//top������ ������� ������� 
			else {
				//������ ���� top ��Ʈ�� ���� isp�� ũ�ų� ���� ���
				if (stack.getIsp() <= tokenString.getIsp()) {

					//���� top�� ���Ҹ� postFix�� �߰�
					editPostFix(stack.getTopString());
					//������ ���ؿ� top ��Ʈ���� �����
					stack.deleteTopString();
					//+ �� ���ؿ� �߰�
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);
				}
				//������ ���� top ��Ʈ�� ���� isp�� �������
				//�׳� top�� �߰�
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);

				}
			}
		}

		// ���ڰ� - �ΰ��
		else if (strcmp(tokenString.getBuffer(), "-") == 0) {

			//isp 2�� ����
			tokenString.setIsp(2);

			//top������ ����ִ��� Ȯ�� (stack �� stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(2);
			}
			else {
				//���� top ��Ʈ�� ���� isp�� ū���
				if (stack.getIsp() <= tokenString.getIsp()) {

					//���� top�� ���Ҹ� postFix�� �߰�
					editPostFix(stack.getTopString());
					//���ؿ� top ��Ʈ���� �����
					stack.deleteTopString();
					//- �� ���ؿ� �߰�
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);
				}
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);

				}
			}
		}

		// ���ڰ� * �ΰ��
		else if (strcmp(tokenString.getBuffer(), "*") == 0) {
			//isp 1�� ����
			tokenString.setIsp(1);


			//top������ ����ִ��� Ȯ�� (stack �� stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(1);
			}
			else {
				// ������ top��Ʈ���̶� isp�� �������
				// top��Ʈ���� �������� �ڽ��� top��Ʈ���� ��
				if (stack.getIsp() == tokenString.getIsp()) {
					
					//���� top�� ���Ҹ� postFix�� �߰�
					editPostFix(stack.getTopString());

					//���ؿ� top ��Ʈ���� �����
					stack.deleteTopString();
					// * �� ���ؿ� �߰�
					stack.addString(tokenString.getBuffer(), 1);
					//������  top �� isp �� 1�� ����
					stack.setIsp(1);
				}
				//�׷��� ���� ���� �׳� �ڽ��� top��Ʈ���̵�
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
			}
		}

		// ���ڰ� / �ΰ��
		else if (strcmp(tokenString.getBuffer(), "/") == 0) {
			tokenString.setIsp(1);


			//top������ ����ִ��� Ȯ�� (stack �� stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(1);
			}
			else {
				// ������ top��Ʈ���̶� isp�� �������
				// top��Ʈ���� �������� �ڽ��� top��Ʈ���� ��
				if (stack.getIsp() == tokenString.getIsp()) {

					//���� top�� ���Ҹ� postFix�� �߰�
					editPostFix(stack.getTopString());

					//���ؿ� top ��Ʈ���� �����
					stack.deleteTopString();
					// / �� ���ؿ� �߰�
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
				//�׷��� ���� ���� �׳� �ڽ��� top��Ʈ���̵�
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
			}
		}

		//�� ��ȣ�� �׳� top��Ʈ���� �߰�
		else if (strcmp(tokenString.getBuffer(), "(") == 0) {

			stack.addString(tokenString.getBuffer(), 1);
			stack.setIsp(3);
			
			}

		// �� ��ȣ�� ���ؿ� �°�ȣ�� ���ö����� ���� -1 �ϸ鼭
		// ������� ���
		else if (strcmp(tokenString.getBuffer(), ")") == 0) {

			
			// �� ��ȣ�� ���� ������
			for(int i=stack.returnStringCount() ; stack.getTopString().getBuffer()[0] != '(';i-- ){
				//���� top�� ���Ҹ� postFix�� �߰�
				editPostFix(stack.getTopString());
				stack.deleteTopString();

			}
			// ���� �� ���� �°�ȣ�� ������ ��
			// �°�ȣ�� ���ؿ��� ������
			if (stack.getTopString().getBuffer()[0] == '('){
				
				stack.deleteTopString();
			}

		}

		//��ȣ�� �ƴѰ��� �׳� postFix�� �ٷ� ���� ���� + \0 �� �־���
		else 
			editPostFix(tokenString);



	}


	if (stack.returnStringCount() != 0) {
		for (int j = stack.returnStringCount(); j != 0; j--) {
			editPostFix(stack.getTopString());
			stack.minusStringCount();
		}
	}

	String s;
	return s;
}

// ���ĵ� postFix �� ���� ��� �ϴ� �Լ�
int Calculator::evaluation() {
	
	//�ǿ����ڵ��� ���� ���� ����
	Stack<String> stack_num;

	//
	String array;
	char* context=NULL;

	//�� �տ� �ִ� ���ڸ� �켱 �Է�
	array.setAllBuffer(strtok_s(postFix.getBuffer(), " ", &context));

	

	while (array.getBuffer() != NULL) {
		//������ �϶�
		if (array.getBuffer()[0] == '+' || array.getBuffer()[0] == '-' || array.getBuffer()[0] == '*'
			|| array.getBuffer()[0] == '/') {

			//String��ü ���� ����
			int stringCount = stack_num.returnStringCount();

			
			//���� ���� ����
			int num_1 = atoi(stack_num.getString(stringCount-2).getBuffer());

			//������ ���� ����  ( stack_num�� Top )
			int num_2 = atoi(stack_num.getTopString().getBuffer());

			//��� �����
			int result=0;

			//����� ��ȯ�� ���� �ӽ� char�� �迭
			char buff[256];


			int count = 1;

			if (array.getBuffer()[0] == '+') {
				result = num_1 + num_2;
			}
			else if (array.getBuffer()[0] == '-') {
				result = num_1 - num_2;
			}
			else if (array.getBuffer()[0] == '*') {
				result = num_1 * num_2;
			}
			else{
				result = num_1 / num_2;
			}

			//Top�� 2�� ����� ( Pop 2ȸ ���� )
			stack_num.deleteTopString();
			stack_num.deleteTopString();

			
			//10������ result���� char * �� ���ڿ��� �ٲپ� buff�� ����
			_itoa_s(result, buff, 10);

			//buff �� ����ִ� ���ڵ��� ���� count 
			for (; buff[count] != '\0'; count++);

			//Top�� ����� �߰�
			stack_num.addString(buff,count);
		}

		else{

			//�ǿ����ڴ� �ǿ����� ���ؿ� �ϳ��� ����
			stack_num.addString(array.getBuffer(), array.Length());

		}

		array.setAllBuffer(strtok_s(NULL," ",&context));

	}
	


	return atoi(stack_num.getTopString().getBuffer());

}


int Calculator::setExpression(const char* expr) {
	//�Է¹��� char * ���� ���� count�� ���� ����
	int expr_count = 0;

	//token�� �� String��ü�� �������ֱ� ���� ��ü ����
	String input;

	//0�� ���ں��� ����
	for (; ; expr_count++ ) {

		// �Է� ����
		//�Է� ���ۺ��� ����
		if (expr[0] == ' ') {
			//�Է� ������ errCode = 1
			errCode = 1;
			cout << "�Է� ����" << endl;
			return errCode;
		}

		//\0 ���ڰ� �� ���� String�� buffer�� �׾Ƶ� ���ڵ� token�� �߰� �� for�� Ż��
		if (expr[expr_count] == '\0') {
			tokens.addString(input.getBuffer(), input.Length());
			break;
		}

		//���Ⱑ �����Ǹ� �� ���� String�� buffer�� �׾Ƶ� ���ڵ��� token�� �߰�
		//�߰� �Ŀ� String��ü�� buffer �ʱ�ȭ
		if (expr[expr_count] == ' ') {
			tokens.addString(input.getBuffer(), input.Length());
			input.deleteBuffer();
		}

		//����, \0���ڸ� �����ϰ� �ƴ� ���ڵ��� String��ü�� buffer�� �ӽ÷� �߰�
		else 
			input.setBuffer(expr[expr_count]);
	}

	//postFix�� ������ �����ϴ� �Լ�
	makePostFix();
	
	//�����ڵ� ���� , 0: ���� 1:����
	return errCode;
}

//���� ��������� ��ȯ
int Calculator::getValue() {

	return evaluation();
}

//���ĵ� postFix�� ��ȯ
String Calculator::getPostFix() {

	return postFix;
}

//�����ڵ� ��ȯ
int Calculator::getErrorCode() {
	return errCode;
}