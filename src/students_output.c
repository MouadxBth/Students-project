#include "students.h"

void     print_student_name(Student *student)
{
	printf("FIRST NAME:\t\t%s\n", student->first_name);
        printf("LAST NAME:\t\t%s\n\n", student->last_name);
}

void	print_student_average(Student *student)
{
	printf("FIRST NAME:\t\t%s\n", student->first_name);
        printf("LAST NAME:\t\t%s\n", student->last_name);
        printf("AVERAGE GRADE:\t\t%.2f\n\n", student->average);
}

void    print_student(Student *student)
{
        if (!student)
                return ;
        printf("ID:\t\t\t%d\n", student->id);
	printf("FIRST NAME:\t\t%s\n", student->first_name);
        printf("LAST NAME:\t\t%s\n", student->last_name);
        printf("AVERAGE GRADE:\t\t%.2f\n\n", student->average);
}

void    print_title(void)
{
        printf("░██████╗████████╗██╗░░░██╗██████╗░███████╗███╗░░██╗████████╗░██████╗\n");
        printf("██╔════╝╚══██╔══╝██║░░░██║██╔══██╗██╔════╝████╗░██║╚══██╔══╝██╔════╝\n");
        printf("╚█████╗░░░░██║░░░██║░░░██║██║░░██║█████╗░░██╔██╗██║░░░██║░░░╚█████╗░\n");
        printf("░╚═══██╗░░░██║░░░██║░░░██║██║░░██║██╔══╝░░██║╚████║░░░██║░░░░╚═══██╗\n");
        printf("██████╔╝░░░██║░░░╚██████╔╝██████╔╝███████╗██║░╚███║░░░██║░░░██████╔╝\n");
        printf("╚═════╝░░░░╚═╝░░░░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚══╝░░░╚═╝░░░╚═════╝░\n\n");
}

void    print_options(void)
{
        printf("1) Add a new Student.\n");
        printf("2) Show students.\n");
        printf("3) Show the average of each Student.\n");
        printf("4) Show a Student's informations.\n");
        printf("5) Sort Students.\n");
        printf("6) Exit.\n");
}