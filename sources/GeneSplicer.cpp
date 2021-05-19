#include <iostream>
#include <set>
#include "GeneSplicer.hpp"

    using namespace std;

    namespace pandemic{

        GeneSplicer& GeneSplicer::discover_cure(Color color){
            if(my_board.get_discovermap(color)){
                return *this;
            }
            if(!my_board.get_cityvalue(my_city).research_station){
                throw invalid_argument("In the city you are in there is no research station");
            }
            if(my_card.size()>=min_card){
                int count = 0;
                while (count < min_card){
                    my_card.erase(my_card.begin());
                    count++;
                }
                my_board.get_discovermap(color) = true;
                return *this;
            }
                throw logic_error("There are not enough city-colored cards");
        }

        string GeneSplicer::role(){
            return "GeneSplicer";
        }
    }
