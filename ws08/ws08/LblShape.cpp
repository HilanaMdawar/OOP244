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

**************************************************************************************/
#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;

namespace seneca {

    // Constructor
    LblShape::LblShape(const char* lbl) {
        if (lbl != nullptr && lbl[0] != '\0') {
            m_label = new char[strlen(lbl) + 1];
            strcpy(m_label, lbl);
        }
        else {
            m_label = nullptr;
        }
    }

    // Destructor
    LblShape::~LblShape() {
        delete[] m_label;
    }

    // Getter
    const char* LblShape::label() const {
        return m_label;
    }

    // getSpecs
    void LblShape::getSpecs(istream& is) {
        char temp[1001];

        is.get(temp, 1000, ',');
        is.ignore(1000, ',');

        delete[] m_label;
        m_label = nullptr;

        if (temp[0] != '\0') {
            m_label = new char[strlen(temp) + 1];
            strcpy(m_label, temp);
        }
    }

}