/*************************************************************************************
* OOP244 - 2261
*
* Student Name :Hilana Mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  : w 02
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
* AI was used for minor clarification of syntax, logic understanding.
**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "dma.h"
#include "cstr.h"

namespace seneca {

    Samples* CreateSamples(const char* title) {
        Samples* s = new Samples;
        s->m_size = 0;
        s->m_data = nullptr;

        int len = strLen(title);
        s->m_title = new char[len + 1];
        strCpy(s->m_title, title);

        return s;
    }

    void add(Samples& S, const int data[], int size) {
        if (size <= 0) return;

        int* temp = new int[S.m_size + size];

        // copy old
        for (int i = 0; i < S.m_size; i++) {
            temp[i] = S.m_data[i];
        }

        // copy new chunk
        for (int i = 0; i < size; i++) {
            temp[S.m_size + i] = data[i];
        }

        delete[] S.m_data;
        S.m_data = temp;
        S.m_size += size;
    }

    void freemem(Samples*& S) {
        if (S) {
            delete[] S->m_title;
            delete[] S->m_data;
            delete S;
            S = nullptr;
        }
    }

}
