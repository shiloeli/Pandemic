#include <iostream>
#include <unordered_map>
#include <string>
#include "Board.hpp"

using namespace std;

namespace pandemic{

    Board::Board(){update_boardmap();
        update_discovermap();}

    void Board::update_boardmap(){
        pandemic::Board::board_map[City::Algiers] = pandemic::City_value(Color::Black, {City::Madrid,City::Paris,City::Istanbul,City::Cairo},"Algiers");
        pandemic::Board::board_map[City::Atlanta] = pandemic::City_value(Color::Blue, {City::Chicago,City::Miami,City::Washington},"Atlanta");
        pandemic::Board::board_map[City::Baghdad] = pandemic::City_value(Color::Black, {City::Tehran,City::Istanbul,City::Cairo,City::Riyadh,City::Karachi},"Baghdad");
        pandemic::Board::board_map[City::Bangkok] = pandemic::City_value(Color::Red, {City::Kolkata,City::Chennai,City::Jakarta,City::HoChiMinhCity,City::HongKong},"Bangkok");
        pandemic::Board::board_map[City::Beijing] = pandemic::City_value(Color::Red, {City::Shanghai,City::Seoul},"Beijing");
        pandemic::Board::board_map[City::Bogota] = pandemic::City_value(Color::Yellow, {City::MexicoCity,City::Lima,City::Miami,City::SaoPaulo,City::BuenosAires},"Bogota");
        pandemic::Board::board_map[City::BuenosAires] = pandemic::City_value(Color::Yellow, {City::Bogota,City::SaoPaulo},"BuenosAires");
        pandemic::Board::board_map[City::Cairo] = pandemic::City_value(Color::Black, {City::Algiers,City::Istanbul,City::Baghdad,City::Khartoum,City::Riyadh},"Cairo");
        pandemic::Board::board_map[City::Chennai] = pandemic::City_value(Color::Black, {City::Mumbai,City::Delhi,City::Kolkata,City::Bangkok,City::Jakarta},"Chennai");
        pandemic::Board::board_map[City::Chicago] = pandemic::City_value(Color::Blue, {City::SanFrancisco,City::LosAngeles,City::MexicoCity,City::Atlanta,City::Montreal},"Chicago");
        pandemic::Board::board_map[City::Delhi] = pandemic::City_value(Color::Black, {City::Tehran,City::Karachi,City::Mumbai,City::Chennai,City::Kolkata},"Delhi");
        pandemic::Board::board_map[City::Essen] = pandemic::City_value(Color::Blue, {City::London,City::Paris,City::Milan,City::StPetersburg},"Essen");
        pandemic::Board::board_map[City::HoChiMinhCity] = pandemic::City_value(Color::Red, {City::Jakarta,City::Bangkok,City::HongKong,City::Manila},"HoChiMinhCity");
        pandemic::Board::board_map[City::HongKong] = pandemic::City_value(Color::Red, {City::Bangkok,City::Kolkata,City::HoChiMinhCity,City::Shanghai,City::Manila,City::Taipei},"HongKong");
        pandemic::Board::board_map[City::Istanbul] = pandemic::City_value(Color::Black, {City::Milan,City::Algiers,City::StPetersburg,City::Cairo,City::Baghdad,City::Moscow},"Istanbul");
        pandemic::Board::board_map[City::Jakarta] = pandemic::City_value(Color::Red, {City::Chennai,City::Bangkok,City::HoChiMinhCity,City::Sydney},"Jakarta");
        pandemic::Board::board_map[City::Johannesburg] = pandemic::City_value(Color::Yellow, {City::Kinshasa,City::Khartoum},"Johannesburg");
        pandemic::Board::board_map[City::Karachi] = pandemic::City_value(Color::Black, {City::Tehran,City::Baghdad,City::Riyadh,City::Mumbai,City::Delhi},"Karachi");
        pandemic::Board::board_map[City::Khartoum] = pandemic::City_value(Color::Yellow, {City::Cairo,City::Lagos,City::Kinshasa,City::Johannesburg},"Khartoum");
        pandemic::Board::board_map[City::Kinshasa] = pandemic::City_value(Color::Yellow, {City::Lagos,City::Khartoum,City::Johannesburg},"Kinshasa");
        pandemic::Board::board_map[City::Kolkata] = pandemic::City_value(Color::Black, {City::Delhi,City::Chennai,City::Bangkok,City::HongKong},"Kolkata");
        pandemic::Board::board_map[City::Lagos] = pandemic::City_value(Color::Yellow, {City::SaoPaulo,City::Khartoum,City::Kinshasa},"Lagos");
        pandemic::Board::board_map[City::Lima] = pandemic::City_value(Color::Yellow, {City::MexicoCity,City::Bogota,City::Santiago},"Lima");
        pandemic::Board::board_map[City::London] = pandemic::City_value(Color::Blue, {City::NewYork,City::Madrid,City::Essen,City::Paris},"London");
        pandemic::Board::board_map[City::LosAngeles] = pandemic::City_value(Color::Yellow, {City::SanFrancisco,City::Chicago,City::MexicoCity,City::Sydney},"LosAngeles");
        pandemic::Board::board_map[City::Madrid] = pandemic::City_value(Color::Blue, {City::London,City::NewYork,City::Paris,City::SaoPaulo,City::Algiers},"Madrid");
        pandemic::Board::board_map[City::Manila] = pandemic::City_value(Color::Red, {City::Taipei,City::SanFrancisco,City::HoChiMinhCity,City::Sydney,City::HongKong},"Manila");
        pandemic::Board::board_map[City::MexicoCity] = pandemic::City_value(Color::Yellow, {City::LosAngeles,City::Chicago,City::Miami,City::Lima,City::Bogota},"MexicoCity");
        pandemic::Board::board_map[City::Miami] = pandemic::City_value(Color::Yellow, {City::Atlanta,City::MexicoCity,City::Washington,City::Bogota},"Miami");
        pandemic::Board::board_map[City::Milan] = pandemic::City_value(Color::Blue, {City::Essen,City::Paris,City::Istanbul},"Milan");
        pandemic::Board::board_map[City::Montreal] = pandemic::City_value(Color::Blue, {City::Chicago,City::Washington,City::NewYork},"Montreal");
        pandemic::Board::board_map[City::Moscow] = pandemic::City_value(Color::Black, {City::StPetersburg,City::Istanbul,City::Tehran},"Moscow");
        pandemic::Board::board_map[City::Mumbai] = pandemic::City_value(Color::Black, {City::Karachi,City::Delhi,City::Chennai},"Mumbai");
        pandemic::Board::board_map[City::NewYork] = pandemic::City_value(Color::Blue, {City::Montreal,City::Washington,City::London,City::Madrid},"NewYork");
        pandemic::Board::board_map[City::Osaka] = pandemic::City_value(Color::Red, {City::Taipei,City::Tokyo},"Osaka");
        pandemic::Board::board_map[City::Paris] = pandemic::City_value(Color::Blue, {City::Algiers,City::Essen,City::Madrid,City::Milan,City::London},"Paris");
        pandemic::Board::board_map[City::Riyadh] = pandemic::City_value(Color::Black, {City::Baghdad,City::Cairo,City::Karachi},"Riyadh");
        pandemic::Board::board_map[City::SanFrancisco] = pandemic::City_value(Color::Blue, {City::LosAngeles,City::Chicago,City::Tokyo,City::Manila},"SanFrancisco");
        pandemic::Board::board_map[City::Santiago] = pandemic::City_value(Color::Yellow, {City::Lima},"Santiago");
        pandemic::Board::board_map[City::SaoPaulo] = pandemic::City_value(Color::Yellow, {City::Bogota,City::BuenosAires,City::Lagos,City::Madrid},"SaoPaulo");
        pandemic::Board::board_map[City::Seoul] = pandemic::City_value(Color::Red, {City::Beijing,City::Shanghai,City::Tokyo},"Seoul");
        pandemic::Board::board_map[City::Shanghai] = pandemic::City_value(Color::Red, {City::Beijing,City::HongKong,City::Taipei,City::Seoul,City::Tokyo},"Shanghai");
        pandemic::Board::board_map[City::StPetersburg] = pandemic::City_value(Color::Blue, {City::Essen,City::Istanbul,City::Moscow},"StPetersburg");
        pandemic::Board::board_map[City::Sydney] = pandemic::City_value(Color::Red, {City::Jakarta,City::Manila,City::LosAngeles},"Sydney");
        pandemic::Board::board_map[City::Taipei] = pandemic::City_value(Color::Red, {City::Shanghai,City::HongKong,City::Osaka,City::Manila},"Taipei");
        pandemic::Board::board_map[City::Tehran] = pandemic::City_value(Color::Black, {City::Baghdad,City::Moscow,City::Karachi,City::Delhi},"Tehran");
        pandemic::Board::board_map[City::Tokyo] = pandemic::City_value(Color::Red, {City::Seoul,City::Shanghai,City::Osaka,City::SanFrancisco},"Tokyo");
        pandemic::Board::board_map[City::Washington] = pandemic::City_value(Color::Blue, {City::Atlanta,City::NewYork,City::Montreal,City::Miami},"Washington");
    }

