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
#include "Line.h"
#include <cstring>
using namespace std;

namespace seneca {

    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* lbl, int len) : LblShape(lbl) {
        m_length = len;
        if (label() && len < (int)strlen(label()))
            m_length = (int)strlen(label());
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && label()) {
            os << label() << endl;
            for (int i = 0; i < m_length; i++) os << "=";
        }
    }

}