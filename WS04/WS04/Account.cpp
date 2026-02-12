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
*
* I have done all the coding by myself and only copied the code that my professor
* provided to complete my workshops and assignments.
* * I completed the implementation of the Account class and all operator overloads myself.
* I only used AI to help me understand and fix the alignment of the output formatting,
* as I was having difficulty adjusting the spacing and column widths correctly.
* All logic and functionality were written and understood by me.

**************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Account.h"

namespace seneca {

    void Account::setEmpty() {
        m_holderName[0] = '\0';
        m_number = -1;
        m_balance = 0.0;
    }

    void Account::setNew(const char* name) {
        std::strncpy(m_holderName, name, NameMaxLen);
        m_holderName[NameMaxLen] = '\0';
        m_number = 0;
        m_balance = 0.0;
    }

    bool Account::validName(const char* name) const {
        return name && name[0] != '\0';
    }

    bool Account::validNumber(int number) const {
        return number >= 10000 && number <= 99999;
    }

    Account::Account(const char* holderName) {
        if (validName(holderName)) setNew(holderName);
        else setEmpty();
    }

    Account::Account(const char* holderName, int number, double balance) {
        if (validName(holderName) && validNumber(number) && balance >= 0.0) {
            std::strncpy(m_holderName, holderName, NameMaxLen);
            m_holderName[NameMaxLen] = '\0';
            m_number = number;
            m_balance = balance;
        }
        else {
            setEmpty();
        }
    }

    std::ostream& Account::display() const {
        using namespace std;

        const int NAME_W = 31;   
        const int ACC_W = 5;    
        const int BAL_W = 12;   

        ios::fmtflags oldFlags = cout.flags();
        streamsize oldPrec = cout.precision();
        char oldFill = cout.fill();

        cout << ' ';
        if (m_number < 0) {
            cout << left << setw(NAME_W) << "Bad Account";
        }
        else {
            
            char name30[NameMaxLen + 1]{};
            std::strncpy(name30, m_holderName, NameMaxLen);
            name30[NameMaxLen] = '\0';
            cout << left << setw(NAME_W) << name30;
        }

        
        cout << "| ";
        if (m_number < 0) {
            cout << "-----";
        }
        else if (m_number == 0) {
            cout << " NEW ";
        }
        else {
            cout << right << setw(ACC_W) << m_number;
        }
        cout << ' ';

   
        cout << "| ";
        if (m_number < 0) {
            cout << right << setw(BAL_W) << "------------";
        }
        else {
            cout << right << setw(BAL_W) << fixed << setprecision(2) << m_balance;
        }
        cout << ' ';

        cout.fill(oldFill);
        cout.precision(oldPrec);
        cout.flags(oldFlags);

        return cout;
    }

    Account::operator bool() const {
        return validNumber(m_number) && m_balance >= 0.0 && m_holderName[0] != '\0';
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    Account::operator const char* () const {
        return m_holderName;
    }

    char& Account::operator[](int index) {
        int i = index % NameMaxLen;
        if (i < 0) i += NameMaxLen;
        return m_holderName[i];
    }

    const char Account::operator[](int index) const {
        int i = index % NameMaxLen;
        if (i < 0) i += NameMaxLen;
        return m_holderName[i];
    }

    Account& Account::operator=(int number) {
        if (m_number == 0) {
            if (validNumber(number)) m_number = number;
            else setEmpty();
        }
        return *this;
    }

    Account& Account::operator=(double balance) {
        if (balance >= 0.0) m_balance = balance;
        else setEmpty();
        return *this;
    }

    Account& Account::operator+=(double amount) {
        if (m_number != -1 && amount >= 0.0) m_balance += amount;
        return *this;
    }

    Account& Account::operator-=(double amount) {
        if (m_number != -1 && amount >= 0.0 && m_balance >= amount) m_balance -= amount;
        return *this;
    }

    Account& Account::operator<<(Account& other) {
        if (m_number != -1 && other.m_number != -1 && this != &other) {
            m_balance += other.m_balance;
            other.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& other) {
        if (m_number != -1 && other.m_number != -1 && this != &other) {
            other.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }

    bool Account::operator~() const {
        return m_number == 0;
    }

    Account& Account::operator++() {
        if (m_number != -1) m_balance += 1.0;
        return *this;
    }

    Account Account::operator++(int) {
        Account old = *this;
        if (m_number != -1) m_balance += 1.0;
        return old;
    }

    Account& Account::operator--() {
        if (m_number != -1 && m_balance > 0.0) m_balance -= 1.0;
        return *this;
    }

    Account Account::operator--(int) {
        Account old = *this;
        if (m_number != -1 && m_balance > 0.0) m_balance -= 1.0;
        return old;
    }

}
