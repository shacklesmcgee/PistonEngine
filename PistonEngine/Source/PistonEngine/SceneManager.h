#pragma once
#include "GameObject.h"
#include <vector>

#include <lua.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol.hpp>

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	GameObject* CreateDefault();
	GameObject* Create(string _name);
	virtual void Update(float msec);

	GameObject* GetGameObject(string _name);
	vector<GameObject*> GetAllGameObjects();


private:
	vector<GameObject*> _gameObjects;
};

