#include "GameObjectManager.h"


GameObjectManager::GameObjectManager()
{
	//sol::state lua;

	//lua.set("GameObjectManager", this);
	//lua["CreateObject"] = &GameObjectManager::Create;
	//lua.script_file("Assets/test.lua");
}

GameObjectManager::~GameObjectManager()
{
}

//GameObject* GameObjectManager::CreateDefault()
//{
//	GameObject* _gameObject = new GameObject();
//	_gameObjects.push_back(_gameObject);
//
//	return _gameObject;
//}

GameObject* GameObjectManager::Create(string _newName)
{
	GameObject* _gameObject = new GameObject();
	_gameObject->SetName(_newName);
	_gameObjects.push_back(_gameObject);

	return _gameObject;
}

void GameObjectManager::Update(float msec)
{
	for (auto const& value : _gameObjects)
	{
		value->Update(msec);
	}
}



GameObject* GameObjectManager::GetGameObject(string _name)
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

vector<GameObject*> GameObjectManager::GetAllGameObjects()
{
	return _gameObjects;
}
