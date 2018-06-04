#include "vehicle.h"
#include "math.h"

vehicle::vehicle(sf::RenderWindow * window) {

	shape.setFillColor(sf::Color::Green);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(1);
	shape.setScale(1, 2);
	shape.setRadius(3);
	shape.setPosition(location);
	shape.setPointCount(3);

	location = (Vector2f)sf::Mouse::getPosition(*window);
	velocity = Vector2f(0, 0);
	acceleration = Vector2f(0, 0);

	maxspeed = 50.0f;
	maxforce = 1.0f;
	radius = 20.0f;
}

vehicle::~vehicle() {
}

void vehicle::borders(sf::RenderWindow * window) {

	if (shape.getPosition().x > window->getSize().x - 10)
		shape.setPosition(10, shape.getPosition().y);
	if (shape.getPosition().x < 10)
		shape.setPosition(window->getSize().x - 10, shape.getPosition().y);
	if (shape.getPosition().y > window->getSize().y - 10)
		shape.setPosition(shape.getPosition().x, 10);
	if (shape.getPosition().y < 10)
		shape.setPosition(shape.getPosition().y, window->getSize().y - 10);
}

void vehicle::update(float dt) {

	shape.setPosition(location);
	shape.setRotation(atan2(velocity.x, -velocity.y) * 180 / PI);

	location += velocity * dt;
	velocity += acceleration * dt;
	acceleration = acceleration * 0.0f;

}

void vehicle::applyForce(sf::Vector2f steer) {
	acceleration += steer;
}

void vehicle::seek(sf::Vector2f target) {

	sf::Vector2f aim = target - location;
	Vector2f desired;

	if (math::magnitude(aim) > radius) {
		desired = math::normalize(aim) * maxspeed;
		Vector2f steer = desired - velocity;
		math::limit(steer,maxforce);
		applyForce(steer);
	}
	else
		desired = math::normalize(aim) * maxspeed * math::magnitude(aim) / radius;
	
}