    void Board::update_discovermap(){
        pandemic::Board::discover_map[Color::Black] = false;
        pandemic::Board::discover_map[Color::Blue] = false;
        pandemic::Board::discover_map[Color::Red] = false;
        pandemic::Board::discover_map[Color::Yellow] = false;
    }

    City_value& Board::get_cityvalue(City city){
        return board_map[city];
    }
    bool& Board::get_discovermap(Color color){
        return discover_map[color];
    }

    int& Board::operator[](City city){
        return board_map[city].disease_level;
    }


    ostream& operator<<(ostream& out, const Board& board){
        cout<<"=========== My Board ==============="<<endl;
            for(const auto &pair : board.board_map){
                cout<<"Board["+pair.second.name+"]="+to_string(pair.second.disease_level)+
                ", research_station:"+to_string(static_cast<int>(pair.second.research_station))<<endl;
            }
        cout<<"=========== Medicaments Detected ============="<<endl;
            for(const auto &pair2 : board.discover_map){
                if(pair2.second){
                    cout<<"Medication:"+City_value::get_colorName(pair2.first)+"."<<endl;
                }
            }
        return out;
    }

    bool Board::is_clean(){
        for(auto const &pair: board_map){
            if(pandemic::Board::board_map[pair.first].disease_level>0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        for(auto &pair: this->discover_map){
            if(pair.second){
                pair.second = false;
            }
        }
    }  
}