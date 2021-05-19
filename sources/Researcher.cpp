#include <iostream>
#include <exception>
#include "Researcher.hpp"

    using namespace std;

    namespace pandemic{

        Researcher& Researcher::discover_cure(Color color){
              if(my_board.get_discovermap(color)){
                return *this;
            }
            if(my_card.size()>= min_card){
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

        string Researcher::role(){
            return "Researcher";
        }
    }