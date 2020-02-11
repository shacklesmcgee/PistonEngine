#pragma once
#include "BaseComponent.h"

class TransformComponent : BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	void getTransform();//this should not be a void function
	void setTransform();

protected:
	//Transform;
	//WorldTransform;
	//parent
};
