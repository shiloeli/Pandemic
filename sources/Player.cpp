#include <iostream>
#include <unordered_map>
#include <exception>
#include "Player.hpp"

using namespace std;

    namespace pandemic{

        Player& Player::drive(City city){
            if(my_city == city){
                throw logic_error("You can not drive to the city where you are");
            }
            if( my_board.get_cityvalue(my_city).neighbors.count(city) != 0){
                my_city = city;
                if(this->role() == "Medic" && my_board.get_discovermap(my_board.get_cityvalue(city).color)){
                    my_board.get_cityvalue(city).disease_level = 0;
                }
                return *this;
            }
            throw logic_error("Attempt to move between non-neighboring cities");    
            }
        

        Player& Player::fly_direct(City city){
            if(my_city == city){
                throw logic_error("You can not fly to the city where you are");
            }

            if(my_card.count(city) != 0){
                my_city = city;
                my_card.erase(city);
            }else{
                throw logic_error("The appropriate card for the city you want to fly to has not been found");
            }
            if(this->role() == "Medic" && my_board.get_discovermap(my_board.get_cityvalue(city).color)){
                my_board.get_cityvalue(city).disease_level = 0;
            }
            return *this;
        }

        Player& Player::fly_charter(City city){
            if(my_city == city){
                throw logic_error("You can not fly to the city where you are");
            }
            if(my_card.count(my_city) == 0){
                throw logic_error("You do not have the card of the city you want to fly to");
            }
            City old_city = my_city;
            my_city = city;
            my_card.erase(old_city);
        
            if(this->role() == "Medic" && my_board.get_discovermap(my_board.get_cityvalue(city).color)){
                my_board.get_cityvalue(city).disease_level = 0;
            }
            return *this;
        }

        Player& Player::fly_shuttle(City city){
            if(my_city == city){
                throw logic_error("You can not fly to the city where you are");
            }
            if(my_board.get_cityvalue(my_city).research_station && my_board.get_cityvalue(city).research_station){
                my_city = city;
                if(this->role() == "Medic" && my_board.get_discovermap(my_board.get_cityvalue(city).color)){
                    my_board.get_cityvalue(city).disease_level = 0;
                }
                return *this;
            }
            throw invalid_argument("There is no research station in the city");
        }

        Player& Player::build(){
            if(my_card.count(my_city) == 0){
                throw logic_error("You do not have the card of the city you want to fly to");
            }
            if(!my_board.get_cityvalue(my_city).research_station){
                my_board.get_cityvalue(my_city).research_station = true;
                my_card.erase(my_city);
            }
            return *this;
        }

        Player& Player::discover_cure(Color color){
            if(!my_board.get_cityvalue(my_city).research_station){
                throw invalid_argument("In the city you are in there is no research station");
            }
            if(my_board.get_discovermap(color)){
                return *this;
            }
            if(my_card.size() >= min_card){
                set <City> throw_card;
                for(auto const &pair: my_card){
                    if(pair.second == color){
                        throw_card.insert(pair.first);
                    }
                    if(throw_card.size() == min_card){
                        for(auto const &del_city: throw_card){
                            my_card.erase(del_city);
                        }
                        my_board.get_discovermap(color) = true;
                        return *this;
                    }
                }
            }
            throw logic_error("There are not enough city-colored cards");
        }

        Player& Player::treat(City city){
            if(city != my_city){
                throw logic_error("1The function must accept the city you are in as a parameter");
            }
            if(my_board.get_cityvalue(city).disease_level==0){
                throw logic_error("It is not possible to lower the disease level below 0");
            }
            Color my_color = my_board.get_cityvalue(my_city).color;
            if(my_board.get_discovermap(my_color)){
                my_board.get_cityvalue(my_city).disease_level=0;
            }else{
                my_board.get_cityvalue(my_city).disease_level--;
            }
            return *this;
        }
      
        string Player::role(){
            return "Player";
        }

        Player& Player::take_card(City city){
            my_card[city] = this->my_board.get_cityvalue(city).color;
            return *this;
        }

        Player& Player::remove_cards(City city){
            for(const auto &pair : my_card){
                my_card.erase(pair.first);
            }
            return *this;
        }
    }
