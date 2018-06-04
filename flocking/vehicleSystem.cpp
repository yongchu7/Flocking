#include "vehicleSystem.h"
#include "vehicle.h"
#include "math.h"

vehicleSystem::vehicleSystem() {
}

vehicleSystem::~vehicleSystem(){}

void vehicleSystem::update(sf::RenderWindow* window, float dt) {
	for (auto &v : boids)
	{
		applyBehaviors(window, v);
		v.borders(window);
		v.update(dt);

	}
}

void vehicleSystem::render(sf::RenderWindow* window) {
	for (auto v : boids) {
		window->draw(v.shape);
	}
}

void vehicleSystem::addVehicles(sf::RenderWindow* window) {
	boids.push_back(vehicle(window));
}

void vehicleSystem::removeVehicle()
{
	boids.pop_back();
}

void vehicleSystem::separate(vehicle& v) {
	float neighbordist = 20.0f;
	sf::Vector2f sum;
	int count = 0;
	for (auto other : boids) {
		float d = math::magnitude(v.location - other.location);
		if ((d > 0) && (d < neighbordist)) {
			sf::Vector2f diff = math::normalize(v.location - other.location) / d;
			sum += diff;
			count++;
		}
	}
	if (count > 0)
	{
		sum.x / count;
		sum.y / count;
		Vector2f steer = math::normalize(sum) * v.maxspeed - v.velocity;
		math::limit(steer, 1.0f);
		v.applyForce(math::normalize(sum) * v.maxspeed - v.velocity);
	}
}

void vehicleSystem::alignment(vehicle& v) {

	float neighbordist = 50.0f;
	Vector2f sum;
	int count = 0;
	for (auto other : boids)
	{
		float d = math::magnitude(v.location - other.location);
		if ((d > 0) && (d < neighbordist))
		{
			sum += other.velocity;
			count++;
		}
	}

	if (count > 0)
	{
		sum.x / count;
		sum.y / count;
		Vector2f steer = math::normalize(sum) * v.maxspeed - v.velocity;
		math::limit(steer, 1.0f);
		v.applyForce(math::normalize(sum) * v.maxspeed - v.velocity);

	}
	else
		v.applyForce(Vector2f(0, 0));
}

void vehicleSystem::cohesion(vehicle& v) {

	float neighbordist = 50.0f;
	Vector2f sum;
	int count = 0;
	for (auto other : boids)
	{
		float d = math::magnitude(v.location - other.location);
		if ((d > 0) && (d < neighbordist))
		{
			sum += other.location;
			count++;
		}
	}

	if (count > 0)
	{
		sum.x / count;
		sum.y / count;
		v.seek(sum);
	}
	else
		v.applyForce(Vector2f(0, 0));
}

void vehicleSystem::applyBehaviors(sf::RenderWindow * window, vehicle& v) {
	if (Rightforce) {
		Vector2f RF = Vector2f(5, 0);
		v.applyForce(RF);
	}
	if (Leftforce) {
		Vector2f LF = Vector2f(-5, 0);
		v.applyForce(LF);
	}
	if (Upforce) {
		Vector2f UF = Vector2f(0, 5);
		v.applyForce(UF);
	}
	if (Downforce) {
		Vector2f DF = Vector2f(0, -5);
		v.applyForce(DF);
	}
	if (isCohesion) {
		cohesion(v);
	}
	if (isAlignment) {
		alignment(v);
	}
	if (isAlignment) {
		separate(v);
	}
	//cohesion(v);
	//alignment(v);
	//separate(v);
}

void vehicleSystem::rightForce() {
	Rightforce = !Rightforce;
	//cout << Rightforce << endl;
}
void vehicleSystem::leftForce() {
	Leftforce = !Leftforce;
}
void vehicleSystem::upForce() {
	Upforce = !Upforce;
}
void vehicleSystem::downForce() {
	Downforce = !Downforce;
}
void vehicleSystem::AddCohesion() {
	isCohesion = !isCohesion;
}
void vehicleSystem::AddAlignment() {
	isAlignment = !isAlignment;
}
void vehicleSystem::AddSeparate() {
	isAlignment = !isSeparate;
}
