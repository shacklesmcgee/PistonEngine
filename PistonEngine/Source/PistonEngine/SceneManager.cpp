#include "SceneManager.h"
#include "InputEvent.h"

using namespace rapidjson;

SceneManager::SceneManager()
{
	screenWidth = 0;
	screenHeight = 0;
	isPaused = false;
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

void SceneManager::Destroy(GameObject* _objToDestroy)
{
	vector<GameObject*>::iterator itr;
	vector<GameObject*>::iterator itr2;

	for (itr = _gameObjects.begin(); itr != _gameObjects.end();)
	{
		if((*itr) == _objToDestroy)
		{
			itr2 = _gameObjects.erase(itr);
			delete _objToDestroy;
			return;
		}
		else
		{
			itr++;
		}
	}
}

void SceneManager::DestroyByName(string _name)
{
	vector<GameObject*>::iterator itr;
	vector<GameObject*>::iterator itr2;

	for (itr = _gameObjects.begin(); itr != _gameObjects.end();)
	{
		if ((*itr)->GetName() == _name)
		{
			GameObject* temp = *itr;
			itr2 = _gameObjects.erase(itr);
			delete temp;
			return;
		}
		else
		{
			itr++;
		}
	}
}

void SceneManager::Update(float msec)
{
	if (!isPaused)
	{
		for (auto const& value : _gameObjects)
		{
			value->Update(msec);
		}
	}
}


void SceneManager::SetVariables(float newWidth, float newHeight)
{
	screenWidth = newWidth;
	screenHeight = newHeight;
}

float SceneManager::GetScreenWidth()
{
	return screenWidth;
}

float SceneManager::GetScreenHeight()
{
	return screenHeight;
}


void SceneManager::PauseGame()
{
	isPaused = true;
}

void SceneManager::ResumeGame()
{
	isPaused = false;
}


GameObject* SceneManager::GetGameObject(string _name)
{
	GameObject* obj = NULL;

	for (auto const& value : _gameObjects) 
	{
		if (value && value->GetName() == _name)
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

void SceneManager::LoadScene(string location)
{

	_gameObjects.clear();
	const char* c = location.c_str();

	FILE* fp = fopen(c, "rb");

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
			string font = "";
			string text = "";

			if (!tempJSONObject[x]["texture"].IsNull())
				texture = tempJSONObject[x]["texture"].GetString();

			if (!tempJSONObject[x]["script"].IsNull())
				script = tempJSONObject[x]["script"].GetString();

			if (!tempJSONObject[x]["text"].IsNull())
				text = tempJSONObject[x]["text"].GetString();

			if (!tempJSONObject[x]["font"].IsNull())
				font = tempJSONObject[x]["font"].GetString();

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

			if (tempJSONObject[x]["textComp"].GetBool())
			{
				obj->AddComponent(new TextComponent(font, text, 64, sf::Color::White, obj->Lua));

			}
			if (tempJSONObject[x]["scriptComp"].GetBool())
			{
				obj->AddComponent(new ScriptComponent(script, obj->Lua));

				if (obj->Lua["Start"].valid())
				{
					
					std::vector<string> args;
					if (tempJSONObject[x]["args"].IsObject())
					{
						int i = 1;
						string loc = "arg" + std::to_string(i);
						while (i < 5)
						{
							args.push_back(tempJSONObject[x]["args"][loc.c_str()].GetString());
							i++;
							loc = "arg" + std::to_string(i);
						}
					}
					obj->Script->LuaStart(args);
				}
			}

			if (tempJSONObject[x]["inputComp"].GetBool())
			{
				obj->AddComponent(new InputComponent(obj->Lua));
			}	

			if (tempJSONObject[x]["rigidBodyComp"].GetBool())
			{
			float mass = tempJSONObject[x]["mass"].GetFloat();
			float restitution = tempJSONObject[x]["restitution"].GetFloat();
			bool obeysGravity = tempJSONObject[x]["obeysGravity"].GetBool();

			//currently setting the bounding box from the scale and position of object

			sf::Rect<float> boundingBox((float)tempJSONObject[x]["positionX"].GetInt(), 
				(float)tempJSONObject[x]["positionY"].GetInt() * 1.0,
				(float)tempJSONObject[x]["textureWidth"].GetInt() * tempJSONObject[x]["scaleX"].GetFloat(), 
				(float)tempJSONObject[x]["textureHeight"].GetInt() * tempJSONObject[x]["scaleY"].GetFloat());

			obj->AddComponent(new RigidBodyComponent(obj->Lua));
			obj->RigidBody->SetMass(mass);
			obj->RigidBody->SetObeysGravity(obeysGravity);
			obj->RigidBody->SetRestitution(restitution);
			obj->RigidBody->SetBoundingBox(boundingBox);
			}

			if (tempJSONObject[x]["audioComp"].GetBool())
			{
				string temp = tempJSONObject[x]["audioToSet"].GetString();
				obj->AddComponent(new AudioComponent(temp, obj->Lua));
				obj->Audio->PlayAudio();
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
			if (value && value->Input && value->Lua["MouseInput"].valid())
			{
				value->Input->MouseInput(inputEvent.pressed, inputEvent.keyCode, inputEvent.mousePos);
			}
		}
	}

	else if (!inputEvent.isMouse)
	{
		for (auto const& value : _gameObjects) {
			if (value && value->Input && value->Lua["KeyInput"].valid())
			{
				value->Input->KeyInput(inputEvent.pressed, inputEvent.keyCode, inputEvent.mousePos);
			}
		}
	}
	
}
