#include "students.h"

void	iterate_students(Student **array, void (*f)(Student *))
{
	int	index;

	index = -1;
	while (array[++index] && index < MAX_STUDENTS)
		f(array[index]);
}

Student	*find_student(Student **array, int id)
{
	int	index;

	index = -1;
	while (array[++index] && index < MAX_STUDENTS)
		if (array[index]->id == id)
			return (array[index]);
	return (NULL);
}

void	find(Student **array)
{
	int	id;
	Student	*result;

	do {
		printf("Enter student id:\n");
		scanf("%d%*c", &id);
		if (id < 0)
			printf("Invalid id!\n\n");
	} while (id < 0);
	result = find_student(array, id);
	if (result)
		print_student(result);
	else
		printf("Student not found!\n\n");
}

void	handle_choice(int choice, Student **students, int *index)
{
	switch (choice)
	{
		case 1: 
			students[++*index] = input_student();
			break;
		case 2:
			if (!students[0])
				printf("No students are registered yet!\n\n");
			else
				iterate_students(students, print_student_name);
			break;
		case 3:
			if (!students[0])
				printf("No students are registered yet!\n\n");
			else
				iterate_students(students, print_student_average);
			break;
		case 4:
			find(students);
			break;
		case 5:
			if (!students[0])
				printf("No students are registered yet!\n\n");
			else
			{
				bubble_sort_students(students);
				printf("Sorted successfully!\n\n");
			}
			break;
	}
}

int	main(void)
{
	Student	**students;
	int	index;
	int	choice;
	
	students = (Student **)malloc(sizeof(Student *) * (MAX_STUDENTS + 1));
	if (!students)
	{
		printf("Couldn't allocate memory for the main array!\n");
		return (1);
	}
	index = -1;
	do {
		system("@cls||clear");
		choice = print_menu();
		handle_choice(choice, students, &index);
		if (choice != 6)
			sleep(1);
	} while (choice != 6);
	iterate_students(students, free_student);
	free(students);
	return (0);
}
