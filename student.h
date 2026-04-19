#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    char Name[100];
    char ID[100];
    float GPA;
} Student;

void input_Student(Student a[], int *n);
void print_Student(Student a[], int n);
void add_Student(Student a[], int *n);
int find_Student(Student a[], int n, char ID[]);
void delete_Student(Student a[], int *n, char ID[]);
#endif