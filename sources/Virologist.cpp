#include <iostream>
#include <exception>
#include "Virologist.hpp"

    using namespace std;

    namespace pandemic{

        Virologist& Virologist::treat(City city){
            
            if(my_card.count(city) == 0 && city != my_city){
                throw logic_error("You do not have the appropriate city card");
            }
            if(my_board.get_cityvalue(city).disease_level==0){
                throw logic_error("It is not possible to lower the disease level below 0");
            }
            Color my_color = my_board.get_cityvalue(city).color;
            if(my_board.get_discovermap(my_color)){
               my_board.get_cityvalue(city).disease_level=0;
            }else{
                my_board.get_cityvalue(city).disease_level--;
            }
            my_card.erase(city);
            return *this;
        }
      
        std::string Virologist::role(){
            return "Virologist";
        }
    } 