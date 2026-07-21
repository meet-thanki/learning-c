#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mini project: Student Database Management System
/*I have made this project similar to the first one to help me revise these fundamentals.*/

typedef struct{
    char name[20];
    int ID;
    float GPA;
} Student;

typedef struct{
    Student *student;
    int count;
    int capacity;
} StudentList;

void init_studentList(StudentList *sl1, int initial_capacity);
void add_student(StudentList *sl1, const char *name, int ID, float GPA);
void free_studentList(StudentList *sl1);

int main(){
    StudentList myList;

    init_studentList(&myList, 2);
    
    add_student(&myList, "ABC", 1234, 3.9);
    add_student(&myList, "DEF", 2345, 3.99);
    add_student(&myList, "DEF", 3456, 3.89);
    add_student(&myList, "DEF", 4567, 3.97);
    add_student(&myList, "GHI", 5678, 3.90);
    add_student(&myList, "JKL", 6789, 3.99);

    FILE *fptr;
    fptr = fopen("StudentDatabase.txt", "w");

    if(fptr == NULL){
        printf("File cannot be opened.");
        return 1;
    }

    fprintf(fptr, "Students saved: \n");
    for(int i = 0; i< myList.count; i++){
        fprintf(fptr, "\n%s | %d | %.2f", myList.student[i].name,  myList.student[i].ID,  myList.student[i].GPA);
    }
    
    free_studentList(&myList);
    fclose(fptr);
    return 0;
}

void init_studentList(StudentList *sl1, int initial_capacity){
    sl1->count = 0;
    sl1->capacity = initial_capacity;
    sl1->student = (Student*) calloc(initial_capacity, sizeof(Student));
}

void add_student(StudentList *sl1, const char *name, int ID, float GPA){
    if(sl1->count == sl1->capacity){
        int newCapacity = 2*sl1->capacity;
        Student *temp = (Student*) realloc(sl1->student, newCapacity*sizeof(Student));

        if(temp == NULL){
            printf("Memory Allocation Failed!");
            return; // immediately exits the function and hands control over to the function that called it.
        }

        sl1->student = temp;
        sl1->capacity = newCapacity;
        printf("Capacity resized to: %d.\n", sl1->capacity);
    }

    strcpy(sl1->student[sl1->count].name, name);
    sl1->student[sl1->count].ID = ID;
    sl1->student[sl1->count].GPA = GPA;

    sl1->count++;
}

void free_studentList(StudentList *sl1){
    free(sl1->student);
    sl1->capacity = 0;
    sl1->count = 0;
    sl1->student = NULL;
}