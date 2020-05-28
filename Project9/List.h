#pragma once
#include "String.h"
#include <iostream>
using namespace std;
template <class T>

class List {
private:
	T* strings;
	int stringCount;
	int size;
	int top_isp;


public:
	List();
	~List();

	T getString(int);
	void addString(char *,int);
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
