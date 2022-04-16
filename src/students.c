#include "students.h"

Student **get_students(void)
{
	static Student **students;

	if (!students)
	{
		students = (Student **)malloc(sizeof(Student *) * (MAX_STUDENTS + 1));
		if (!students)
		{
			printf("Couldn't allocate memory for the main array!\n");
			return (NULL);
		}
	}

	return (students);
}

static void	handle_choice(int choice)
{
	static int count = 0;

	if (!get_students())
		return ;
	switch (choice)
	{
		case 1: 
			add_student(&count, input_student());
			break;
		case 2:
			if (!get_students()[0])
				printf("No students are registered yet!\n\n");
			else
				for_each_student(print_student_name);
			break;
		case 3:
			if (!get_students()[0])
				printf("No students are registered yet!\n\n");
			else
				for_each_student(print_student_average);
			break;
		case 4:
			search_for_student();
			break;
		case 5:
			if (!get_students()[0])
				printf("No students are registered yet!\n\n");
			else
			{
				merge_sort_students(0, count);
				printf("Sorted successfully!\n\n");
			}
			break;
	}
}

int	main(void)
{
	int	choice;

	do {
		system("@cls||clear");
		print_title();
		print_options();
		choice = input_choice(1, 6);
		handle_choice(choice);
		if (choice != 6)
			sleep(1);
	} while (choice != 6);
	for_each_student(free_student);
	free(get_students());
	return (0);
}
