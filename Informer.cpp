#include "Informer.h"

Informer::Informer(){
	alertDanger = 0;
	danger = false;
}
void Informer::updateInform(queue<Ant*> anthill, Field* field,Enemy* enem){
	queue<Ant*> tmpAnthill;
	while (!anthill.empty())
	{
		temp.push(anthill.front());
		anthill.pop();
	}
	anthill = temp;
	while (!temp.empty()) {
		if ((temp.front()->getX() == enem->getX() && temp.front()->getY() == enem->getY())||(danger==true)) {
			danger = true;
			alertDanger++;
			alert();
			while (!anthill.empty()) {
				tmpAnthill.push(updateAnt(anthill.front(), field,enem));
				anthill.pop();
			
			}
		}
		temp.pop();
	}

	if (tmpAnthill.size() != 0) {
		anthill = tmpAnthill;
	}
	else {
		if (alertDanger != 0)
			cout << "NO DANGER" << endl;
		alertDanger = 0;
	}
		

}
Ant* Informer::updateAnt(Ant* ant, Field* field,Enemy* enemy) {
	if ((ant->getRole()->Work(field->getValue(ant->getX(), ant->getY())) == 4) || (ant->getRole()->getFile() == "images/collectorFood.png") || (ant->getRole()->getFile() == "images/collectorBranch.png")){
		ant->getRole()->setLeftBorder(enemy->getX()-1);
		ant->getRole()->setRightBorder(enemy->getX() +1);
	}
	else{
		ant->getRole()->setLeftBorder(0);
		ant->getRole()->setRightBorder(3);
	}
	return ant;
}
void Informer::alert() {
	if (alertDanger==1) {
		cout << endl;
		cout << "DANGER" << endl;
	}
}


Informer::~Informer()
{
}
