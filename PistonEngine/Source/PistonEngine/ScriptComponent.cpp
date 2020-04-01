#include "ScriptComponent.h"

using namespace std;

class BaseObject;

ScriptComponent::ScriptComponent(string _fileName, sol::state &_lua)
{
	name = "ScriptComponent";
	_lua.script_file(_fileName);

	if (_lua["Start"].valid())
		Start = _lua["Start"];
	if (_lua["Update"].valid())
		LuaUpdate = _lua["Update"];
}

ScriptComponent::~ScriptComponent(void)
{
}


void ScriptComponent::Update(float dt)
{
	if (LuaUpdate != NULL)
		LuaUpdate();
}

