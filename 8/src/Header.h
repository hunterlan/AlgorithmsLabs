#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct University {
	string name;
	University *next;
};

struct Specialty {
	string name;
	Specialty *next;
	University *list;
};



void addSpeciality(Specialty *head, string name);
void addUniversity(Specialty *head, string name);
void printList(Specialty *head);
void removeList(Specialty *head);
void removeSublist(Specialty *p);
void removeSpecialty(Specialty *head);
void removeUniversity(Specialty *head);