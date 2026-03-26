#include "Shape.h"
using namespace std;

namespace seneca {

    ostream& operator<<(ostream& os, const Shape& S) {
        S.draw(os);
        return os;
    }

    istream& operator>>(istream& is, Shape& S) {
        S.getSpecs(is);
        return is;
    }

}