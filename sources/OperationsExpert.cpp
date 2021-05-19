#include <iostream>
#include "OperationsExpert.hpp"

   using namespace std;

   namespace pandemic{

      OperationsExpert& OperationsExpert::build(){
         OperationsExpert::my_board.get_cityvalue(my_city).research_station = true;
         return *this;
      }

      string OperationsExpert::role(){
         return "OperationsExpert";
      }   

    }

