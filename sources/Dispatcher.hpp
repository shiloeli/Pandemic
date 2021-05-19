#pragma once
#include <iostream>

#include "Player.hpp"

    namespace pandemic {
        class Dispatcher:public Player{
            public:
                Dispatcher(Board& board, City city):Player(board,city){}
                Dispatcher& fly_direct(City city) override;
                std::string role() override;
        };
    }