#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent()
{
	setAABB();
}

RigidBodyComponent::~RigidBodyComponent(void)
{
}

void RigidBodyComponent::Update(float dt)
{
}

void RigidBodyComponent::addForce(sf::Vector2f force)
{
	RigidBodyComponent::totalForces += force;
}

void RigidBodyComponent::stop()
{
	currentVelocity = sf::Vector2f();
	totalForces = sf::Vector2f();
}

void RigidBodyComponent::setAABB()
{
	/*Bounds bound = new Bounds(new Vector2(0, 0), new Vector2(1, 1));
	Renderer renderer = GetComponent<Renderer>();

	if (renderer)
	{
		bound = renderer.bounds;
	}

	aabb.bLeft = sf::Vector2f(bound.center.x - bound.extents.x, bound.center.y - bound.extents.y);
	aabb.tRight = sf::Vector2f(bound.center.x + bound.extents.x, bound.center.y + bound.extents.y);*/
}

void RigidBodyComponent::integrate(float dT) {
	sf::Vector2f acceleration = sf::Vector2f();

	if (obeysGravity && !RigidBodyComponent::grounded) {
		acceleration = gravity;
	}
	else {
		if (Mathf.Abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
	}

	acceleration += totalForces / mass;
	if (mass == 0)
		acceleration = sf::Vector2f(0, 0);

	currentVelocity += acceleration * dT;

	sf::Vector2f temp = transform.position;
	temp += currentVelocity * dT;
	transform.position = temp;
	setAABB();

	totalForces = sf::Vector2f(0, 0);
}
