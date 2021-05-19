#pragma once
#include <iostream>
#include "Player.hpp"

    namespace pandemic{
        class Virologist:public Player{
            public:
            Virologist(Board& board, City city):Player(board, city){}
            Virologist& treat(City city) override;
            std::string role() override;
        };
    }