#pragma once
#include <SFML/Graphics.hpp>
#include "Role.h"
#include "Baby.h"
#include "Nanny.h"
#include "Collector.h"
#include "Shepherd.h"
#include "Warrior.h"
#include "Cleaner.h"
#include "Field.h"


using namespace sf;

class Ant
{
private:
	int x, y;
	int livespan;
	Texture texture;
	Sprite sprite;
	Role* role;
public:
	Ant();
	Sprite getSprite();
	int getLivespan() { return livespan; }
	void setLivespan() { livespan = 200; }
	int getX() { return x; }
	int getY() { return y; }
	void goForward();
	void goLeft();
	void goBackwards();
	void goRight();
	void move();
	bool alive();
	void setRole();
	Role* getRole(){
		return role;
	}
	void update(int time, Field* field);
	~Ant();
};

