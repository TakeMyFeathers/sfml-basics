#pragma once

class Player
{
public:
    int x, y;
    int speed=10;

    Player();
    Player(int x, int y);
    void move(int dx, int dy);
    void getPosition();
};