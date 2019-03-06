#pragma once
#include "Role.h"
#include <iostream>
#include <ctime>

using namespace std;
class Baby : public Role
{
private:
	string file;

	int leftBorder, rightBorder;
public:
	Baby() {file = "images/Baby.png";}
	int Work(int type) { return 0; }
	string getFile() { return file; }
	void setLeftBorder(int value) { leftBorder = value; }
	void setRightBorder(int value) { rightBorder = value; }
	int getLeftBorder() { return leftBorder; }
	int getRightBorder() { return rightBorder; }
	~Baby() {};
};

