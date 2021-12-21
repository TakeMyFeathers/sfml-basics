#include "player.h"

#include <iostream>

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
}

Player::Player(){
    this->x = 0;
    this->y = 0;
}

void Player::move(int dx, int dy)
{
    x+=dx*speed;
    y+=dy*speed;
}

void Player::getPosition()
{
    std::cout<<"x: "<<this->x<<", "<<"y: "<<this->y<<std::endl;
}