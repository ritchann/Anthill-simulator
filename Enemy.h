#pragma once
#include "Role.h"
#include "Ant.h"
#include <iostream>


using namespace std;

class Enemy
{
private:
	int attackTime;
	int intervalBetweenAttacks;
	int x, y;
	int livespan;
	int rightBorder=30, leftBorder=25;
	Texture texture;
	Sprite sprite;

public:
	Enemy();
	int getRightBorder() {
		return rightBorder;
	}
	int getAttackTime() {
		return attackTime;
	}
	int getInervalBetweenAttacks() {
		return intervalBetweenAttacks;
	}
	void setLivespan(int livespan) {
		livespan = livespan;
	}
	int getLeftBorder() {
		return leftBorder;
	}
	int getX() { return x; }
	int getY() { return y; }
	void doWork(Ant* ant,Field* field,int time);
	Sprite getSprite();
	void goForward();
	void goLeft();
	void goBackwards();
	void goRight();
	void move();
	bool alive(int time);
	void setCoordinates();
	void update(Field* field,int time);
	~Enemy() {};
};

