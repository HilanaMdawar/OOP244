/*************************************************************************************
* OOP244 - 2261
*
* Student Name : Hilana Mdawar
* Student Email : hdawar@myseneca.ca
* Workshop #  :
* Course/Section: OOP244/NRA
*
* I declare that this assignment is my own work in accordance with the Seneca Academic
* Policy. No part of this assignment has been copied manually or electronically from/to
* any other source (including web sites) or distributed to other students.

**************************************************************************************/

#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include <iostream>

namespace seneca {

    const int NameMaxLen = 30;

    class Account {
        char m_holderName[NameMaxLen + 1];
        int m_number;
        double m_balance;

        void setEmpty();
        void setNew(const char* name);
        bool validName(const char* name) const;
        bool validNumber(int number) const;

    public:
      
        Account(const char* holderName = nullptr);
        Account(const char* holderName, int number, double balance);

       
        std::ostream& display() const;

        
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;

       
        char& operator[](int index);
        const char operator[](int index) const;

  
        Account& operator=(int number);
        Account& operator=(double balance);

       
        Account& operator+=(double amount);
        Account& operator-=(double amount);
        Account& operator<<(Account& other);
        Account& operator>>(Account& other);

       
        bool operator~() const;
        Account& operator++();      
        Account operator++(int);    
        Account& operator--();      
        Account operator--(int);    //
    };

}

#endif
