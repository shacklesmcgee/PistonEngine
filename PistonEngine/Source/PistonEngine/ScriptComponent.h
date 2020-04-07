#pragma once
#include "BaseComponent.h"
#include "sol.hpp"

using namespace std;

class ScriptComponent : public BaseComponent
{
public:
	//ScriptComponent();
	ScriptComponent(string _fileName, sol::state &_lua);
	~ScriptComponent(void);

	virtual void Update(float dt);

	void PrintInt(int value);
	bool fileLoaded = false;
	sol::state lua;

protected:
	string name;
};

