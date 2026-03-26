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