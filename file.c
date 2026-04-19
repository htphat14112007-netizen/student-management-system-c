#include<stdio.h>
#include"file.h"
#include"student.h"

void save_File(Student a[], int n){
    FILE *f = fopen("data.txt", "w");

    if(f == NULL){
        printf("Khong Mo Duoc File!!");
        return;
    }

    for(int i = 0; i < n; i++){
        fprintf(f, "%s | %s | %.1f\n",
            a[i].ID, a[i].Name, a[i].GPA);
    }

    fclose(f);

    printf("Luu File Thanh Cong!!\n");
}

void load_File(Student a[], int *n){
    FILE *f = fopen("data.txt", "r");

    if(f == NULL){
        printf("Chua Co File!!\n");
        return;
    }

    *n = 0; 
    
    while(fscanf(f, " %[^|] | %[^|] | %f",
    a[*n].ID, a[*n].Name, &a[*n].GPA) != EOF){
        
        (*n)++;

    }

    fclose(f);
    
    printf("Tai File Thanh Cong!!!\n");
}
