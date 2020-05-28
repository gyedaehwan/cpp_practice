#include "String.h"

//�⺻ ������
String::String() : String(10)
{

}
//ũ�Ⱑ m+1�� char�� �迭�� ����� ������
String::String(int m) {
	size = m + 1;
	buffer = new char[m + 1];
	length = 0;
	buffer[0] = ' ';
	buffer[1] = '\0';
	isp = 0;
	icp = 0;
}
String::String(char* init, int m) :String(m) {
	//m��ŭ for���� ���鼭 init�� ���� ���� buffer�迭�� ���� 
	for (int i = 0; i < m; i++) {
		buffer[i] = init[i];
	}
	//���ڸ� null
	buffer[m] = '\0';
	//���ڿ��� ���̴� m , �迭�� ��üũ��� m+1
	length = m;
}


//�Ҹ���
String::~String() {
		delete[] buffer;
}

//���������
String::String(const String& s) : String(s.length + 1) {
	//for���� �Էµ� �����迭�� ���ڿ� ���� ��ŭ���鼭 buffer�� �Ѱ��� ����
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	//������ �ε����� null
	buffer[s.length] = '\0';
	length = s.length;
}


void String::setBuffer(char c) {
	if (length >= size) {
		char* newBuffer = new char[size * 2];
		memcpy(newBuffer, buffer, sizeof(char) * size);
		newBuffer[length] = c;
		delete[] buffer;
		buffer = newBuffer;
		size *= 2;
	}

	else
		buffer[length] = c;
	length++;

}

void String::deleteBuffer() {
	delete[] buffer;
	buffer = new char[size];
	length = 0;
}


char* String::getBuffer() {
	return buffer;
}

//������ �� ��ȯ
int String::Length() {
	return length;
}

//�ε��� i ~ j ������ ���ڿ� ��ȯ 
String String::substr(int start, int end) {


	String result(length);
	int result_count = 0;
	for (int i = start; i < end + 1; i++, result_count++) {
		if (buffer[i] != '\0')
			result.buffer[result_count] = buffer[i];
		else {
			cout << "�ε��� ������ ���� �ʽ��ϴ�." << endl;
			return *this;
		}
	}
	result.buffer[result_count + 1] = '\0';
	result.length = result_count;

	return result;
}


void String::print() {

	cout << "String �� print() : ";
	for (int i = 0; i < length; i++) {
		cout << buffer[i];
	}
	cout << endl;
}


//���ڿ� ������ = operator ����Ͽ� ���ڿ� ����
//���Կ����� �����ε�
String String::operator=(const String& s) {
	//������ buffer �迭�� �޸� �Ҵ� ����

	delete[] buffer;
	buffer = new char[s.length + 1];

	//for���� �Էµ� �����迭�� ���ڿ� ���� ��ŭ���鼭 buffer�� �Ѱ��� ����
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	//������ �ε����� null
	buffer[s.length] = '\0';
	length = s.length;

	return *this;
}

void String::setAllBuffer(char* c) {
	if (c == NULL){
		buffer = c;
	}
	else {
		buffer = c;
		for (; c[length] != '\0'; length++);
	}
}

void String::deleteChar() {
	char* newbuffer = new char[size];
	for (int i = 0; i < length - 1; i++) {
		newbuffer[i] = buffer[i];
	}
	newbuffer[length-1] = '\0';
	delete[] buffer;
	buffer = newbuffer;

}


void String::setIsp(int isp) {
	this->isp = isp;
	
}


int String::getIsp() {
	return isp;
}