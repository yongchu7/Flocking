#pragma once
#include "world.h"
class vehicle {

public:

	vehicle(sf::RenderWindow* window);
	~vehicle();
	void update(float dt);
	void applyForce(sf::Vector2f steer);
	void seek(sf::Vector2f target);
	void borders(sf::RenderWindow * window);
	sf::CircleShape shape;
	sf::Vector2f location;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float maxspeed;
	float maxforce = 1.0f;
	float radius = 20.0f;
	std::vector<vehicle> boids;

};