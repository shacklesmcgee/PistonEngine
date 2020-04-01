#pragma once
#include "GameObject.h"
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <sol.hpp>
#include "Event.h"
#include <lua.hpp>

#define SOL_ALL_SAFETIES_ON 1


using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	GameObject* Create(string _name);
	virtual void Update(float msec);

	GameObject* GetGameObject(string _name);
	vector<GameObject*> GetAllGameObjects();

	void LoadScene();

	void Input(const Event& e);

private:
	vector<GameObject*> _gameObjects; 


};

