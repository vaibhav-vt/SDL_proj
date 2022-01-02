#pragma once

#include "Game.h"
#include "TextureManager.h"
#include "Gameobject.h"

class ObjectHandler
{
private:

public:
	ObjectHandler();
	~ObjectHandler();

	void updateObj(int factor, int k);
	void renderObj(int mflag, int enter);


};