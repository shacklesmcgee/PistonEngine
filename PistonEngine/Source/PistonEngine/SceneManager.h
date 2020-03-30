#pragma once
#include "GameObject.h"
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <sol.hpp>

#include <lua.hpp>
#define SOL_ALL_SAFETIES_ON 1


using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	GameObject* Create(string _name, sol::state &_lua);
	virtual void Update(float msec);

	GameObject* GetGameObject(string _name);
	vector<GameObject*> GetAllGameObjects();

	void LoadScene(sol::state &_lua);

	void Input();

private:
	vector<GameObject*> _gameObjects; 


};

