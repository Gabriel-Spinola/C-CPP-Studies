#include <iostream>

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);

    while(window.isOpen()) {
        sf::Event ev;

        while(window.pollEvent(ev)) {
            if(ev.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}