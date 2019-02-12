#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024


typedef struct student {
    char name[MAX_STR_LEN];
    char student_number[MAX_STR_LEN];
    struct student *next; 
} Student;


/* Create a group and initialize all its attributes */
Student *create_student(char name[MAX_STR_LEN], char student_number[MAX_STR_LEN]) {
    // create a new group in the HEAP
    Student *new_student = (Student *)calloc(1, sizeof(Student));

    // initialize the group
    strcpy(new_student->name, name);
    strcpy(new_student->student_number, student_number);
    new_student->next = NULL;
    return new_student;
}

Student *insert_to_head(Student *head, char name[MAX_STR_LEN], char student_number[MAX_STR_LEN]) {
    Student *new_student = create_student(name, student_number);
    new_student->next = head;
    head = new_student;
    return head;
}


void list_students(Student *head) {
    // create a pointer as the current node
    Student *curr = head;
    // loop through the list and print every node passed and move current forward
    while (curr != NULL) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}


Student *find_student(Student *head, const char student_number[]) {
    Student *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->student_number, student_number) == 0)
            return curr;
        curr = curr->next;

    }
    return NULL;
}

Student *add_to_tail(Student *head, char name[MAX_STR_LEN], char student_number[MAX_STR_LEN]) {
    // create new group and initialize with a copy of group_name
    Student *new_student = create_student(name, student_number);

    // insert to head if it is a empty list
    if (head == NULL) {
        head = new_student;
    // traverse the list until we find a same name or the end of the list
    } else {
        Student *curr = head;
        // loop through the list to check if theres duplicated name and move current toward the end
        while ((curr->next != NULL) && (strcmp(curr->student_number, student_number) != 0))
            curr = curr->next;

        // If no duplicated name is found, add the new node to the end of the list
        if (strcmp(curr->student_number, student_number) != 0) 
            curr->next = new_student;
        
    }
    return head;
}

Student *add_to_tail2(Student *head, char name[MAX_STR_LEN], char student_number[MAX_STR_LEN]) {
    // create new group and initialize with a copy of group_name
    Student *new_student = create_student(name, student_number);

    Student *curr = head;
    Student *prev = NULL;

    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        head = new_student;
    } else {
        prev->next = new_student;
    }

    return head;
}


Student *remove_head(Student *head) {
    Student *old_head = head;
    head = head->next;
    free(old_head);
    return head;
}


Student *remove_tail(Student *head) {
    if (head == NULL)
        return head;

    if (head->next == NULL) {
        head = NULL;
    } else {
        Student *curr = head;
        while (curr->next->next != NULL) 
            curr = curr->next;

        free(curr->next);
        curr->next = NULL;
    }
    return head;
}



int main() {
    /* Initialize the list head */
    Student *head = NULL;
    head = insert_to_head(head, "Vincent", "1001311128");
    head = insert_to_head(head, "White", "1002342343");
    head = add_to_tail(head, "Leon", "23333333333");
    head = add_to_tail(head, "B", "66666666666");
    head = remove_head(head);
    head = remove_tail(head);

    
    printf("\n\n\n");
    list_students(head);
    printf("\n\n\n");

    Student *sb = find_student(head, "66666666666");
    printf("%s\n", sb->name);

    return 0;
}