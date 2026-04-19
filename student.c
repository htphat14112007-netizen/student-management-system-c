#include<stdio.h>
#include<string.h>
#include"student.h"

void input_Student(Student a[], int *n){
    printf("Nhap So Luong Sinh Vien: ");
    scanf("%d",n);
    getchar();

    for(int i = 0; i < *n; i++){
        printf("\nNhap Ho Ten Sinh Vien thu %d: ",i + 1);
        fgets(a[i].Name, sizeof(a[i].Name), stdin);
        a[i].Name[strcspn(a[i].Name, "\n")] = '\0';

        printf("Nhap ID: ");
        fgets(a[i].ID, sizeof(a[i].ID), stdin);
        a[i].ID[strcspn(a[i].ID, "\n")] = '\0';

        printf("Nhap GPA: ");
        scanf("%f",&a[i].GPA);
        getchar();
    }
}

void print_Student(Student a[], int n){
    printf("Danh Sach Sinh Vien\n");
    for(int i = 0; i < n; i++){
        printf("%d. %s | %s | %.1f\n",i + 1, a[i].ID, a[i].Name, a[i].GPA);
    }
}

void add_Student(Student a[], int *n){
    printf("Nhap Sinh Vien Can Them: ");

    printf("\nNhap Ho Ten: ");
    fgets(a[*n].Name, sizeof(a[*n].Name), stdin);
    a[*n].Name[strcspn(a[*n].Name, "\n")] = '\0';

    printf("Nhap ID: ");
    fgets(a[*n].ID, sizeof(a[*n].ID), stdin);
    a[*n].ID[strcspn(a[*n].ID, "\n")] = '\0';

    printf("Nhap GPA: ");
    scanf("%f",&a[*n].GPA);
    getchar();

    (*n)++;
}

int find_Student(Student a[], int n, char ID[]){
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].ID, ID) == 0) return i;
    }
    return -1;
}

void delete_Student(Student a[], int *n, char ID[]){
    int pos = find_Student(a, *n, ID);
    
    if(pos == -1){
        printf("KHONG TIM THAY!\n");
        return;
    }

    for(int i = pos; i < *n - 1; i++){
        a[i] = a[i + 1];
    }
    (*n)--;

    printf("Da Xoa!");
}

