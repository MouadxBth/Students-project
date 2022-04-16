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

static void merge(int start, int middle, int end) {
	Student **first, **second;
	int first_length, second_length;
	int index, second_index;

	first_length = middle - start + 1;
	second_length = end - middle;

	first = (Student **)malloc(sizeof(Student *) * first_length);
	second = (Student **)malloc(sizeof(Student *) * second_length);
	if (!first || !second)
	{
		printf("Error! couldnt allocate memory for sorting!");
		return ;
	}
	index = -1;
	while (++index < first_length)
		first[index] = get_students()[start + index];
	index = -1;
	while (++index < second_length)
		second[index] = get_students()[middle + 1 + index];
	
	index = 0;
	second_index = 0;
	while (index < first_length && second_index < second_length)
	{
		if (!first[index] || !second[second_index])
			break ;
		if (first[index]->average > second[second_index]->average)
		{
			get_students()[start] = first[index];
			index++;
		}
		else {
			get_students()[start] = second[second_index];
			second_index++;
		}
		start++;
	}

	while (index < first_length) {
		get_students()[start] = first[index];
		index++;
		start++;
	}

	while (second_index < second_length) {
		get_students()[start] = second[second_index];
		second_index++;
		start++;
	}
	free(first);
	free(second);
}

void merge_sort_students(int start, int end) {
	int middle;

	if (!get_students() || end <= start)
		return ;
	
	middle = start + (end - start) / 2;
	merge_sort_students(start, middle);
	merge_sort_students(middle + 1, end);
	merge(start, middle, end);
}