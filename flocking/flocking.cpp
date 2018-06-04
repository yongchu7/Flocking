#include "world.h"
#include "vehicleSystem.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "flocking");
	sf::Clock clock;
	sf::Clock time;
	float timer = .2f;
	float dt;
	vehicleSystem* vehiclesystem = new vehicleSystem();

	Music music;
	music.openFromFile("BGM.ogg");
	music.play();
	Font font;
	font.loadFromFile("arial.ttf");
	Text intro("Welcome to my Flocking! Press up,down,right,left to control the force directions, press A, S, C to turn on the alignment, separate, cohesion ",font);
	intro.setCharacterSize(12);
	intro.setPosition(10, 30);
	intro.setColor(sf::Color::Green);
	Text control("Mouse left click to add vehicles, right click to remove vehicles!", font);
	control.setCharacterSize(12);
	control.setPosition(10, 40);
	control.setColor(sf::Color::Green);
	Text thank("Thank you for watching!", font);
	thank.setCharacterSize(50);
	thank.setPosition(150, 250);
	thank.setColor(sf::Color::Green);




	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (timer < .3f)
			timer += time.restart().asSeconds();
		else
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				vehiclesystem->addVehicles(&window);
				timer = 0;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				vehiclesystem->removeVehicle();
				timer = 0;
			}
		}
		dt = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			vehiclesystem->rightForce();
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			vehiclesystem->leftForce();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			vehiclesystem->upForce();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			vehiclesystem->downForce();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			vehiclesystem->AddCohesion();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			vehiclesystem->AddAlignment();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			vehiclesystem->AddSeparate();
		}
	
		
		vehiclesystem->update(&window, dt);
		window.clear();
		vehiclesystem->render(&window);
		window.draw(intro);
		window.draw(control);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
			window.draw(thank);
		}

		window.display();
	}

	return 0;
}
