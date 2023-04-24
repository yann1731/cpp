#include "Data.hpp"

Data::Data():posx(12.5), posy(20.5), dirx(1), diry(0), hp(100), mp(0) {

}

Data::~Data() {

}

std::ostream& operator<<(std::ostream& out, const Data& rhs) {
    out << rhs.dirx << " " << rhs.diry << " " << rhs.posx << " " << rhs.posy << " " << rhs.hp \
    << " " << rhs.mp;
    return out;
}