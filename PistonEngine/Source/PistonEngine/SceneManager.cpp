#include "SceneManager.h"


SceneManager::SceneManager()
{
	//sol::state lua;

	//lua.set("SceneManager", this);
	//lua["CreateObject"] = &SceneManager::Create;
	//lua.script_file("Assets/test.lua");
}

SceneManager::~SceneManager()
{
}

//GameObject* SceneManager::CreateDefault()
//{
//	GameObject* _gameObject = new GameObject();
//	_gameObjects.push_back(_gameObject);
//
//	return _gameObject;
//}

GameObject* SceneManager::Create(string _newName)
{
	GameObject* _gameObject = new GameObject();
	_gameObject->SetName(_newName);
	_gameObjects.push_back(_gameObject);

	return _gameObject;
}

void SceneManager::Update(float msec)
{
	for (auto const& value : _gameObjects)
	{
		value->Update(msec);
	}
}



GameObject* SceneManager::GetGameObject(string _name)
{
	GameObject* obj = NULL;

	for (auto const& value : _gameObjects) {
		if (value->GetName() == _name)
		{
			obj = value;
			break;
		}

	}
	return obj;
}

vector<GameObject*> SceneManager::GetAllGameObjects()
{
	return _gameObjects;
}
