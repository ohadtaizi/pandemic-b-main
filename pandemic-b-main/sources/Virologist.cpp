#include"Virologist.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;


namespace pandemic {
    Player& Virologist::treat(City c) {
        if (board[c] == 0 || (this->city!=c && this->cards.count(c)==0)) {
         
            throw invalid_argument("illigel treat");
        }
        if (this->city!=c) {
            this->cards.erase(c);
        }
        if (board.CureDiscoverd(c)) {board[c] = 0;}
        else {board[c]--;}
        return *this;
    };
}