#include <iostream>
#include "player.h"

int main(){
    std::cout<<"Let it be"<<std::endl;
    Player a(0,0);
    a.move(10,10);
    a.getPosition();

    return 0;
}