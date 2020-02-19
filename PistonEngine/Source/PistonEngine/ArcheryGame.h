#pragma once
#include "GameEngine.h"

class ArcheryGame : public GameEngine
{
public:
	ArcheryGame();
	~ArcheryGame();
	void Start(sf::RenderWindow& _mainWindow);
	void Update(sf::RenderWindow& _mainWindow);

};

