#include "List.h"
#include <string.h>



//생성자와 소멸자
template <class T>
List<T>::List() {
	stringCount = 0; // 데이터의 개수
	size = 10; //배열의 크기
	strings = new T[size];
	top_isp = 0;
}

template <class T>
List<T>::~List() {
	delete[] strings;
}

template <class T>
T List<T>::getString(int index) {

	if (index < stringCount)
		return strings[index];
	else
		return -9999;
}


template <class T>
void List<T>::addString(char* c , int count) {
	
	
	String s(c, count);
	if (stringCount < size) {
		strings[stringCount]=s;
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
void List<T>::print() {
	for (int i = 0; i < stringCount; i++) {
		cout << i<<"안의 값 : " << strings[i].getBuffer() << endl;
		cout << "stringCount : "<< stringCount << endl;
	}
}

template <class T>
int List<T>::returnStringCount() {
	return stringCount;

}

template <class T>
T List<T>::getTopString() {
	if (stringCount <= 0)
		throw "List_string is empty";
	else
		return strings[stringCount-1];
}

template <class T>
void List<T>::minusStringCount() {
	stringCount--;
}

template <class T>
void List<T>::deleteTopString() {
	getTopString().deleteBuffer();
	minusStringCount();
}

template <class T>
void List<T>::setIsp(int isp) {
	this->top_isp = isp;
}

template <class T>
int List<T>::getIsp() {
	return top_isp;
}