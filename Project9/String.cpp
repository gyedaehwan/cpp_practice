#include "String.h"

//기본 생성자
String::String() : String(10)
{

}
//크기가 m+1인 char형 배열을 만드는 생성자
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
	//m만큼 for문을 돌면서 init의 값을 기존 buffer배열에 삽입 
	for (int i = 0; i < m; i++) {
		buffer[i] = init[i];
	}
	//끝자리 null
	buffer[m] = '\0';
	//문자열의 길이는 m , 배열의 전체크기는 m+1
	length = m;
}


//소멸자
String::~String() {
		delete[] buffer;
}

//복사생성자
String::String(const String& s) : String(s.length + 1) {
	//for문을 입력된 참조배열의 문자열 길이 만큼돌면서 buffer에 한값씩 삽입
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	//마지막 인덱스에 null
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

//문자의 수 반환
int String::Length() {
	return length;
}

//인덱스 i ~ j 사이의 문자열 반환 
String String::substr(int start, int end) {


	String result(length);
	int result_count = 0;
	for (int i = start; i < end + 1; i++, result_count++) {
		if (buffer[i] != '\0')
			result.buffer[result_count] = buffer[i];
		else {
			cout << "인덱스 범위가 맞지 않습니다." << endl;
			return *this;
		}
	}
	result.buffer[result_count + 1] = '\0';
	result.length = result_count;

	return result;
}


void String::print() {

	cout << "String 내 print() : ";
	for (int i = 0; i < length; i++) {
		cout << buffer[i];
	}
	cout << endl;
}


//문자열 선언후 = operator 사용하여 문자열 삽입
//대입연산자 오버로딩
String String::operator=(const String& s) {
	//기존의 buffer 배열의 메모리 할당 해제

	delete[] buffer;
	buffer = new char[s.length + 1];

	//for문을 입력된 참조배열의 문자열 길이 만큼돌면서 buffer에 한값씩 삽입
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	//마지막 인덱스에 null
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