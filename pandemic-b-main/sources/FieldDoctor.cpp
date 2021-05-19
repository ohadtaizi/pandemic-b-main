#include"FieldDoctor.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City c){
    if (c != city) {
        if(!board.connectedCity(city, c)){
            throw std::invalid_argument{"In order to do the treat the city you want to treat must be a neighbor of the city where you are."};
        }
    }
    if(board[c] == 0){
        throw runtime_error{" not possible to lower the disease level  the disease level is 0"};
    }
    if(board.CureDiscoverd(c)){
        board[c] = 0;
    }
    else{
        board[c]--;
    }
    return *this;
}
