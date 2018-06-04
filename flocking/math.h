#pragma once
#include "world.h"
#define PI 3.14159265359
static class math {

public:

	float static magnitude(sf::Vector2f vector);
	sf::Vector2f static normalize(sf::Vector2f vector);
	float static dotProduct(sf::Vector2f vector1, sf::Vector2f vector2);
	void static limit(sf::Vector2f& vector, float limit);
};