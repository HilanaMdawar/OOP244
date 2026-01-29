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
*AI was used for minor clarification of syntax, logic understanding.
*

**************************************************************************************/

#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca {

    struct Samples {
        char* m_title{};
        int* m_data{};
        int   m_size{};
    };

    Samples* CreateSamples(const char* title);
    void add(Samples& S, const int data[], int size);
    void freemem(Samples*& S);

}

#endif
