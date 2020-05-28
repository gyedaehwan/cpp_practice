#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* buffer;
	int length;
	int size;
	int isp;
	int icp;

public:
	String();
	String(int);

	String(char*, int);
	~String();
	String(const String&);
	void setBuffer(char);
	void setAllBuffer(char *);
	char* getBuffer();
	void deleteChar();
	void deleteBuffer();
	String operator=(const String&);
	int Length();
	String substr(int, int);


	void print();
	void setIsp(int);
	void setIcp(int);
	int getIsp();
	int getIcp();


};




