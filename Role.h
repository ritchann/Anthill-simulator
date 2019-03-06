#pragma once
#include <string>
#include "Field.h"

class Role
{
public:
	Role() {};
	
	virtual int Work(int type) = 0;
	virtual std::string getFile() = 0;
	virtual void setLeftBorder(int) = 0;
	virtual void setRightBorder(int) = 0;
	virtual int getLeftBorder() = 0;
	virtual int getRightBorder() = 0;
	virtual ~Role() {};
};

