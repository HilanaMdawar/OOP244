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

#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

namespace seneca {
    int strLen(const char* s);
    void strCpy(char* des, const char* src);
    void strcpy(char* des, const char* src, int len);
}

#endif