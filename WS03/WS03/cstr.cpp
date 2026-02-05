/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Hilana Mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  : 3
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

#include "cstr.h"

namespace seneca {

    int strLen(const char* s) {
        int len = 0;
        if (s) {
            while (s[len]) len++;
        }
        return len;
    }

    void strCpy(char* des, const char* src) {
        if (des && src) {
            while (*src) {
                *des++ = *src++;
            }
            *des = '\0';
        }
        else if (des) {
            *des = '\0';
        }
    }

    void strcpy(char* des, const char* src, int len) {
        int i = 0;
        if (!des) return;

        if (!src || len <= 0) {
            des[0] = '\0';
            return;
        }

        for (; i < len && src[i]; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

}