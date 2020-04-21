#pragma once
#include "GameObject.h"
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <sol.hpp>
#include "Event.h"
#include <lua.hpp>
#include "SFML/Graphics/Rect.hpp"

#define SOL_ALL_SAFETIES_ON 1


using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	GameObject* Create(string _name);
	void Destroy(GameObject* _objToDestroy);
	void DestroyByName(string _name);

	virtual void Update(float msec);

	GameObject* GetGameObject(string _name);
	vector<GameObject*> GetAllGameObjects();

	void LoadScene(string location);
	void InputTriggered(const Event& e);

	void SetVariables(float newWidth, float newHeight);
	float GetScreenWidth();
	float GetScreenHeight();

	void PauseGame();
	void ResumeGame();

private:
	vector<GameObject*> _gameObjects; 

	float screenWidth;
	float screenHeight;

	bool isPaused;
};

