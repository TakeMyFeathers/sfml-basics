#include "Game.h"
#include <iostream>
#include <vector>
#include <ctime>

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}

void Game::initVariables()
{
    this->window = nullptr;
    this->points = 0;
    this->enemySpwamTimerMax = 1000.0f;
    this->enemySpawnTimer = this->enemySpwamTimerMax;
    this->maxEnemies = 5;
}

void Game::initWindow()
{
    this->videoMode.width = 640;
    this->videoMode.height = 480;
    this->window = new sf::RenderWindow(this->videoMode, "My first game", sf::Style::Default);
    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.0f);
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::updateMousePosition()
{
    this->windowMousePosition = sf::Mouse::getPosition();
}

void Game::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % (static_cast<int>(this->window->getSize().x - this->enemy.getSize().x))), 0.0f);

    this->enemy.setFillColor(sf::Color::Yellow);
    this->enemies.push_back(this->enemy);
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateMousePosition();
    this->updateEnemies();
}

void Game::updateEnemies()
{
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpwamTimerMax)
        {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.0f;
        }
        else
            this->enemySpawnTimer += 1.0f;

        for (auto &e : this->enemies)
        {
            e.move(0.0f, 2.0f);
        }
    }
}

void Game::renderEnemies()
{
    for (auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}

void Game::render()
{
    this->window->clear(sf::Color::Green);
    this->renderEnemies();
    this->window->display();
}