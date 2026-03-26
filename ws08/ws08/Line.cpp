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