#include <iostream>
#include <exception>
#include "Scientist.hpp"

    using namespace std;

    namespace pandemic{

        Scientist& Scientist::discover_cure(Color color){
            if(!my_board.get_cityvalue(my_city).research_station){
                throw logic_error("You are in a city without a research station");
            }
            if(my_board.get_discovermap(color)){
                return *this;
            }   
            if(my_card.size()<my_num){
                throw logic_error("You do not have enough cards to discard");
            }
            set <City> throw_card;
            for(const auto &pair: my_card){
                throw_card.insert(pair.first);
                if(throw_card.size() == my_num){
                    break;
                }
            }
            for(const auto &del_city: throw_card){
                my_card.erase(del_city);
            }
            my_board.get_discovermap(color) = true;
            return *this;
            }
            
        string Scientist::role(){
            return "Scientist";
        }
    }
