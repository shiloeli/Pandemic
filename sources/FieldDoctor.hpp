#pragma once
#include <iostream>
#include "Player.hpp"

    namespace pandemic{
        class FieldDoctor:public Player{
            public:
            FieldDoctor(Board& board, City city):Player(board,city){}
            FieldDoctor& treat(City city) override;
            std::string role() override;
        };
    }