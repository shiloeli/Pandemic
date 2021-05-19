#pragma once
#include <iostream>
#include "Player.hpp"

    namespace pandemic{
        class GeneSplicer:public Player{

            public:
                GeneSplicer(Board& board, City city):Player(board,city){}
                GeneSplicer& discover_cure(Color color) override;
                std::string role() override;
        };
    }