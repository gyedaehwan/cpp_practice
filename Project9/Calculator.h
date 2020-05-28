#include <iostream>
#include "List.cpp"
#include "Stack.cpp"

using namespace std;
class Calculator
{
private:
	List<String> tokens;

	//오류코드 :0 -> 오류없음, 1-> 오류있음
	int errCode;

	//후위표기식 = 최초 공백으로 초기화
	String postFix;

	//postfix로 변경하는 함수
	String makePostFix();

	// 부호 우선순위 비교후 postFix 에 넣는 함수
	void editPostFix(String);

	//postfix를 계산하는 함수
	int evaluation();

public:

	Calculator();
	~Calculator();

	//void printTokens();

	// 오류코드 반환
	int getErrorCode();

	// expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수            
	// 만약에 오류가 있을경우,  errcode = 1로 변경하고 
	// 그 값을 리턴
	// 오류가 없을 경우 0을 리턴
	int setExpression(const char*);

	// 변환된 후위표기식을 반환   --> 오류가 있을경우 최초값인 공백이 리턴
	String getPostFix();

	// 수식 오류 --> 예외발생 "error"
	// 수식 오류없음 --> 결과값 리턴
	int getValue();
};