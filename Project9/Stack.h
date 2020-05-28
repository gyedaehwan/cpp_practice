#pragma once
#include "String.h"
#include <iostream>
using namespace std;
template <class T>

class Stack {
private:
	T* strings;
	int stringCount;
	int size;
	int top_isp;


public:
	Stack();
	~Stack();

	T getString(int);
	void addString(char*, int);
	int returnStringCount();
	//printÇÔ¼ö
	void print();

	//get
	T getTopString();

	void deleteTopString();

	void minusStringCount();

	void setIsp(int);
	int getIsp();


};

