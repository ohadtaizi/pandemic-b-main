#include"Medic.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;

namespace pandemic{
    
    Player& Medic::treat(City c){
        if (c == city && board[c] > 0)
        {
            board[c] = 0;
            return *this;
        }
        throw invalid_argument("illigel treat");
    }

    void Medic::flyall(City c){
        if (board.CureDiscoverd(c))
        {
            board[c] = 0;
        }
    }

};