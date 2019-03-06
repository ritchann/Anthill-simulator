#pragma once
#include "Ant.h"
#include "Anthill.h"
#include "Field.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include "Informer.h"

using namespace sf;

class Engine {
private:
	RenderWindow window;
	Sprite backgroundSprite;
	Texture backgroundTexture;

	std::queue<Ant*> org;
	std::queue<Ant*> tmp;
	std::queue<Ant*> tmpForEnemy;
	Enemy* enem;
	std::vector<Sprite> output;

	Informer inform;
	Anthill anthill;
	Field* field;
	int time = 2000;
	int currentTime = 1;
	void draw();
	
public:
	Engine(Field* field);
	void start();
	~Engine();
};
