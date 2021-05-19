
#include"Scientist.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;


namespace pandemic{

    Player &Scientist::discover_cure(Color c)
        {
        if (meditions.count(c) != 0){return *this;}
        
        if (board.is_research_station(city))
        {
                int color = 0;
                for(const auto &card: this->cards){
                        if (board.colorOfCity(card) == c)  
                         {       color++;   }
                         if(color >= num){break;}
                        
                }
                if (color < num)
                {
                throw invalid_argument("Not enough cards");        
                }
                
                color = 0;
                City temp[num];
                for(auto &card: this->cards){
                        if (board.colorOfCity(card) == c)
                        {
                                temp[color] = card;
                                color++;
                        }
                        if(color >= num){break;}
                }
            
             board.markRecovery(c);
                meditions.insert(c);
                return *this;
        }
        throw invalid_argument("Not heve research station");        
    }
};