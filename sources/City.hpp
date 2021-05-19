#pragma once
#include <iostream>
#include <unordered_map>
#include <set>
#include "City.hpp"

namespace pandemic{

    enum class City{
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };

    class City_value{
        public:
            Color color;
            std::string name;
            int disease_level;
            bool research_station;
            std::set<City> neighbors; 

            City_value(){}

            City_value(Color color2, std::set<City> neighbors2, std::string name2){
                this->name = name2;
                this->disease_level = 0;
                this->color = color2;
                this->neighbors = neighbors2;
                this->research_station = false;
            }

            static std::string get_colorName(enum Color color){
                switch (color){
                    case Color::Black:
                        return "Black";
                    case Color::Blue:
                        return "Blue";
                    case Color::Red:
                        return "Red";
                    case Color::Yellow:
                        return "Yellow";
            }
        }

    };
}