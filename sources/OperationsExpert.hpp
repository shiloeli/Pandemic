#pragma once
#include <iostream>
#include "Player.hpp"

namespace pandemic{
    class OperationsExpert:public Player{
        public:
            OperationsExpert(Board& board, City city):Player(board,city){}
            OperationsExpert();
            OperationsExpert& build() override; 
            std::string role() override;
    };
}