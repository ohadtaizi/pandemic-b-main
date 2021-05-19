#include "GeneSplicer.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
const int fiveCards = 5;

namespace pandemic
{
    
    Player &GeneSplicer::discover_cure(Color c)
    {

         if (meditions.count(c) != 0)
        {
            return *this;
        }

             int counter = 0;
        for (const auto &card : cards)
        {
            counter++;
        }
     
        if (counter < fiveCards)
        {
            throw invalid_argument("Not enough cards");
        }
     

        if (!board.is_research_station(city))
        {
   throw invalid_argument{"There is no research station in this city"};        }

       
        counter = fiveCards;
        City temp[fiveCards];
        for (auto &card : cards)
        {
            temp[counter--] = card;
         
            if (counter <0)
            {
                break;
            }
        }

        counter = 0;
        while(counter < fiveCards)
     
        {
            cards.erase(temp[counter++]);
            
        }
        board.markRecovery(c);
        meditions.insert(c);
        return *this;
    }
};