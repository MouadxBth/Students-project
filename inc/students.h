#ifndef STUDENTS_H
# define STUDENTS_H

# include <stdio.h>
# include <stdlib.h>

# ifdef _WIN32
#  include <Windows.h>
# else
#  include <unistd.h>
# endif

# ifndef MAX_STUDENTS
#  define MAX_STUDENTS 200
# endif

typedef struct s_student {

	int	id;
	char	*first_name;
	char	*last_name;
	int	modules;
	float	*grades;
	float	average;

} Student;

Student **get_students();

Student	*new_student(int id, int modules);

void	free_student(Student *student);

void	add_student(int *count, Student *student);

void	delete_student(int id);

int		find_student_index(int id);

Student *find_student(int id);

void	for_each_student(void (*f)(Student *));

Student	*input_student(void);

int		input_choice(int start, int end);

void	print_student(Student *student);

void	print_student_name(Student *student);

void	print_student_average(Student *student);

void	print_title(void);

void	print_options(void);

void	search_for_student(void);

void	merge_sort_students(int start, int end);

#endif
