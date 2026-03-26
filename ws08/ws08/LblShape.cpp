#include "LblShape.h"
#include <cstring>
using namespace std;

namespace seneca {

    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::LblShape() {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* lbl) {
        m_label = nullptr;
        if (lbl) {
            m_label = new char[strlen(lbl) + 1];
            strcpy_s(m_label, strlen(lbl) + 1, lbl);
        }
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    void LblShape::getSpecs(istream& is) {
        char temp[81];
        is.getline(temp, 81, ',');

        // 🔥 FIX: remove leading space if exists
        int start = 0;
        while (temp[start] == ' ') start++;

        delete[] m_label;
        m_label = new char[strlen(temp + start) + 1];
        strcpy_s(m_label, strlen(temp + start) + 1, temp + start);
    }

}