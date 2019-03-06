#pragma once
#include <SFML/Graphics.hpp>

class Anthill {
private:
	int coord;
	Texture texture;
	Sprite sprite;
public:
	Anthill() {
		coord = 10;
		texture.loadFromFile("images/Sand.png");
		sprite.setTexture(texture);
	};
	Sprite getSprite() {
		return sprite;
	}
	int getCoord() {
		return coord;
	}
	void update(Field* field, int countAnt, int time) { //тут можно ничего не понимать, просто рандомные действия, но зависящие от колличества еды и веточек
		if (time > 90) {//веточки берут на строительство, кушают еду и живут активным образом жизни
			if (time % 20 == 0 && coord <21 && coord>9) {
				if (field->getCountedFood() - countAnt / 2 > 0) {
					field->setCountedFood(field->getCountedFood() - countAnt / 2);
					coord--;
				}
			}
			if (field->getCountedFood() % 20 == 0 && field->getCountedFood() != 0 && coord < 20)
				coord++;
			if (field->getCountedBranch() % 100 == 0 && field->getCountedBranch() != 0 && coord < 20)
				coord++;
			if (time % 110 == 0)
				field->setCounedBranch(field->getCountedBranch() - field->getCountedBranch() / 3);
		}
}
	int getStatus() {
		return coord;
	}
	~Anthill() {};
};
