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

Student	*new_student(int id, int modules);

void	free_student(Student *student);

Student	*input_student(void);

void	iterate_students(Student **array, void (*f)(Student *));

void	print_student(Student *student);

void	print_student_name(Student *student);

void	print_student_average(Student *student);

int	print_menu(void);

void	bubble_sort_students(Student **array);

#endif
