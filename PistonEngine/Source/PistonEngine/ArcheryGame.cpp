#include "ArcheryGame.h"

ArcheryGame::ArcheryGame()
{
}

ArcheryGame::~ArcheryGame()
{
}

void ArcheryGame::Start(sf::RenderWindow& _mainWindow)
{
	//GameEngine::Start();

	////Creating an object
	//GameObject* ball = Piston._gameObjectManager.Create("ball");
	////Create graphics component
	//ball->AddComponent(new GraphicsComponent("Assets/ball.png"));
	////Create transform component
	//ball->AddComponent(new TransformComponent());
	////Create audio component
	//ball->AddComponent(new AudioComponent("Assets/bump.wav"));
	////test the audio component
	//ball->Audio->PlayAudio();

	////Creating an 2nd object
	//GameObject* ball2 = Piston._gameObjectManager.Create("ball2");
	//ball2->SetParent(*Piston._gameObjectManager.GetGameObject("ball"));
	////Create graphics component
	//ball2->AddComponent(new GraphicsComponent("Assets/ball2.png"));
	////Create transform component
	//ball2->AddComponent(new TransformComponent());
	//ball2->Graphics->setOrigin((sf::Vector2f)Piston._gameObjectManager.GetGameObject("ball2")->Graphics->GetSprite().getTexture()->getSize());
}

void ArcheryGame::Update(sf::RenderWindow& _mainWindow)
{
	//test the transform component and scene manager
	/*if (value->GetName() == "ball")
		value->Transform->setLocation(0.01f, 0.01f);

	else if (value->GetName() == "ball2")
		value->Transform->setRotation(0.01f, value->Graphics->getOrigin());*/
}
