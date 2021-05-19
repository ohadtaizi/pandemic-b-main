#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <map>
#include <set>
#include <iostream>

using namespace std;



namespace pandemic
{


    void Board::remove_cures()
    {
        medicines.clear();
    }
    void Board::remove_stations(){
    research_Stations_lists.clear();
}

    int &Board::operator[](City c)
    {
        return cubes[c];
    }
    bool Board::is_clean()
    {
        for (auto& map : cubes)
        {
            if (map.second != 0)
            {
                return false;
            }
        }
        return true;
    }
    bool Board::connectedCity(City &c1, City &c2)
    {
       for(auto city : neighbor.at(c1)){
        if(city == c2){
            return true;
        }
     }
     return false;
    }
    void Board::build_research_station(City c)
    {
        research_Stations_lists.insert(c);
    }
    bool Board::is_research_station(City c)
    {
        return research_Stations_lists.count(c) != 0;
    }
    void Board::markRecovery(Color c)
    {
        medicines.insert(c);
    }
    bool Board::CureDiscoverd(City c)
    {
        return medicines.count(colorOfCity(c)) != 0;
    }
    Color Board::colorOfCity(City c)
    {
        return citycolor.at(c);
    }
   ostream &operator<<(std::ostream &sout, Board &b)
    {
 

 sout << "Cities Only  cubes or research station:" << endl;
    for (const auto& map :citycolor) {
       City city = map.first;
       sout << "city: " << city << endl;
       sout << "disease level: " << b.cubes.at(city) << endl;
       bool flag = true;
       if(b.research_Stations_lists.count(city) == 0){
           flag = false;
       }
       sout << "research station: " << flag << endl;
       sout << endl;
    }
    sout << "cures that discover :" << endl;
    if (b.bluecure) { sout << "Blue" << endl; }
    if (b.blackcure) { sout << "Black" << endl; }
    if (b.redcure) { sout << "Red" << endl; }
    if (b.yellowcure) { sout << "Yellow" << endl; }
    return sout;
    }
    bool Board::color_disease_cured(Color color) const {
    bool flag = false;
    if(color == Color::Black){
        flag = blackcure;
    }
    else if(color == Color::Blue){
        flag = bluecure;
    }
    else if(color == Color::Yellow){
        flag = yellowcure;
    }
    else if(color == Color::Red){
        flag = redcure;
    }
    return flag;
}

};
