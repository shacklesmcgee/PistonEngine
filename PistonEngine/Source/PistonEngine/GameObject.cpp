#include "GameObject.h"
#include "SceneManager.h"

GameObject::GameObject()
{
	parent = NULL;

	Lua.open_libraries(sol::lib::base, sol::lib::math);
	Lua.set("GameObject", this);

	Lua["GetParent"] = &GameObject::GetParent;
	Lua["GetName"] = &GameObject::GetName;
	Lua["Create"] = &GameObject::LuaCreate;
	Lua["Destroy"] = &GameObject::LuaDestroy;
	Lua["LoadScene"] = &GameObject::LuaLoadScene;
}

GameObject::~GameObject(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void GameObject::SetParent(GameObject & p)
{
	parent = &p; 
	p.AddChild(this);

	this->Transform->SetByParent();
}

GameObject* GameObject::GetParent()
{
	return parent;
}

string GameObject::GetName()
{
	return name;
}

void GameObject::AddChild(GameObject * s)
{
	children.push_back(s);
	s->parent = this;
}

vector<GameObject*> GameObject::GetAllChildren()
{
	return children;
}

void GameObject::AddComponent(BaseComponent* componentToAdd)
{
	componentToAdd->owner = this;
	components.push_back(componentToAdd);

	if (componentToAdd->name == "GraphicsComponent")
	{
		Graphics = static_cast<GraphicsComponent*>(componentToAdd);
		Graphics->owner = this;
	}

	else if (componentToAdd->name == "TransformComponent")
	{
		Transform = static_cast<TransformComponent*>(componentToAdd);
		Transform->owner = this;
	}

	else if (componentToAdd->name == "AudioComponent")
	{
		Audio = static_cast<AudioComponent*>(componentToAdd);
		Audio->owner = this;
	}

	else if (componentToAdd->name == "ScriptComponent")
	{
		Script = static_cast<ScriptComponent*>(componentToAdd);
		Script->owner = this;
	}

	else if (componentToAdd->name == "InputComponent")
	{
		Input = static_cast<InputComponent*>(componentToAdd);
		Input->owner = this;
	}

	else if (componentToAdd->name == "TextComponent")
	{
		Text = static_cast<TextComponent*>(componentToAdd);
		Text->owner = this;
	}

	else if (componentToAdd->name == "RigidBodyComponent")
	{
		RigidBody = static_cast<RigidBodyComponent*>(componentToAdd);
		RigidBody->owner = this;
	}
}

BaseComponent* GameObject::GetComponent(string componentToGet)
{
	BaseComponent* comp = NULL;

	for (auto const& value : components) {
		if (value->name == componentToGet)
		{
			comp = value;
			break;
		}

	}
	return comp;
}

void GameObject::SetName(string _newName)
{
	name = _newName;
}

SceneManager* GameObject::GetSceneManager()
{
	return _sceneManager;
}

void GameObject::SetSceneManager(SceneManager* _newSceneManager)
{
	_sceneManager = _newSceneManager;
}

void GameObject::LuaCreate(sol::table gameObject)
{
	int i = 0;
	string tempName = gameObject["name"];

	for (auto const& value : _sceneManager->GetAllGameObjects())
	{
		if (value->name == (tempName + to_string(i)))
			i++;
	}

	tempName = tempName + to_string(i);
	_sceneManager->Create(tempName);

	GameObject* temp = _sceneManager->GetGameObject(tempName);

	if (gameObject["position"].valid() || gameObject["rotation"].valid() || gameObject["scale"].valid())
	{
		temp->AddComponent(new TransformComponent(temp->Lua));
	}

	if (gameObject["position"].valid())
	{
		temp->Transform->SetLocationF(gameObject["position"]["x"], gameObject["position"]["y"]);
	}

	if (gameObject["rotation"].valid())
	{
		temp->Transform->SetRotationF(gameObject["rotation"]["angle"], gameObject["rotation"]["x"], gameObject["rotation"]["y"]);
	}

	if (gameObject["scale"].valid())
	{
		temp->Transform->SetScaleF(gameObject["scale"]["x"], gameObject["scale"]["y"]);
	}

	if (gameObject["parent"].valid())
	{
		temp->SetParent(*_sceneManager->GetGameObject(gameObject["parent"]));
	}

	if (gameObject["graphics"].valid())
	{
		if (gameObject["graphics"]["texture"].valid() && gameObject["graphics"]["animated"].valid())
		{
			

			sf::IntRect tempRect = sf::IntRect(gameObject["graphics"]["textureX"],
												gameObject["graphics"]["textureY"],
												gameObject["graphics"]["textureWidth"],
												gameObject["graphics"]["textureHeight"]);

			temp->AddComponent(new GraphicsComponent(gameObject["graphics"]["name"],
													gameObject["graphics"]["texture"], 
													tempRect, 
													gameObject["graphics"]["animated"], 
													gameObject["graphics"]["frameTime"], 
													gameObject["graphics"]["looping"], 
													temp->Lua));
		}
	}

	if (gameObject["script"].valid())
	{
		temp->AddComponent(new ScriptComponent(gameObject["script"]["location"], temp->Lua));
	}

	if (temp->Lua["Start"].valid())
	{
		std::vector<string> args;

		if (gameObject["script"]["args"])
		{
			int i = 1;
			string loc = "arg" + std::to_string(i);
			while (gameObject["script"]["args"][loc])
			{
				
				args.push_back(gameObject["script"]["args"][loc]);
				i++;
				loc = "arg" + std::to_string(i);
			}
		}

		temp->Script->LuaStart(args);
	}

	if (gameObject["input"].valid())
	{
		temp->AddComponent(new InputComponent(temp->Lua));
	}

	if (gameObject["rigidBody"].valid())
	{

		temp->AddComponent(new RigidBodyComponent(temp->Lua));

		if (gameObject["rigidBody"]["mass"].valid())
		{
			temp->RigidBody->SetMass(gameObject["rigidBody"]["mass"]);
		}

		if (gameObject["rigidBody"]["restitution"].valid())
		{
			temp->RigidBody->SetRestitution(gameObject["rigidBody"]["restitution"]);
		}

		if (gameObject["rigidBody"]["obeysGravity"].valid())
		{
			temp->RigidBody->SetObeysGravity(gameObject["rigidBody"]["obeysGravity"]);

		}

		float tempX = gameObject["position"]["x"];
		float tempY = gameObject["position"]["y"];
		float tempWidth = (float)gameObject["graphics"]["textureWidth"] * (float)gameObject["scale"]["x"];
		float tempHeight = (float)gameObject["graphics"]["textureHeight"] * (float)gameObject["scale"]["y"];
		sf::Rect<float> tempRect(tempX, tempY, tempWidth, tempHeight);

		temp->RigidBody->SetBoundingBox(tempRect);
	}
}

void GameObject::LuaDestroy(string name)
{
	if (name != "" && name != this->name)
		GetSceneManager()->DestroyByName(name);
}

void GameObject::LuaLoadScene(string name)
{
	GetSceneManager()->LoadScene(name);
}
void GameObject::Update(float msec)
{
	
	for (auto const& value : components) {
		value->Update(msec);
	}

	if (Transform)
	{
		if (parent)
		{
			worldTransform = parent->worldTransform * Transform->GetTransform();
		}

		else
		{
			worldTransform = Transform->GetTransform();
		}
	}
	//if (Transform->GetLocationX() < 0 || 
	//	Transform->GetLocationX() > GetSceneManager()->GetScreenWidth() || 
	//	Transform->GetLocationY() < 0 ||
	//	Transform->GetLocationY() > GetSceneManager()->GetScreenHeight())
	//{
	//	GetSceneManager()->Destroy(this);
	//}
}
