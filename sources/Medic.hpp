#pragma once 
#include <iostream>
#include "Player.hpp"

namespace pandemic{
    class Medic:public Player{
        public:
            Medic(Board& board, City city):Player(board, city){}
            Medic& treat(City city) override;
            std::string role() override;
    };
}