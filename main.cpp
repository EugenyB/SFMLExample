#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(0, 0);
    line[0].color  = sf::Color::Red;
    line[1].position = sf::Vector2f(200, 200);
    line[1].color = sf::Color::Red;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) //key
                    window.close();
                if (event.key.code == sf::Keyboard::R) {
                    shape.setFillColor(sf::Color::Red);
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(line, 2, sf::Lines);
        window.display();
    }

    return 0;
}