#include"Dispatcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic{
    
    Player& Dispatcher::fly_direct(City c){

        if (this->city == c)
        {
         throw runtime_error{"It is impossible to fly direct from the city where you are to the same city where you are now"}; 
        }
        
        if(board.is_research_station(city)){
            this->city = c;
            return *this;
        }
        
        if (cards.count(c) != 0)
        {
            cards.erase(c);
                this->city = c;
               
        }
        else
        {
                throw runtime_error("Not in the cards!");
        }
        return *this;
    }
};