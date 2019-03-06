#pragma once
#include "Role.h"
#include <iostream>
#include <ctime>

using namespace std;
class Collector : public Role
{
private:
	string file;
	int food;
	int leftBorder, rightBorder;
	
public:
	Collector()
	{
		food = 1 + rand() % 2;
		if (food == 1)
			file = "images/collectorFood.png";
		else
			file = "images/collectorBranch.png";
	}
	int Work(int type) {
		if ((type == 2) || (type == 3)) {
			switch (food) {
			case 1:
				if (type == 2) return 2;
				else return 0;
				break;
			case 2:
				if (type == 3) return 3;
				else return 0;
				break;
			}
		}
		else return 0;
	}
	string getFile() { return file; }
	void setLeftBorder(int value) { leftBorder = value; }
	void setRightBorder(int value) { rightBorder = value; }
	int getLeftBorder() { return leftBorder; }
	int getRightBorder() { return rightBorder; }
	~Collector() {};
};

