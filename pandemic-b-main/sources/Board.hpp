#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>
using namespace std;

namespace pandemic {

    class Board {
        private:
        map<City, int> cubes;
         set<Color> medicines;
        set<City> research_Stations_lists;
  
      bool bluecure;
        bool redcure;
        bool blackcure;
        bool yellowcure;
        public:
            Board() {}
                ~Board() { }
            void remove_cures();
             void remove_stations();
                void build_research_station(City c);
            void markRecovery(Color c);
            int& operator[](City c);
            bool is_clean();
            bool connectedCity(City& c1, City& c2);
            bool is_research_station(City c);
              bool CureDiscoverd(City c);
             bool color_disease_cured(Color color) const;
            Color colorOfCity(City c);
          
            friend ostream& operator<<(std::ostream& sout, Board& b);
    };



}