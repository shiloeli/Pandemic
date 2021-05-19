#include <iostream>
#include <exception>
#include "Dispatcher.hpp"

using namespace std;

    namespace pandemic{

        Dispatcher& Dispatcher::fly_direct(City city){
            if(my_city == city){
                throw logic_error("You can not fly to the city where you are");
            }
            if(my_board.get_cityvalue(my_city).research_station){
                this->my_city = city;
                return *this;
            }
            if(my_card.count(city) !=0){
                my_city = city;
                my_card.erase(city);
                return *this;
            }
            throw logic_error("There is no research station in the city you are in");   
        }

        string Dispatcher::role(){
            return "Dispatcher";
        }
    }