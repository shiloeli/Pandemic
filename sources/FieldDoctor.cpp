#include <iostream>
#include "FieldDoctor.hpp"

    using namespace std;
    namespace pandemic{

        FieldDoctor& FieldDoctor::treat(City city){
           if(city == my_city || my_board.get_cityvalue(my_city).neighbors.count(city) != 0){
               if(my_board.get_cityvalue(city).disease_level==0){
                   throw logic_error("It is not possible to lower the disease level below 0");
               }
                Color my_color = my_board.get_cityvalue(city).color;
                if(my_board.get_discovermap(my_color)){
                    my_board.get_cityvalue(city).disease_level=0;
                }else{
                    my_board.get_cityvalue(city).disease_level--;
                }
                if(my_board.get_cityvalue(my_city).neighbors.count(city) == 0){
                    my_card.erase(city);
                }
                return *this;
            }
            throw logic_error("At least one of the conditions is not met");
        }

        string FieldDoctor::role(){
            return "FieldDoctor";
        }
    }