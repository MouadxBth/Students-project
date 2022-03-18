#include "students.h"

static int	get_id(int *id, char *str, char *invalid, char *exist)
{
	do {
		printf("%s\n", str);
		scanf("%d%*c", id);
		if (*id < 0)
			printf("%s\n", invalid);
		
	} while (*id < 0);

    if (find_student(*id))
	{
        printf("%s\n", exist);
		return (0);
	}
	return (1);
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

	if (!get_id(&id, "Enter his/her id:", "Invalid id!", "Error! A student with that ID already exists!"))
		return (NULL);
	get_modules(&modules, "Enter his/her modules:", "Must have at least 1 module!");
	result = new_student(id, modules);
	get_string(result->first_name, "Enter his/her first name:");
	get_string(result->last_name, "Enter his/her last name:");
	get_grades("Enter his/her grades:", modules, result->grades);
	result->average = calculate_average(modules, result->grades);
	printf("Added a new Student successfully!\n");
    
	return (result);
}
