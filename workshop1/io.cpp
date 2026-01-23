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
* in this section i used copilot to fix error and I asked a student named Sumeet Sandhu
* and asked the prof but the slution was not working so I used copilot to help me fix the issue.
**************************************************************************************/
#include <iostream>
#include <iomanip>
#include "io.h"
#include "cstr.h"

using namespace std;

namespace seneca {

    void read(char* name) {
        cout << "name>\n ";
        cin.getline(name, 26);
    }

    void print(long long phoneNumber) {
        long long area = phoneNumber / 10000000LL;              // first 3
        long long prefix = (phoneNumber / 10000LL) % 1000LL;    // next 3
        long long line = phoneNumber % 10000LL;                 // last 4

        cout << '(' << setw(3) << setfill('0') << area << ") "
            << setw(3) << setfill('0') << prefix << '-'
            << setw(4) << setfill('0') << line;

        cout << setfill(' '); // restore
    }

    void print(const PhoneRec& rec, size_t& row, const char* nameFilter) {
        bool match = true;

        if (nameFilter && nameFilter[0]) {
            match = (strstr(rec.name, nameFilter) != nullptr) ||
                (strstr(rec.lastName, nameFilter) != nullptr);
        }

        if (match) {
            cout << row << ": " << rec.name << ' ' << rec.lastName << ' ';
            print(rec.phoneNumber);
            cout << endl;
            row++;
        }
    }

    bool read(PhoneRec& rec, FILE* fptr) {
        
        return fscanf_s(fptr, "%15s%25s%lld", rec.name, (unsigned)_countof(rec.name), rec.lastName, (unsigned)_countof(rec.lastName), &rec.phoneNumber) == 3;
    }

    void print(PhoneRec* recs[], size_t size, const char* nameFilter) {
        size_t row = 1;
        for (size_t i = 0; i < size; i++) {
            print(*recs[i], row, nameFilter);
        }
    }

    void setPointers(PhoneRec* recPtrs[], PhoneRec recs[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            recPtrs[i] = &recs[i];
        }
    }

    void sort(PhoneRec* recPtrs[], size_t size, bool sortByLastName) {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = i + 1; j < size; j++) {
                int cmp = 0;
                if (sortByLastName) {
                    cmp = strcmp(recPtrs[i]->lastName, recPtrs[j]->lastName);
                }
                else {
                    cmp = strcmp(recPtrs[i]->name, recPtrs[j]->name);
                }

                if (cmp > 0) {
                    PhoneRec* tmp = recPtrs[i];
                    recPtrs[i] = recPtrs[j];
                    recPtrs[j] = tmp;
                }
            }
        }
    }

}