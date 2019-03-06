#pragma once
#include "Role.h"
#include <iostream>

using namespace std;
class Nanny: public Role
{
private:
	string file;
	int leftBorder, rightBorder;
public:
	Nanny() { file = "images/Nanny.png"; };
	int Work(int type) {
		return 0;
	}
	string getFile() { return file; }
	void setLeftBorder(int value) { leftBorder = value; }
	void setRightBorder(int value) { rightBorder = value; }
	int getLeftBorder() { return leftBorder; }
	int getRightBorder() { return rightBorder; }
	~Nanny() {};
};

