#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include "Player.hpp"

using namespace pandemic;
using namespace std;
const int for_discover_cure = 5;

Player &Player::take_card(City c)
{
        cards.insert(c);
        return *this;
}
Player &Player::drive(City c)
{
        if(city == c){
            throw runtime_error{"It is impossible to drive from the city"};     
        }
        if (board.connectedCity(city, c))
        {
                city = c;
        }
        else
        {
                throw invalid_argument("Not Neighbor City");
        }
        flyall(city);
        return *this;
}
Player &Player::fly_direct(City c)
{
         if (city == c){
           throw invalid_argument("Not in the cards!");
         }
        if ( cards.count(c) == 0)
        {
                throw invalid_argument("Not in the cards!");
        }
        city = c;
        cards.erase(c);
        flyall(city);
        return *this;
}
Player &Player::fly_charter(City c)
{
            if(city == c){
        throw runtime_error{"fly from the city where you are to the same city where you are now"};
    }
        if (cards.count(city) == 0)
        {
                      throw invalid_argument("Not in the cards!");
              
        }
      cards.erase(city);
                city = c;
        flyall(city);
        return *this;
}
Player &Player::fly_shuttle(City c)
{
            if(city == c){
        throw runtime_error{"to drive from the city where you are to the same city where you are now"};
    }
            if (!board.is_research_station(city)){
        throw runtime_error{" fly to a city where there is a research station you must be in a city where there is a research station."};

            }
            if(!board.is_research_station(c)){
              throw runtime_error{" research station you can only move to a city with a research station in this method."};
            }

    
         city = c;
        flyall(city);
        return *this;
}
Player &Player::build()

{
        if (board.is_research_station(city))
        {
                return *this;
        }

        if (cards.count(city) == 0)
        {
                  throw invalid_argument("No card");      
              
        }
              board.build_research_station(city);
                cards.erase(city);

        return *this;
}
Player &Player::discover_cure(Color c)
{
        if (meditions.count(c) != 0){
                return *this;}


        
        if (board.is_research_station(city))
        {
                int i = 0;
                for(auto &card: cards){
                        if (board.colorOfCity(card) == c)
                        {
                                i++;
                        }
                }
                if (i < for_discover_cure)
                {
                throw invalid_argument("Not enough cards");        
                }
                i = 0;
                City t[for_discover_cure];
                for(auto &card: cards){
                        if (board.colorOfCity(card) == c)
                        {
                                t[i] = card;
                                i++;
                        }
                        if(i == for_discover_cure){break;}
                }
                for (size_t i = 0; i < for_discover_cure; i++)
                {
                        cards.erase(t[i]);
                }
                
                board.markRecovery(c);
                meditions.insert(c);
                return *this;
        }
        throw invalid_argument("Not heve research station");        

}
Player &Player::treat(City c)
{
        if(c != city){
         throw runtime_error{" treat city if it is not your city where are you now"};
        }
        if(board[c]==0){
                        throw runtime_error{" not possible to lower the disease level because the disease level is 0"};

        }
        
        if ( board[c] > 0)
        {
                if (board.CureDiscoverd(c)){board[c] = 0;}
                else{board[c]--;}
                return *this;
        }
        throw invalid_argument("illigel treat");
}
string Player::role() { return Role; }
