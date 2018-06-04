#include "math.h"

float math::magnitude(sf::Vector2f vector) {

	return sqrtf(powf(vector.x, 2) + powf(vector.y, 2));

}

sf::Vector2f math::normalize(sf::Vector2f vector) {

	float mag = magnitude(vector);
	if (mag == 0)
		return vector;
	else {
		vector.x = vector.x / mag;
		vector.y = vector.y / mag;
		return vector;

	}
}

float math::dotProduct(sf::Vector2f vector1, sf::Vector2f vector2) {

	return vector1.x * vector2.x + vector1.y * vector2.y;

}


void math::limit(sf::Vector2f& vector, float limit) {
	if (magnitude(vector) > limit) {
		vector = normalize(vector);
		vector.x *= limit;
		vector.y *= limit;
	}
}