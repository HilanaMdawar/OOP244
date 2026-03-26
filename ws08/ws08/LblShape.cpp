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