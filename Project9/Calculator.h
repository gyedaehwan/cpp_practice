#include <iostream>
#include "List.cpp"
#include "Stack.cpp"

using namespace std;
class Calculator
{
private:
	List<String> tokens;

	//�����ڵ� :0 -> ��������, 1-> ��������
	int errCode;

	//����ǥ��� = ���� �������� �ʱ�ȭ
	String postFix;

	//postfix�� �����ϴ� �Լ�
	String makePostFix();

	// ��ȣ �켱���� ���� postFix �� �ִ� �Լ�
	void editPostFix(String);

	//postfix�� ����ϴ� �Լ�
	int evaluation();

public:

	Calculator();
	~Calculator();

	//void printTokens();

	// �����ڵ� ��ȯ
	int getErrorCode();

	// expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�            
	// ���࿡ ������ �������,  errcode = 1�� �����ϰ� 
	// �� ���� ����
	// ������ ���� ��� 0�� ����
	int setExpression(const char*);

	// ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����
	String getPostFix();

	// ���� ���� --> ���ܹ߻� "error"
	// ���� �������� --> ����� ����
	int getValue();
};