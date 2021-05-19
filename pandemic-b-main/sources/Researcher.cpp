#include "Researcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
const int fiveCards = 5;

namespace pandemic
{
        Player &Researcher::discover_cure(Color c)
        {
                    int colors = 0;
                for (const auto &card :this-> cards)
                {
                        if (board.colorOfCity(card) == c)
                        {
                               colors++;
                        }
                        
                }
                if (meditions.count(c) != 0)
                {
                        return *this;
                }
                

        
                if (colors < fiveCards)
                {
                        throw invalid_argument("Not enough cards");
                }
                colors = 0;
                City temp[fiveCards];
                for (auto &card : cards)
                {
                        if (board.colorOfCity(card) == c)
                        {
                                temp[colors++] = card;
                              
                        }
                        if (colors >= fiveCards)
                        {
                                break;
                        }
                }
           
                board.markRecovery(c);
                meditions.insert(c);
                return *this;
        }
};