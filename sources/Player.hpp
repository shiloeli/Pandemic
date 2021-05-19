#pragma once
#include <iostream>
#include <unordered_map>
#include "Board.hpp"

namespace pandemic{
    class Player{
        #define min_card 5
        public:
            std::unordered_map<City, Color> my_card;
            Board& my_board;
            pandemic::City my_city;
            
            Player(Board& board, City city):my_board(board),my_city(city){}
            Player& drive(City city);
            virtual Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City city);
            virtual std::string role();
            Player& take_card(City city);
            Player& remove_cards(City city);
    };
}
            