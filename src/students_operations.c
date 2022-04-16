#include "students.h"

void add_student(int *count, Student *student)
{
    if (!student)
    {
        printf("Error! Cannot insert a null student.\n");
        return ;
    }
    if (get_students()[*count])
    {
        printf("Error! Student already exist!\n");
        return ;
    }
    get_students()[*count] = student;
    ++*count;
}

void delete_student(int id)
{
    int index;

    index = find_student_index(id);
    if (index < 0)
    {
        printf("Error!");
        return ;
    }
    free_student(get_students()[index]);
    get_students()[index] = NULL;
}

int     find_student_index(int id)
{
    int index;

    index = -1;
    while (get_students()[++index] && index < MAX_STUDENTS)
        if (get_students()[index]->id == id)
            return (index);
    return (-1);
}

Student *find_student(int id)
{
    int index;

    index = find_student_index(id);
    if (index < 0)
        return (NULL);
    return (get_students()[index]);
}

void for_each_student(void (*f)(Student *))
{
	int	index;

	index = -1;
	while (get_students()[++index] && index < MAX_STUDENTS)
		f(get_students()[index]);
}