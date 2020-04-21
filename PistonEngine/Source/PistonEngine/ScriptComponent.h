#pragma once
#include "BaseComponent.h"

using namespace std;

class ScriptComponent : public BaseComponent
{
public:
	//ScriptComponent();
	ScriptComponent(string fileName, sol::state &_lua);
	~ScriptComponent(void);

	virtual void Update(float dt);

	bool fileLoaded = false;

	std::function<void(std::vector<string> args)> LuaStart;
	std::function<void(float dt)> LuaUpdate;
	std::function<void(std::vector<string> args)> LuaReceive;

protected:

};

