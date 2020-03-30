#include "SceneManager.h"

using namespace rapidjson;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

GameObject* SceneManager::Create(string _newName, sol::state &_lua)
{
	GameObject* _gameObject = new GameObject(_lua);
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

void SceneManager::LoadScene(sol::state &_lua)
{
	FILE* fp = fopen("Scenes/scene1.json", "rb");

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document document;
	document.ParseStream(is);

	assert(document.HasMember("GameObjects"));
	assert(document["GameObjects"].IsArray());

	Value& gameObjects = document["GameObjects"];
	assert(gameObjects.IsArray());

	for (SizeType i = 0; i < gameObjects.Size(); i++)
	{
		string objString = "GameObject" + std::to_string(i + 1);
		const char* objChar = objString.c_str();

		Value& tempGameObject = gameObjects[i][objChar];
		for (SizeType x = 0; x < tempGameObject.Size(); x++)
		{
			string name = tempGameObject[x]["name"].GetString();
			string texture = "";
			string script = "";

			if (!tempGameObject[x]["texture"].IsNull())
				texture = tempGameObject[x]["texture"].GetString();

			if (!tempGameObject[x]["script"].IsNull())
				script = tempGameObject[x]["script"].GetString();
				
			sf::Vector2f position(tempGameObject[x]["positionX"].GetInt(), tempGameObject[x]["positionY"].GetInt());
			float rotationAngle = tempGameObject[x]["rotationAngle"].GetInt();
			sf::Vector2f rotationOrigin(tempGameObject[x]["rotationX"].GetFloat(), tempGameObject[x]["rotationY"].GetFloat());
			sf::Vector2f scale(tempGameObject[x]["scaleX"].GetFloat(), tempGameObject[x]["scaleY"].GetFloat());

			Create(name, _lua);

			if (tempGameObject[x]["transformComp"].GetBool())
			{
				GetGameObject(name)->AddComponent(new TransformComponent(_lua));
				GetGameObject(name)->Transform->SetLocationF(position.x, position.y);
				GetGameObject(name)->Transform->SetRotation(rotationAngle, rotationOrigin);
				GetGameObject(name)->Transform->SetScaleF(scale.x, scale.y);
			}

			if (!tempGameObject[x]["parent"].IsNull())
			{
				GameObject* parent = GetGameObject(tempGameObject[x]["parent"].GetString());

				GetGameObject(name)->SetParent(*parent);
				//_SceneManager.GetGameObject(name)->Transform->SetLocation(_SceneManager.GetGameObject();
			}

			if (tempGameObject[x]["graphicsComp"].GetBool())
			{
				GetGameObject(name)->AddComponent(new GraphicsComponent(texture, _lua));
			}

			if (tempGameObject[x]["scriptComp"].GetBool())
			{
				GetGameObject(name)->AddComponent(new ScriptComponent(script, _lua));

				sol::function MoveUp = _lua["MoveUp"];

				if (MoveUp.valid())
					MoveUp();
			}
		}
	}

	fclose(fp);
}

void SceneManager::Input()
{
	cout << "works" << endl;
}
