#include "SceneManager.h"
#include "InputEvent.h"

using namespace rapidjson;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

GameObject* SceneManager::Create(string _newName)
{
	GameObject* _gameObject = new GameObject();
	_gameObject->SetName(_newName);
	_gameObject->SetSceneManager(this);
	_gameObjects.push_back(_gameObject);

	return _gameObject;
}

void SceneManager::Destroy(string _name)
{
	int i = 0;
	for (auto const& value : GetAllGameObjects())
	{
		if (value->GetName() == _name)
		{
			delete value;
			_gameObjects.erase(_gameObjects.begin() + i);
		}
		i++;
	}
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

void SceneManager::LoadScene()
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

		Value& tempJSONObject = gameObjects[i][objChar];
		for (SizeType x = 0; x < tempJSONObject.Size(); x++)
		{
			string name = tempJSONObject[x]["name"].GetString();
			string texture = "";
			string script = "";

			if (!tempJSONObject[x]["texture"].IsNull())
				texture = tempJSONObject[x]["texture"].GetString();

			if (!tempJSONObject[x]["script"].IsNull())
				script = tempJSONObject[x]["script"].GetString();

			sf::Vector2f position(tempJSONObject[x]["positionX"].GetInt(), tempJSONObject[x]["positionY"].GetInt());
			float rotationAngle = tempJSONObject[x]["rotationAngle"].GetInt();
			sf::Vector2f rotationOrigin(tempJSONObject[x]["rotationX"].GetFloat(), tempJSONObject[x]["rotationY"].GetFloat());
			sf::Vector2f scale(tempJSONObject[x]["scaleX"].GetFloat(), tempJSONObject[x]["scaleY"].GetFloat());

			GameObject* obj = Create(name);

			if (tempJSONObject[x]["transformComp"].GetBool())
			{
				obj->AddComponent(new TransformComponent(obj->Lua));
				obj->Transform->SetLocationF(position.x, position.y);
				obj->Transform->SetRotation(rotationAngle, rotationOrigin);
				obj->Transform->SetScaleF(scale.x, scale.y);
			}

			if (!tempJSONObject[x]["parent"].IsNull())
			{
				GameObject* parent = GetGameObject(tempJSONObject[x]["parent"].GetString());

				obj->SetParent(*parent);
			}

			if (tempJSONObject[x]["graphicsComp"].GetBool())
			{
				if (tempJSONObject[x]["animated"].GetBool())
				{
					sf::IntRect tempRect = sf::IntRect(tempJSONObject[x]["textureX"].GetInt(),
														tempJSONObject[x]["textureY"].GetInt(),
														tempJSONObject[x]["textureWidth"].GetInt(),
														tempJSONObject[x]["textureHeight"].GetInt());

					obj->AddComponent(new GraphicsComponent(tempJSONObject[x]["textureName"].GetString(),
						texture, 
						tempRect, 
						tempJSONObject[x]["animated"].GetBool(), 
						tempJSONObject[x]["frameTime"].GetFloat(), 
						tempJSONObject[x]["looping"].GetBool(), 
						obj->Lua));
				}
			}

			if (tempJSONObject[x]["scriptComp"].GetBool())
			{
				obj->AddComponent(new ScriptComponent(script, obj->Lua));

				if (obj->Lua["Start"].valid())
				{
					obj->Script->Start();
				}
			}

			if (tempJSONObject[x]["inputComp"].GetBool())
			{
				obj->AddComponent(new InputComponent(obj->Lua));
			}
		}
	}

	fclose(fp);
}

void SceneManager::InputTriggered(const Event& e)
{
	const InputEvent& inputEvent = static_cast<const InputEvent&>(e);

	if (inputEvent.isMouse)
	{
		for (auto const& value : _gameObjects) {
			if (value->Input && value->Lua["MouseInput"].valid())
			{
				value->Input->MouseInput(inputEvent.pressed, inputEvent.keyCode);
			}
		}
	}

	else if (!inputEvent.isMouse)
	{
		for (auto const& value : _gameObjects) {
			if (value->Input && value->Lua["KeyInput"].valid())
			{
				value->Input->KeyInput(inputEvent.pressed, inputEvent.keyCode);
			}
		}
	}
	
}
