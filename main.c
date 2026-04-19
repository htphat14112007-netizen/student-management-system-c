#include<stdio.h>
#include<string.h>
#include"student.h"
#include"file.h"

void menu(){
    printf("\n------MENU------");
    printf("\n0. Thoat Khoi Chuong Trinh!!!");
    printf("\n1. Nhap Danh Sach");
    printf("\n2. Hien Thi Danh Sach");
    printf("\n3. Them Sinh Vien");
    printf("\n4. Tim Sinh Vien");
    printf("\n5. Xoa Sinh Vien");
    printf("\n6. Luu File");
    printf("\n7. Doc File");
}

int main(){
    int choice;
    char ID[20];
    Student a[100];
    int n;

    do{

        menu();

        printf("\n\nNhap Lua Chon: ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 0:
                printf("Ban Da Thoat Khoi Chuong Trinh!");
                break;

            case 1: 
                input_Student(a, &n);
                break;

            case 2:
                print_Student(a, n);
                break;

            case 3:
                add_Student(a, &n);
                break;
            case 4:
                printf("Nhap ID Can Tim: ");
                scanf("%s", ID);
                getchar();
                
                int pos = find_Student(a, n, ID);

                if(pos != -1)
                    printf("Tim Thay: %s | %s | %.1f",a[pos].ID, a[pos].Name, a[pos].GPA);

                else 
                    printf("Khong Tim Thay!");
                break;

            case 5:
                printf("Nhap ID Sinh Vien Can Xoa: ");
                scanf("%s", ID);
                getchar();

                delete_Student(a, &n, ID);

                break;

            case 6:
                save_File(a, n);
                break;

            case 7:
                load_File(a, &n);
                break;

            default: 
                printf("Lua Chon Khong Dung!!\nHay Nhap Lai\n");
        }
    } while(choice != 0);

    return 0;

}