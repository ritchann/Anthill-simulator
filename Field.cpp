#include "Field.h"
#include <iostream>

Field::Field() {
	for (int i = 0; i < 42; i++) {
 		for (int j = 0; j < 24; j++) {
			field[i][j] = 0;
		}
	}

	updateField();

	fileLitter = "images/Litter.png";
	fileFood = "images/Food.png";
	fileBranch = "images/Branch.png";

	countedFood = 0;
	countedBranch = 0;
}

String Field::getFileBranch() { return fileBranch; }
String Field::getFileLitter() { return fileLitter; }
String Field::getFileFood() { return fileFood; }

bool Field::isLitter(int x, int y) {
	if (field[x][y] == LITTER) return true;
	else false;
}
bool Field::isBranch(int x, int y) {
	if (field[x][y] == BRANCH) return true;
	else false;
}
bool Field::isFood(int x, int y) {
	if (field[x][y] == FOOD) return true;
	else false;
}

void Field::setValue(int x, int y) { field[x][y] = 0; }
int Field::getValue(int x, int y) { return field[x][y]; }

void Field::setCountedFood(int newCountFood) {
	countedFood = newCountFood;
}
void Field::updateField() {
	int k = 1;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 24; j++) {
			if (k % 10 == 0) field[i][j] = LITTER;
			k++;
		}
	}

	k = 1;
	for (int i = 20; i < 30; i++) {
		for (int j = 0; j < 24; j++) {
			if (k % 2 == 0) field[i][j] = FOOD;
			else field[i][j] = BRANCH;
			k++;
		}
	}
}
void Field::setCounedBranch(int newCountedBranch) {
	countedBranch = newCountedBranch;
}

void Field::addFood() { countedFood++; }
void Field::addBranch() { countedBranch++; }
int Field::getCountedBranch() { return countedBranch; }
int Field::getCountedFood() { return countedFood; }