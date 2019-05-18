#include "Header.h";

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

	cout << "___________________________________" << endl;
	printList(head);

	removeUniversity(head);

	cout << "___________________________________" << endl;
	printList(head);

	removeList(head);

	return 0;
}

void addSpeciality(Specialty *head, string name) {
	Specialty *newElem = new Specialty;
	newElem->name = name;
	newElem->list = new University;
	newElem->list->next = NULL;


	Specialty *tmp = head;
	while (tmp->next != NULL) {
		tmp=tmp->next;
	}

	newElem->next = tmp->next;
	tmp->next = newElem;

}

void addUniversity(Specialty *head, string name){
	University *newElem = new University;
	newElem->name = name;
	newElem->next = NULL;
	Specialty *tmp = head;
	University *p;

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	p = tmp->list;

	while (p->next != NULL) {
		p = p->next;
	}

	if (tmp->list->name == "") {
		tmp->list = newElem;
	}
	else {
		p->next = newElem;
	}


}

void printList(Specialty *head){
	Specialty *tmp = head;
	tmp = tmp->next;
	University *univ;

	while (tmp != NULL) {
		cout << "Specialty: " << tmp->name<< endl;
		cout << "Universities: " << endl;
		univ = tmp->list;
		while (univ->next != NULL) {
			cout << univ->name << endl;
			univ = univ->next;
		}
		tmp = tmp->next;
	}

}

void removeList(Specialty *head) {
	Specialty *p = head;
	Specialty *tmp;

	tmp = p;
	p = p->next;
	delete tmp;

	while (p->next)
	{
		tmp = p;
		p = p->next;
		removeSublist(tmp);
		delete tmp;
	}
	p = p->next;
	delete[] p;
	head = NULL;
}

void removeSublist(Specialty *p) {
	if (p->list == NULL) {
		return;
	}
	University *p1 = p->list;
	University *tmp1;
	while (p1->next)
	{
		tmp1 = p1;
		p1 = p1->next;
		delete tmp1;
	}
	p1 = p1->next;
	delete p1;
}

void removeSpecialty(Specialty *head) {
	if (head->next == NULL) {
		cout << "List is empty";
		return;
	}

	Specialty *tmp = head, *tmp2 = head;
	tmp = tmp->next;

	while (tmp->next != NULL) {
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}

	tmp2->next = NULL;

	removeSublist(tmp);
	delete tmp;
}

void removeUniversity(Specialty *head) {
	if (head->next == NULL) {
		cout << "List is empty";
		return;
	}
	Specialty *tmp = head;


	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	if (tmp->list == NULL) {
		cout << "Sublist is empty" << endl;
		return;
	}

	University *p = tmp->list;
	University *p2 = tmp->list;
	if (p->next != NULL) {
		p = p->next;
	}

	while (p->next != NULL) {
		p = p->next;
		p2 = p2->next;
	}

	p2->next = NULL;
	delete p;
}
