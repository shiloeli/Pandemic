#pragma once
#include <iostream>
#include <unordered_map>
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{

    class Board{
        private:
            std::unordered_map<pandemic::City, pandemic::City_value> board_map;
            std::unordered_map<Color, bool> discover_map;

        public:     
            Board();

            void update_boardmap();
            void update_discovermap();
            City_value& get_cityvalue( City city);
            bool& get_discovermap(Color color);
            
            int& operator[](City city);
            friend std::ostream& operator<<(std::ostream& out, const Board& board);

            bool is_clean();
            void remove_cures();
    };
}
