#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow win(sf::VideoMode(640, 480), "Wow, Is it a window?", sf::Style::Default);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    win.setFramerateLimit(60);
    player.setFillColor(sf::Color::Red);
    player.setOrigin(sf::Vector2f(50.0f, 50.0f));
    player.setPosition(sf::Vector2f((float)(640 / 2), (float)(480 / 2)));
    int speed = 10;

    while (win.isOpen())
    {
        sf::Event ev;
        while (win.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                win.close();
                break;

            case sf::Event::KeyPressed:

                switch (ev.key.code)
                {
                case sf::Keyboard::Left:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        player.move(sf::Vector2f(-1.0f * speed, 1.0f * speed));

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        player.move(sf::Vector2f(-1.0f * speed, -1.0f * speed));
                    else
                        player.move(sf::Vector2f(-1.0f * speed, 0.0f));
                    break;

                case sf::Keyboard::Up:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                        player.move(sf::Vector2f(-1.0f * speed, -1.0f * speed));

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                        player.move(sf::Vector2f(1.0f * speed, 1.0f * speed));
                    else
                        player.move(sf::Vector2f(0.0f, -1.0f * speed));
                    break;

                case sf::Keyboard::Right:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                        player.move(sf::Vector2f(1.0f * speed, 1.0f * speed));

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        player.move(sf::Vector2f(1.0f * speed, -1.0f * speed));
                    else
                        player.move(sf::Vector2f(1.0f * speed, 0.0f));
                    break;

                case sf::Keyboard::Down:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                        player.move(sf::Vector2f(-1.0f * speed, 1.0f * speed));

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                        player.move(sf::Vector2f(1.0f * speed, 1.0f * speed));
                    else
                        player.move(sf::Vector2f(0.0f, 1.0f * speed));
                    break;
                }
                break;
            }
        }
        player.rotate(1);
        win.clear(sf::Color::Green);
        win.draw(player);
        win.display();
    }
    return 0;
}