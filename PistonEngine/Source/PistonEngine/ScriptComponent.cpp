#include "ScriptComponent.h"

using namespace std;

class BaseObject;

ScriptComponent::ScriptComponent(string _fileName, sol::state &_lua)
{
	name = "ScriptComponent";
	_lua.script_file(_fileName);
}

ScriptComponent::~ScriptComponent(void)
{
}


void ScriptComponent::Update(float dt)
{
}

