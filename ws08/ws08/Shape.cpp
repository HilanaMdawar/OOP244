/*************************************************************************************
* OOP244 - 2261
*
* Student Name :hilana mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  :8
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
**************************************************************************************/
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