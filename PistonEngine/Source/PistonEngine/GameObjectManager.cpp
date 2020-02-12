#include "GameObjectManager.h"

void GameObjectManager::Create(string _name)
{
	GameObject* _gameObject = new GameObject();
	_gameObject->name = _name;
	_gameObjects.push_back(_gameObject);
}

void GameObjectManager::Update(float msec)
{
	for (std::vector<GameObject*>::iterator i = _gameObjects.begin(); i != _gameObjects.end(); ++i)
	{
		(*i)->Update(msec);
	}
}

GameObject* GameObjectManager::GetGameObject(string _name)
{
	GameObject* obj = NULL;

	for (auto const& value : _gameObjects) {
		if (value->name == _name)
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
