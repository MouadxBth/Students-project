#include "students.h"

void     print_student_name(Student *student)
{
        printf("FIRST NAME:\t\t%-10s\n", student->first_name);
        printf("LAST NAME:\t\t%-10s\n", student->last_name);
}

void	print_student_average(Student *student)
{
	print_student_name(student);
        printf("AVERAGE GRADE:\t%10.2f\n", student->average);
}

void    print_student(Student *student)
{
        if (!student)
                return ;
        printf("ID:\t\t%10d\n", student->id);
	print_student_average(student);
}

int     print_menu(void)
{
        int     choice;

        do {
                printf("1) Add a new Student.\n");
                printf("2) Show students.\n");
                printf("3) Show the average of each Student.\n");
                printf("4) Show a Student's informations.\n");
                printf("5) Sort Students.\n");
                printf("6) Exit.\n");
                scanf("%d", &choice);
                if (choice < 1 || choice > 6)
                        printf("Invalid choice!\n");
        } while (choice < 1 || choice > 6);
        return (choice);
}
