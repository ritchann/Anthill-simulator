#include "Enemy.h"


Enemy::Enemy()
{
	srand(time(0));
	x = 41; 
	y = rand() % 23;//появляется на границе в рандомной точке
	attackTime = 25 + rand() % 35; //я поставила время атаки с 25, потому что у нас воины только после 20 появляются
	intervalBetweenAttacks = 10 + rand() % 20;// в общем, у нас есть время начала атаки, и также рандомим интервал между нашими атаками
	livespan = 1;
	texture.loadFromFile("images/Enemy.png");
	sprite.setTexture(texture);
	sprite.setPosition(x * 32, y * 32);
}


Sprite Enemy::getSprite() { return sprite; }

void Enemy::goForward() { y = y - 1; }

void Enemy::goLeft() { x = x - 1; }

void Enemy::goBackwards() { y = y + 1; }

void Enemy::goRight() { x = x + 1; }

void Enemy::move() {
	int direction;
	if ((x <= getRightBorder()) && (x >= getLeftBorder())) {
		direction = 1 + rand() % 4;
	}
	else if (x >= getRightBorder()) direction = 4;
	else direction = 2;
	switch (direction) {
	case 1:
		if (y <= 0) move();
		else goForward();
		break;
	case 2:
		if (x >= getRightBorder()) move();
		else goRight();
		break;
	case 3:
		if (y >= 20) move();
		else goBackwards();
		break;
	case 4:
		if (x <= getLeftBorder()) move();
		else goLeft();
		break;
	}
}


void Enemy::update(Field* field,int time) {
	if (field->getValue(x,y)==2)// все также как у других, только если в клеточке вишенка, он ее ест)))
		field->setValue(x, y);
	livespan++;
	sprite.setTexture(texture);
	move();
	sprite.setPosition(x * 32, y * 32);
}

bool Enemy::alive(int time) {// жив, а точнее активен только тогда, когда текущее время больше времени начала атаки
	if (time >= attackTime)
		return true;
	else{
		return false;
	}
}

void Enemy::setCoordinates() {//меняем тут координатки, для его нового рандомного положения
	x = 41;
	y = 1+rand()%23;
}
void Enemy::doWork(Ant* ant,Field* field,int time) {//собствена его работка
	if (ant->getX() == x && ant->getY() == y) { // если враг стоит в одной клетке с муравьем
		if (ant->getRole()->Work(field->getValue(x, y)) == 4) {//а именно если стоит с воином
			switch (1 + rand() % 3)//будем рандомить действия, потому что уровней жизни у нас нет и чтобы все это было поинтереснен
			{
			case 1: // убиваем воина
				ant->setLivespan();
				ant->setRole();
				cout << "kill warrior" << endl;
				break;
			case 2: //тут у нас враг паникует, его пугают и он отлетает к боковой правой границе
				while (getX() != 41) {
					goRight();
				}
				cout << "panic enemy" << endl;
				break;
			case 3://врага убивают
				setCoordinates();//рандомим ему новые координаты
				attackTime = time + intervalBetweenAttacks;//также ставим новое время начала атаки с учетом текущего времени и интервала между атаками
				cout << "kill enemy" << endl;
				break;
			}
		}
		if (ant->getRole()->getFile() == "images/collectorFood.png") {//если у нас в клеточке собиратель еды, то мы ее либо отбираем, либо нет
			switch (1+rand()%2 )
			{
			case 1://отбираем еду 
				field->setCountedFood(field->getCountedFood() - 1);
				cout << "took food" << endl;
				break;
			case 2:
				cout << "did not take food" << endl;
				break;
			}
		}
	}
}


