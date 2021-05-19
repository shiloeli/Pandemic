#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    Board board;
	board[City::Algiers] = 10;      
	board[City::Atlanta] = 2;      
	board[City::Baghdad] = 5;    
	board[City::Manila] = 2; 
	board[City::Beijing ] = 1;   

    OperationsExpert player {board, City::Algiers}; 
	player.take_card(City::Johannesburg)
    	.take_card(City::Khartoum)
	    .take_card(City::SaoPaulo)
	    .take_card(City::BuenosAires)
	    .take_card(City::HoChiMinhCity);   

    player.build();
    
		player.drive(City::Madrid);  
	try {
		player.drive(City::Atlanta);  
	} catch (const exception& ex) {
	 	cout << "exception: " << ex.what() << endl;
	}

	player.fly_direct(City::HoChiMinhCity);  
	try {
		player.fly_direct(City::Taipei);  
	} catch (const exception& ex) {
	 	cout << " exception: " << ex.what() << endl;  
	}


	player.drive(City::Manila);    
	cout << board[City::Manila] << endl; 
	player.treat(City::Manila);   
	cout << board[City::Manila] << endl; 
	player.treat(City::Manila);    
	cout << board[City::Manila] << endl; 
	try {
		player.treat(City::Manila); 
	} catch (const exception& ex) {
	 	cout << "exception: " << ex.what() << endl; 
	}
	try {
		player.treat(City::Washington);  
	} catch (const exception& ex) {
	 	cout << "exception: " << ex.what() << endl;  
	}

	player.take_card(City::Sydney);

	player.drive(City::Sydney);
	player.fly_charter(City::NewYork);  

	try {
		player.fly_charter(City::Seoul); 
	} catch (const exception& ex) {
	 	cout << "exception3: " << ex.what() << endl;  
	}

	try{
	player.drive(City::LosAngeles); 
	}catch(const exception& ex) {
		cout << "exception4: " << ex.what() << endl;  
	}
	player.build(); 
	player.drive(City::Montreal);
	player.build();   

	player.fly_shuttle(City::NewYork);  
	try {
		player.fly_shuttle(City::Chicago); 
	} catch (const exception& ex) {
	 	cout << "exception: " << ex.what() << endl; 
	}

	player.take_card(City::Atlanta);
	player.take_card(City::Chicago);
	player.take_card(City::Essen);
	player.take_card(City::Madrid);
	player.take_card(City::Milan);
	try {
		player.discover_cure(Color::Blue); 
	} catch (const exception& ex) {
	 	cout << "exception: " << ex.what() << endl;  
	}
	cout<<board<<endl;
}