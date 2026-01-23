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
**
* I used AI to help me understand the workshop requirements and to guide me through
* the implementation steps, as I was struggling with the concepts.
* I also used AI to help identify and fix errors during debugging.
* All coding decisions and final implementations are my own.
**************************************************************************************/
#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

#include <cstddef>

namespace seneca {
	char* strcat(char* des, const char* src);

	char tolower(char ch);
	char* tolower(char* des, const char* src);
	char* tolower(char* str);

	int strcmp(const char* s1, const char* s2);
	int strcmp(const char* s1, const char* s2, std::size_t len);

	char* strcpy(char* des, const char* src);
	char* strcpy(char* des, const char* src, std::size_t len);
	char* strncpy(char* des, const char* src, std::size_t len);

	std::size_t strlen(const char* str);

	const char* strstr(const char* str, const char* toFind);

	bool isalpha(char ch);
	bool isspace(char ch);
}

#endif