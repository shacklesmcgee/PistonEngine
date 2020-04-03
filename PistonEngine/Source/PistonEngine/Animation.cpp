#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(string _name, string _location, sf::IntRect _rect, bool _animated, float _frameTime, bool _looping)
{
	Name = _name;
	TextureLocation = _location;
	SpriteRect = _rect;

	Animated = _animated;
	FrameTime = _frameTime;
	Playing = false;
	Looping = _looping;

	StartX = _rect.left;
	StartY = _rect.top;	
}

Animation::~Animation()
{
}
