#include "Stack.h"
#include <string.h>



//생성자와 소멸자
template <class T>
Stack<T>::Stack() {
	stringCount = 0; // 데이터의 개수
	size = 10; //배열의 크기
	strings = new T[size];
	top_isp = 0;
}

template <class T>
Stack<T>::~Stack() {
	delete[] strings;
}

template <class T>
T Stack<T>::getString(int index) {

	if (index < stringCount)
		return strings[index];
	else
		return -9999;
}


//스트링을 추가, Push 와 같은 역할
template <class T>
void Stack<T>::addString(char* c, int count) {


	String s(c, count);
	if (stringCount < size) {
		strings[stringCount] = s;
		stringCount++;


	}
	else {
		String* newstrings = new String[size * 2];
		for (int i = 0; i < stringCount; i++) {
			newstrings[i] = strings[i];

		}
		newstrings[stringCount] = s;

		delete[] strings;
		strings = newstrings;
		stringCount++;
		size *= 2;
	}


}

template <class T>
void Stack<T>::print() {
	for (int i = 0; i < stringCount; i++) {
		cout << i << "안의 값 : " << strings[i].getBuffer() << endl;
		cout << "stringCount : " << stringCount << endl;
	}
}

template <class T>
int Stack<T>::returnStringCount() {
	return stringCount;

}


//top 스트링을 반환, Top과 같은 역할
template <class T>
T Stack<T>::getTopString() {
	if (stringCount <= 0)
		throw "List_string is empty";
	else
		return strings[stringCount - 1];
}

template <class T>
void Stack<T>::minusStringCount() {
	stringCount--;
}


//top 스트링을 삭제, Pop과 같은 역할
template <class T>
void Stack<T>::deleteTopString() {
	strings[stringCount - 1].deleteBuffer();
	minusStringCount();
}

template <class T>
void Stack<T>::setIsp(int isp) {
	this->top_isp = isp;
}

template <class T>
int Stack<T>::getIsp() {
	return top_isp;
}