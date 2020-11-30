#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

#include "player.h"
#include "enemies.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1200), "Game");

	Player bob(32, 32);
	Enemies enemies(100);
	unsigned int frameCount = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				bob.OnKeyTyped(event.key.code);
			}

			if (event.type == sf::Event::KeyReleased)
			{
				bob.OnKeyReleased(event.key.code);
			}
		}

		bob.Update(enemies.myEnemies, enemies.myEnemyCount);

		if (frameCount % 2 == 0)
		{
			enemies.Update(bob.myBullets, bob.myBulletCount);
		}



		window.clear();

		bob.Draw(window);
		enemies.Draw(window);

		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		frameCount++;
	}

	return 0;
}