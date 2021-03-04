#include <iostream>
#include <vector>

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

void ShootingBalls() {
    // Setup window
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Works!");

    // Set framerateLimit to 60fps
    window.setFramerateLimit(60);

    sf::CircleShape hoop;
    sf::CircleShape ball;

    int dir = 0;
  
    bool isShoot = false;

    // set-up hoop
    hoop.setPosition(sf::Vector2f(0.f, 10.f));
    hoop.setRadius(26.f);
    hoop.setFillColor(sf::Color::Black);
    hoop.setOutlineThickness(2);
    hoop.setOutlineColor(sf::Color::Red);

    // set-up ball
    ball.setRadius(20.f);
    ball.setFillColor(sf::Color::Blue);

    // Set the ball position to the bottom of the window - the ball radius * by 2, to get more space and don't touch the border
    ball.setPosition(sf::Vector2f(0.f, window.getSize().y - ball.getRadius() * 2));

    while(window.isOpen()) {
        sf::Event ev;

        while(window.pollEvent(ev)) {
            if(ev.type == sf::Event::Closed)
                window.close();
        }

        // if: Check collision with the left border
        // else if: Check collision with the right border by getting 
        // the hoop position + size and checking if this value is greater than window size.x
        if(hoop.getPosition().x <= 0) {
            dir = 1;
        }
        else if(hoop.getPosition().x + hoop.getRadius() >= window.getSize().x) {
            dir = 0;
        }

        // Move the hoop
        if(dir == 0) {
            hoop.move(-5.f, 0.f);
        }
        else {
            hoop.move(5.f, 0.f);
        }

        // Checking Shooting event
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isShoot)
            isShoot = true;

        // if: Set Ball position relative to the mouse
        // else: MOve the bon forward
        if(!isShoot)
            ball.setPosition(sf::Mouse::getPosition(window).x, ball.getPosition().y);
        else
            ball.move(0.f, -10.f);


        // Check collision with the top border of the window and with the hoops
        if(ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds())) {
            isShoot = false;

            // reset balls position
            ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 2);
        }

        // Draw

        // Clean the old frames on screen
        window.clear(sf::Color::White);

        // Draw the objects
        window.draw(hoop);
        window.draw(ball);

        // Render the screen
        window.display();
    }
}

void ShootingBallsPlusPlus() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Ball Shooter");
	window.setFramerateLimit(60);

	int enemySpawnTimer = 0;
	int shootTimer = 0;

	sf::Vector2f playerCenter;

	sf::CircleShape projectile;
	sf::CircleShape player;
	
	sf::RectangleShape enemy;

	std::vector<sf::CircleShape> projectiles;
	std::vector<sf::RectangleShape> enemies;

	// Set-up player shape
	player.setFillColor(sf::Color::White);
	player.setRadius(35.f);

	// Set the player x to the mid of the window, and the y in the bottom of the window
	player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);

	// Set-up projectile
	projectile.setFillColor(sf::Color::Red);
	projectile.setRadius(10.f);

	// Set-up enemy
	enemy.setFillColor(sf::Color::Magenta);
	enemy.setSize(sf::Vector2f(30.f, 30.f));

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		// Update

		// Player
		// Get the player center position offset
		playerCenter = sf::Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());

		// Makes player follow the cursor (mouse position relative to the window) (x axis)
		player.setPosition(sf::Mouse::getPosition(window).x, player.getPosition().y);

		// Projectiles
		if(shootTimer < 6)
			shootTimer++;

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootTimer >= 6) {
			// Set the correct offset position relative to the player center
			projectile.setPosition(playerCenter - sf::Vector2f(10.f, 35.f));

			// Add the projectile shape to the projectiles vector list
			projectiles.push_back(sf::CircleShape(projectile));

			// reset shoot cooldown
			shootTimer = 0;
		}

		// Shoot and Destroy projectiles
		for(int i = 0; i < projectiles.size(); i++) {
			// Move the projectile upwards
			projectiles[i].move(0.f, -10.f);

			// Destroy the projectile when he reach the window top border
			if(projectiles[i].getPosition().y <= 0)
				projectiles.erase(projectiles.begin() + i);
		}

		//Enemues
		if(enemySpawnTimer < 20)
			enemySpawnTimer++;

		if(enemySpawnTimer >= 20) {
			// Spawn the enemies in a random x position, and in the top of the window
			enemy.setPosition((rand() % int(window.getSize().x - enemy.getSize().x)), 0.f);

			// Ad the enemy shape to the enemies vector list
			enemies.push_back(sf::RectangleShape(enemy));

			// Reset enemy spawn cooldown
			enemySpawnTimer = 0;
		}

		// Move and Destroy enemies
		for(int i = 0; i < enemies.size(); i++) {
			// Move the spawned enemies
			enemies[i].move(0.f, 3.f);

			// Destroy the enemies that Reached the bottom of the screen
			if(enemies[i].getPosition().y > window.getSize().y)
				enemies.erase(enemies.begin() + i);
		}

		//Collision
		// Check if the enemies and the projectiles vector is empty
		// if's not run through all their element
		// and check if they're colliding 
		// if's true erase both.
		if(!enemies.empty() && !projectiles.empty())
			for(int i = 0; i < projectiles.size(); i++)
				for(int k = 0; k < enemies.size(); k++)
					if(projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds())) {
						projectiles.erase(projectiles.begin() + i);
						enemies.erase(enemies.begin() + k);

						break;
					}

	
		// Draw
		// Clean the old frames
		window.clear();

			// Draw the player
			window.draw(player);

			// Draw all the enemies
			for (int i = 0; i < enemies.size(); i++)
				window.draw(enemies[i]);

			// Draw all the projectiles
			for (int i = 0; i < projectiles.size(); i++)
				window.draw(projectiles[i]);

		// Render the window content
		window.display();
	}
}

int main() {
	// ShootingBalls();
    ShootingBallsPlusPlus();
}