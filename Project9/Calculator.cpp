#include "Calculator.h"
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


Calculator::Calculator() {
	errCode = 0;
}

Calculator::~Calculator() {
}

//만들 postFix에 문자를 추가하는 함수
void Calculator::editPostFix(String tokenString) {
	
	//기존 postFix에 \0 이 있는 경우 띄어쓰기로 바꿔줌
	if (postFix.getBuffer()[postFix.Length() - 1] == '\0')
		postFix.getBuffer()[postFix.Length() - 1] = ' ';


	for (int i = 0; i < tokenString.Length(); i++) {
		postFix.setBuffer(tokenString.getBuffer()[i]);
	}

	//맨 끝에 \0을 붙혀줌
	postFix.setBuffer('\0');

}

//postFix로 만드는 함수
String Calculator::makePostFix() {
	//스텍 생성 (부호를 넣기위함)
	Stack<String> stack;

	//tokens의 string개수 ,stringCount
	int stringCount = tokens.returnStringCount();
	
	//0부터 stringCount 까지 
	for (int i = 0; i < stringCount; i++) {
		
		//토큰의 각 String을 담아둘 String 객체생성
		String tokenString = tokens.getString(i);

		// 문자가 + 인경우
		if (strcmp(tokenString.getBuffer(), "+") == 0) {
			//isp 2로 설정
			tokenString.setIsp(2);

			//top스택이 비어있는지 확인 (stack 의 stringcount ==0)
			if (stack.returnStringCount() == 0 ) {
				//연산자 스택에 + 추가
				stack.addString(tokenString.getBuffer(), 1);
				//연산자 스택의 top의 isp를 2로 설정
				stack.setIsp(2);
			}

			//top스텍이 비어있지 않은경우 
			else {
				//연산자 스텍 top 스트링 보다 isp가 크거나 같은 경우
				if (stack.getIsp() <= tokenString.getIsp()) {

					//스텍 top의 원소를 postFix에 추가
					editPostFix(stack.getTopString());
					//연산자 스텍에 top 스트링을 지우고
					stack.deleteTopString();
					//+ 를 스텍에 추가
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);
				}
				//연산자 스텍 top 스트링 보다 isp가 작은경우
				//그냥 top에 추가
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);

				}
			}
		}

		// 문자가 - 인경우
		else if (strcmp(tokenString.getBuffer(), "-") == 0) {

			//isp 2로 설정
			tokenString.setIsp(2);

			//top스택이 비어있는지 확인 (stack 의 stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(2);
			}
			else {
				//스텍 top 스트링 보다 isp가 큰경우
				if (stack.getIsp() <= tokenString.getIsp()) {

					//스텍 top의 원소를 postFix에 추가
					editPostFix(stack.getTopString());
					//스텍에 top 스트링을 지우고
					stack.deleteTopString();
					//- 를 스텍에 추가
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);
				}
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(2);

				}
			}
		}

		// 문자가 * 인경우
		else if (strcmp(tokenString.getBuffer(), "*") == 0) {
			//isp 1로 설정
			tokenString.setIsp(1);


			//top스택이 비어있는지 확인 (stack 의 stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(1);
			}
			else {
				// 스텍의 top스트링이랑 isp가 같은경우
				// top스트링을 내보내고 자신이 top스트링이 됨
				if (stack.getIsp() == tokenString.getIsp()) {
					
					//스텍 top의 원소를 postFix에 추가
					editPostFix(stack.getTopString());

					//스텍에 top 스트링을 지우고
					stack.deleteTopString();
					// * 를 스텍에 추가
					stack.addString(tokenString.getBuffer(), 1);
					//스텍의  top 의 isp 를 1로 설정
					stack.setIsp(1);
				}
				//그렇지 않은 경우는 그냥 자신이 top스트링이됨
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
			}
		}

		// 문자가 / 인경우
		else if (strcmp(tokenString.getBuffer(), "/") == 0) {
			tokenString.setIsp(1);


			//top스택이 비어있는지 확인 (stack 의 stringcount ==0)
			if (stack.returnStringCount() == 0) {
				stack.addString(tokenString.getBuffer(), 1);
				stack.setIsp(1);
			}
			else {
				// 스텍의 top스트링이랑 isp가 같은경우
				// top스트링을 내보내고 자신이 top스트링이 됨
				if (stack.getIsp() == tokenString.getIsp()) {

					//스텍 top의 원소를 postFix에 추가
					editPostFix(stack.getTopString());

					//스텍에 top 스트링을 지우고
					stack.deleteTopString();
					// / 를 스텍에 추가
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
				//그렇지 않은 경우는 그냥 자신이 top스트링이됨
				else {
					stack.addString(tokenString.getBuffer(), 1);
					stack.setIsp(1);
				}
			}
		}

		//좌 괄호는 그냥 top스트링에 추가
		else if (strcmp(tokenString.getBuffer(), "(") == 0) {

			stack.addString(tokenString.getBuffer(), 1);
			stack.setIsp(3);
			
			}

		// 우 괄호는 스텍에 좌괄호가 나올때까지 스텍 -1 하면서
		// 순서대로 출력
		else if (strcmp(tokenString.getBuffer(), ")") == 0) {

			
			// 좌 괄호가 오기 전까지
			for(int i=stack.returnStringCount() ; stack.getTopString().getBuffer()[0] != '(';i-- ){
				//스텍 top의 원소를 postFix에 추가
				editPostFix(stack.getTopString());
				stack.deleteTopString();

			}
			// 값을 다 빼고 좌괄호를 만났을 때
			// 좌괄호를 스텍에서 지워줌
			if (stack.getTopString().getBuffer()[0] == '('){
				
				stack.deleteTopString();
			}

		}

		//부호가 아닌경우는 그냥 postFix에 바로 넣음 문자 + \0 로 넣어줌
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

// 정렬된 postFix 를 통해 계산 하는 함수
int Calculator::evaluation() {
	
	//피연산자들을 받을 스텍 생성
	Stack<String> stack_num;

	//
	String array;
	char* context=NULL;

	//맨 앞에 있는 문자를 우선 입력
	array.setAllBuffer(strtok_s(postFix.getBuffer(), " ", &context));

	

	while (array.getBuffer() != NULL) {
		//연산자 일때
		if (array.getBuffer()[0] == '+' || array.getBuffer()[0] == '-' || array.getBuffer()[0] == '*'
			|| array.getBuffer()[0] == '/') {

			//String객체 개수 변수
			int stringCount = stack_num.returnStringCount();

			
			//먼저 들어온 숫자
			int num_1 = atoi(stack_num.getString(stringCount-2).getBuffer());

			//다음에 들어온 숫자  ( stack_num의 Top )
			int num_2 = atoi(stack_num.getTopString().getBuffer());

			//계산 결과값
			int result=0;

			//결과값 변환을 위한 임시 char형 배열
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

			//Top을 2번 지우고 ( Pop 2회 실행 )
			stack_num.deleteTopString();
			stack_num.deleteTopString();

			
			//10진수인 result값을 char * 형 문자열로 바꾸어 buff에 삽입
			_itoa_s(result, buff, 10);

			//buff 에 들어있는 문자들의 개수 count 
			for (; buff[count] != '\0'; count++);

			//Top에 결과를 추가
			stack_num.addString(buff,count);
		}

		else{

			//피연산자는 피연산자 스텍에 하나씩 삽입
			stack_num.addString(array.getBuffer(), array.Length());

		}

		array.setAllBuffer(strtok_s(NULL," ",&context));

	}
	


	return atoi(stack_num.getTopString().getBuffer());

}


int Calculator::setExpression(const char* expr) {
	//입력받은 char * 문자 개수 count를 위한 변수
	int expr_count = 0;

	//token에 들어갈 String객체를 구분해주기 위한 객체 생성
	String input;

	//0번 문자부터 시작
	for (; ; expr_count++ ) {

		// 입력 오류
		//입력 시작부터 띄어쓰기
		if (expr[0] == ' ') {
			//입력 오류시 errCode = 1
			errCode = 1;
			cout << "입력 오류" << endl;
			return errCode;
		}

		//\0 문자가 그 전에 String의 buffer에 쌓아둔 문자들 token에 추가 및 for문 탈출
		if (expr[expr_count] == '\0') {
			tokens.addString(input.getBuffer(), input.Length());
			break;
		}

		//띄어쓰기가 감지되면 이 전에 String의 buffer에 쌓아둔 문자들을 token에 추가
		//추가 후에 String객체의 buffer 초기화
		if (expr[expr_count] == ' ') {
			tokens.addString(input.getBuffer(), input.Length());
			input.deleteBuffer();
		}

		//띄어쓰기, \0문자를 구분하고 아닌 문자들은 String객체의 buffer에 임시로 추가
		else 
			input.setBuffer(expr[expr_count]);
	}

	//postFix로 순서를 조정하는 함수
	makePostFix();
	
	//에러코드 리턴 , 0: 정상 1:오류
	return errCode;
}

//계산된 최종결과를 반환
int Calculator::getValue() {

	return evaluation();
}

//정렬된 postFix를 반환
String Calculator::getPostFix() {

	return postFix;
}

//에러코드 반환
int Calculator::getErrorCode() {
	return errCode;
}