#include "ListOfLists.h"

int main() {
	Specialty *head = new Specialty;
	head->next = NULL;

	addSpeciality(head, "Developer");
	addUniversity(head, "KHPI");
	addUniversity(head, "NURE");
	addUniversity(head, "Karazrina");

	addSpeciality(head, "Manager");
	addUniversity(head, "Karazina");
	addUniversity(head, "KHPI");

	printList(head);

	removeSpecialty(head);

	cout << " " << endl;
	printList(head);

	removeUniversity(head);

	cout << " " << endl;
	printList(head);

	removeList(head);

	return 0;
}
