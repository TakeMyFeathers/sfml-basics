#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow *window;
    sf::Event ev;
    sf::VideoMode videoMode;
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    sf::Vector2i windowMousePosition;

    int points;
    float enemySpawnTimer;
    float enemySpwamTimerMax;
    int maxEnemies;

private:
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    Game();
    ~Game();

    const bool running() const;

    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    void pollEvents();
    void updateMousePosition();
    void update();
    void render();
};