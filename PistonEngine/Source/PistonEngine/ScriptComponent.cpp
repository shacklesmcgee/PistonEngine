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
	/*if (_lua["ReceiveData"].valid())
	LuaReceiveData = _lua["ReceiveData"];*/

	if (_lua["Test"].valid())
		LuaTest = _lua["Test"];
}

ScriptComponent::~ScriptComponent(void)
{
}


void ScriptComponent::Update(float dt)
{
	if (LuaUpdate != NULL)
		LuaUpdate(dt);
}

