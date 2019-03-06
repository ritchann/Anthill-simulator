#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Field {
private:
	int field[42][24];
	const int LITTER = 1,
		FOOD = 2,
		BRANCH = 3;
	String fileLitter,
		fileFood,
		fileBranch;
	int countedFood, countedBranch;
public:
	Field();
	bool isLitter(int, int);
	bool isFood(int, int);
	bool isBranch(int, int);
	void setValue(int, int);
	int getValue(int, int);
	void updateField();
	String getFileFood();
	String getFileLitter();
	String getFileBranch();
	void addFood();
	void addBranch();
	int getCountedFood();
	void setCountedFood(int newCountFood);
	void setCounedBranch(int newCountedBranch);
	int getCountedBranch();
};
