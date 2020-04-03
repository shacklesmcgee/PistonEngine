#pragma once
#include "SFML/Graphics.hpp"
using namespace std;

class Animation
{
public:
	Animation();
	Animation(string _name, string _location, sf::IntRect _rect, bool _animated, float _frameTime, bool _looping);
	~Animation();


	string Name;
	string TextureLocation;

	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::IntRect SpriteRect;

	bool Animated = false;
	bool Playing = false;
	bool Looping = false;

	int StartX;
	int StartY;

	float FrameTime = 0;
};
