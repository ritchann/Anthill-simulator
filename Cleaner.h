#pragma once
#include "Role.h"
#include <iostream>

using namespace std;
class Cleaner:public Role
{
private:
	string file;
	int leftBorder, rightBorder;
public:
	Cleaner() { file = "images/Cleaner.png"; };
	int Work(int type) {
		if (type == 1) return 1;
		else  return 0;
	}
	string getFile() { return file; }
	void setLeftBorder(int value) { leftBorder = value; }
	void setRightBorder(int value) { rightBorder = value; }
	int getLeftBorder() { return leftBorder; }
	int getRightBorder() { return rightBorder; }
	~Cleaner() {};
};

