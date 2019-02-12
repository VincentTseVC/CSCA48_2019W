#include<stdio.h>
#include<string.h>

#define MAX_NAME_SIZE 1024 // no need ;

typedef struct human_being {
	char first_name[MAX_NAME_SIZE];
	char last_name[MAX_NAME_SIZE];
	int age;
	struct human_being *father;
	struct human_being *next;
} Person;


void setAge(Person *person, int new_age) {
	person->age = new_age;
	// (*person).age = new_age; 
}

void setFirstName(Person *person, char *first_name) {
	strcpy(person->first_name, first_name); 
	// strcpy((*person).first_name, first_name);
}

void setLastName(Person *person, char *last_name) {
	strcpy(person->last_name, last_name); 
	// strcpy((*person).last_name, last_name);
}

void initPerson(Person *person, int age, char *first_name, 
				char *last_name, Person *father) {
	setAge(person, age);
	setFirstName(person, first_name);
	setLastName(person, last_name);
	person->father = father;
	// (*person).father = father;
}


void printPerson(Person person) {
	char *father = "Jesus";

	if (person.father != NULL)
		father = person.father->first_name;
		// father = (*person.father).first_name;

	printf("Hello, my name is %s %s and I am %d years old. My dad is %s\n", 
		    person.first_name, person.last_name, person.age, father);
}





int main() {
	// struct human_being vc;
	Person vc;
	initPerson(&vc, 18, "Vincent", "Tse", NULL);

	Person white;
	initPerson(&white, 3, "White", "Tse", &vc);

	Person beauty;
	initPerson(&beauty, 18, "B", "Tse", &vc);

	printPerson(vc);
	printPerson(white);
	printPerson(beauty);

	// white has finally grown up
	setAge(&white, 4);
	// beauty thinks that her name 'B' need to be changed
	setFirstName(&beauty, "BB"); // but still ugly :)

	printPerson(vc);
	printPerson(white);
	printPerson(beauty);

	// A list (linked) of Persons
	Person *head;

	head = &vc;
	head->next = &white;
	head->next->next = &beauty;

	printf("%s\n", head->first_name);
	printf("%s\n", vc.next->first_name);
	printf("%s\n", white.next->first_name);


}