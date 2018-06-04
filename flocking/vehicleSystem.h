#pragma once
#include "vehicle.h"

class vehicleSystem {

public:
	vehicleSystem();
	~vehicleSystem();
	void update(sf::RenderWindow* window, float dt);
	void render(sf::RenderWindow* window);

	void addVehicles(sf::RenderWindow* window);
	void removeVehicle();
	void applyBehaviors(sf::RenderWindow * window, vehicle& v);

	void separate(vehicle& v);
	void alignment(vehicle& v);
	void cohesion(vehicle& v);

	void rightForce();
	bool Rightforce = false;
	void leftForce();
	bool Leftforce = false;
	void upForce();
	bool Upforce = false;
	void downForce();
	bool Downforce = false;
	void AddCohesion();
	bool isCohesion = false;
	void AddAlignment();
	bool isAlignment = false;
	void AddSeparate();
	bool isSeparate = false;

	std::vector<vehicle> boids;

};