#include "Stack.h"
#include <string.h>



//�����ڿ� �Ҹ���
template <class T>
Stack<T>::Stack() {
	stringCount = 0; // �������� ����
	size = 10; //�迭�� ũ��
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


//��Ʈ���� �߰�, Push �� ���� ����
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
		cout << i << "���� �� : " << strings[i].getBuffer() << endl;
		cout << "stringCount : " << stringCount << endl;
	}
}

template <class T>
int Stack<T>::returnStringCount() {
	return stringCount;

}


//top ��Ʈ���� ��ȯ, Top�� ���� ����
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


//top ��Ʈ���� ����, Pop�� ���� ����
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