#include "ScriptComponent.h"

using namespace std;

class BaseObject;

ScriptComponent::ScriptComponent(string fileName, sol::state &_lua)
{
	name = "ScriptComponent";

	_lua.script_file(fileName);
	if (_lua["Start"].valid())
		LuaStart = _lua["Start"];
	if (_lua["Update"].valid())
		LuaUpdate = _lua["Update"];
}

ScriptComponent::~ScriptComponent(void)
{
}


void ScriptComponent::Update(float dt)
{
	if (LuaUpdate != NULL)
		LuaUpdate(dt);
}

