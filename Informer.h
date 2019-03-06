#pragma once
#include <queue>
#include "Ant.h"
#include "Enemy.h"
class Informer
{
private:
	queue<Ant*> temp;
	bool danger;
	int alertDanger;
public:
	Informer();
	void setDanger() {
		danger = false;
	}
	void updateInform(queue<Ant*> anthill,Field* field, Enemy* enem);
	Ant* updateAnt(Ant* ant,Field* field,Enemy* enemy);
	void alert();
	~Informer();
};

