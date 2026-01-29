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

#include "sensorAnalysis.h"

namespace seneca {

    double averageReading(const int data[], int size) {
        double avg = 0.0;
        if (data && size > 0) {
            long long sum = 0;
            for (int i = 0; i < size; i++) sum += data[i];
            avg = (double)sum / size;
        }
        return avg;
    }

    int countSpikes(const int data[], int size) {
        int spikes = 0;
        if (data && size > 0) {
            for (int i = 0; i < size; i++) {
                if (data[i] > 200) spikes++;   // <-- THIS is the expected definition
            }
        }
        return spikes;
    }

    int maxDrop(const int data[], int size) {
        int maxD = 0;
        if (data && size > 1) {
            for (int i = 1; i < size; i++) {
                int drop = data[i - 1] - data[i];
                if (drop > maxD) maxD = drop;
            }
        }
        return maxD;
    }

    int countInRange(const int data[], int size, int min, int max) {
        int cnt = 0;
        if (data && size > 0) {
            for (int i = 0; i < size; i++) {
                if (data[i] >= min && data[i] <= max) cnt++;
            }
        }
        return cnt;
    }

}
