#include <iostream>
#include <string>
#include "Medic.hpp"

    using namespace std;
    
    namespace pandemic{

        Medic& Medic::treat(City city){
            if(city != my_city){
                throw logic_error("You can't take care of a city you are not in");
            }
            if(my_board.get_cityvalue(my_city).disease_level == 0){
                throw logic_error("The disease level cannot be lowered below 0");
            }
            my_board.get_cityvalue(my_city).disease_level=0;
            return *this;
        }

        string Medic::role(){
            return "Medic";
        }
        
        

    }
           
           
