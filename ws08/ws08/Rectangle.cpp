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
#include "Rectangle.h"
#include <cstring>
using namespace std;

namespace seneca {

    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* lbl, int w, int h) : LblShape(lbl) {
        m_width = w;
        m_height = h;

        if (m_height < 3) m_height = 3;
        if (m_width < (int)strlen(label()) + 2)
            m_width = (int)strlen(label()) + 2;
    }

    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }

    void Rectangle::draw(ostream& os) const {
        if (m_width > 0 && m_height > 0 && label()) {

            // top border
            os << "+";
            for (int i = 0; i < m_width - 2; i++) os << "-";
            os << "+" << endl;

            // label line (CORRECT — no forced space)
            os << "|";
            os << label();

            for (int i = 0; i < m_width - 2 - (int)strlen(label()); i++)
                os << " ";

            os << "|" << endl;

            // empty lines
            for (int i = 0; i < m_height - 3; i++) {
                os << "|";
                for (int j = 0; j < m_width - 2; j++) os << " ";
                os << "|" << endl;
            }

            // bottom border
            os << "+";
            for (int i = 0; i < m_width - 2; i++) os << "-";
            os << "+";
        }
    }

}