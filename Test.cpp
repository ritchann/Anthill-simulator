#include "Test.h"
#include "Ant.h"
#include "Engine.h"

void main() {
	Field* field = new Field();
	Engine engine(field);

	engine.start();
}