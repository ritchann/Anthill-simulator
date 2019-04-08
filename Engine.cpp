#include "Engine.h"
#include <ctime>
#include <windows.h>

Engine::Engine(Field* field) {
	window.create(VideoMode(1344,768), "AntHill");
	backgroundTexture.loadFromFile("images/Grass.png");
	backgroundSprite.setTexture(backgroundTexture);
	
	this->field = field;
	Ant* firstAnt = new Ant();
	enem = new Enemy();
	org.push(firstAnt);
}

void Engine::start() {
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		Ant* tmpAnt = new Ant();
		while (time > currentTime) { 
			while (!org.empty()) {
				org.front()->update(time, field);
				if (org.front()->alive()) {
					if (enem->alive(currentTime)) 
						enem->doWork(org.front(), field, currentTime);
					else
						inform.setDanger();

					if (org.front()->alive())
						tmp.push(org.front());
				}
				org.pop();
			}
			Ant* newAnt = new Ant();
			if ((currentTime % 5 == 0) && (tmp.size() < 30)) 
				tmp.push(newAnt);
		
			org = tmp;

			output.clear();
			while (!tmp.empty()) {
				output.push_back(tmp.front()->getSprite());
				tmp.pop();
			}

			draw();
			if (currentTime % 250 == 0)
				field->updateField();
			currentTime++; 
			Sleep(100);
		}
	}
}

void Engine::draw() {
	window.clear();
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 24; j++) {
			backgroundSprite.setPosition(i * 32, j * 32);
			window.draw(backgroundSprite);
		}
	}

	anthill.update(field,output.size(),currentTime);
	Sprite sprite = anthill.getSprite();
	for (int i = 0; i < anthill.getStatus(); i++) {
		for (int j = 0; j < 24; j++) {

			sprite.setPosition(i * 32, j * 32);
			window.draw(sprite);
		}
	}

	Font font;
	font.loadFromFile("Roboto-Bold.ttf");

	Text textStr1("BRANCH: ", font, 20);
	textStr1.setPosition(1000, 0);
	window.draw(textStr1);

	Text textNumber1(std::to_string(field->getCountedBranch()), font, 20);
	textNumber1.setPosition(1095, 0);
	window.draw(textNumber1);

	Text textStr2("POPULATION: ", font, 20);
	textStr2.setPosition(1000, 20);
	window.draw(textStr2);

	Text textNumber2(std::to_string(output.size()), font, 20);
	textNumber2.setPosition(1135, 20);
	window.draw(textNumber2);

	Text textStr3("FOOD: ", font, 20);
	textStr3.setPosition(1000, 40);
	window.draw(textStr3);

	Text textNumber3(std::to_string(field->getCountedFood()), font, 20);
	textNumber3.setPosition(1095, 40);
	window.draw(textNumber3);

	Text textStr4("TIME: ", font, 20);
	textStr4.setPosition(1000, 60);
	window.draw(textStr4);

	Text textNumber4(std::to_string(currentTime), font, 20);
	textNumber4.setPosition(1095, 60);
	window.draw(textNumber4);
	
	Texture textureLitter;
	textureLitter.loadFromFile(field->getFileLitter());
	Sprite spriteLitter;
	spriteLitter.setTexture(textureLitter);
	
	Texture textureFood;
	textureFood.loadFromFile(field->getFileFood());
	Sprite spriteFood;
	spriteFood.setTexture(textureFood);

	Texture textureBranch;
	textureBranch.loadFromFile(field->getFileBranch());
	Sprite spriteBranch;
	spriteBranch.setTexture(textureBranch);


	if (enem->alive(currentTime)) { 
		enem->update(field, currentTime);
		window.draw(enem->getSprite());
	}

	inform.updateInform(org, field, enem);
	for (int i = 0; i < 42; i++) {
		for (int j = 0; j < 24; j++) {
			if (field->isLitter(i, j) == true) {
				spriteLitter.setPosition(i * 32, j * 32);
				window.draw(spriteLitter);
			}
			else if (field->isFood(i, j) == true) {
				spriteFood.setPosition(i * 32, j * 32);
				window.draw(spriteFood);
			}
			else if (field->isBranch(i, j) == true) {
				spriteBranch.setPosition(i * 32, j * 32);
				window.draw(spriteBranch);
			}
		}
	}
	
	for (int i = 0; i < output.size(); i++) {
		window.draw(output[i]);
	}

	window.display();
}

Engine::~Engine() {
	while (!org.empty()) org.pop();
	while (!tmp.empty()) tmp.pop();
	output.clear();
}
