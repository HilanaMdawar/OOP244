/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Hilana Mdawar
* Student Email : hmdawar@myseneca.ca
* Workshop #  : 1
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
*
* I used AI to help me understand the workshop requirements and to guide me through
* the implementation steps, as I was struggling with the concepts.
* I also used AI to help identify and fix errors during debugging.
* All coding decisions and final implementations are my own.
**************************************************************************************/
#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstddef>
#include <cstdio>

namespace seneca {

    struct PhoneRec {
        char name[16];       
        char lastName[26];  
        long long phoneNumber{};
    };

    void read(char* name);

    void print(long long phoneNumber);

    void print(const PhoneRec& rec, std::size_t& row, const char* nameFilter = nullptr);

    bool read(PhoneRec& rec, std::FILE* fptr);

    void print(PhoneRec* recs[], std::size_t size, const char* nameFilter = nullptr);

    void setPointers(PhoneRec* recPtrs[], PhoneRec recs[], std::size_t size);

    void sort(PhoneRec* recPtrs[], std::size_t size, bool sortByLastName);
}

#endif 