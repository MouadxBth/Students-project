#include "students.h"

Student *new_student(int id, int modules)
{
        Student *result = (Student *)malloc(sizeof(Student));
        if (!result)
                return (NULL);
        result->id = id;
        result->modules = modules;
        result->first_name = malloc(0);
        result->last_name = malloc(0);
        result->grades = (float *)malloc(sizeof(float) * modules);
	result->average = 0.0;
        return (result);
}

void    free_student(Student *student)
{
        if (!student)
                return ;
        free(student->first_name);
        free(student->last_name);
        free(student->grades);
        free(student);
}

static void	get_id(int *id, char *str, char *invalid)
{
	do {
		printf("%s\n", str);
		scanf("%d%*c", id);
		if (*id < 0)
			printf("%s\n", invalid);
	} while (*id < 0);
}

static void	get_modules(int *modules, char *str, char *invalid)
{
	do {
		printf("%s\n", str);
		scanf("%d%*c", modules);
		if (*modules <= 0)
			printf("%s\n", invalid);
	} while (*modules <= 0);
}

static void	get_string(char *result, char *str)
{
	printf("%s\n", str);
	scanf("%s%*c", result);
}

static void	get_grades(char *str, int modules, float *result)
{
	int	index;
	float	temp;

	index = -1;
	printf("%s\n", str);
	while (++index < modules)
	{
		do {
			printf("Module %i: ", index + 1);
			scanf("%f", &temp);
			if (temp < 0.0)
				printf("Invalid grade!\n");
		} while (temp < 0.0);
		result[index] = temp;
	}
}

static float	calculate_average(int modules, float *grades)
{
	float	result;
	int	index;

	result = 0.0;
	index = -1;
	while (++index < modules)
		result += grades[index];
	return (result /= modules);
}

Student *input_student(void)
{
        int     id;
        int     modules;
        Student *result;

	get_id(&id, "Enter his/her id:", "Invalid id!");
	get_modules(&modules, "Enter his/her modules:", "Must have at least 1 module!");
	result = new_student(id, modules);
	get_string(result->first_name, "Enter his/her first name:");
	get_string(result->last_name, "Enter his/her last name:");
	get_grades("Enter his/her grades:", modules, result->grades);
	result->average = calculate_average(modules, result->grades);
	printf("Added a new Student successfully!\n");
        return (result);
}

void swap(Student **first, Student **second)
{
    Student *temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort_students(Student **array)
{
   int	index;
   int	second_index;

   for (index = 0; index < MAX_STUDENTS - 1 && array[index] != NULL; index++)
       for (second_index = 0; second_index < MAX_STUDENTS - index - 1 && array[second_index] != NULL; second_index++)
           if (array[second_index]->average > array[second_index + 1]->average)
              swap(&array[second_index], &array[second_index + 1]);
}
