#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;

class GameObjectManager
{
public:
	void Create(string _name);
	virtual void Update(float msec);

	GameObject* GetGameObject(string _name);
	vector<GameObject*> GetAllGameObjects();


private:
	vector<GameObject*> _gameObjects;
};

