#pragma once
#include "Role.h"
#include <iostream>

using namespace std;

class Warrior: public Role
{
private:
	string file;
	int leftBorder, rightBorder;
public:
	Warrior() { file = "images/Warrior.png"; };
	int Work(int type) {
		return 4;
	}
	string getFile() { return file; }
	void setLeftBorder(int value) { leftBorder = value; }
	void setRightBorder(int value) { rightBorder = value; }
	int getLeftBorder() { return leftBorder; }
	int getRightBorder() { return rightBorder; }
	~Warrior() {};
};

