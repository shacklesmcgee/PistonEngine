#pragma once
#include "BaseComponent.h"

using namespace std;

class ScriptComponent : public BaseComponent
{
public:
	//ScriptComponent();
	ScriptComponent(string _fileName, sol::state &_lua);
	~ScriptComponent(void);

	virtual void Update(float dt);

	bool fileLoaded = false;

	std::function<void()> Start;
	std::function<void()> LuaUpdate;

protected:

};

