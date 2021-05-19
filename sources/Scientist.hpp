#pragma once
#include <iostream>
#include "Player.hpp"

    namespace pandemic{
        class Scientist:public Player{
            
            public:
                int my_num;
                Scientist(Board& board, City city, int num):Player(board,city),my_num(num){}
                Scientist& discover_cure(Color color) override;
                std::string role() override;
        };
    }