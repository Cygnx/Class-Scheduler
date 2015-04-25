//Ling Pei Li
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "vector.h"

void initialize(course **my_courses)
{
  *my_courses = (course*)malloc(100 * sizeof(course));
}//initialize

void initialize_students(student **my_students)
{
  *my_students = (student*)malloc(10 * sizeof(student));
}//initialize_students

void resize(course **my_courses, int size)
{
  int i;
  course *new_courses = (course*)malloc(2 * size * sizeof(course));

  for(i = 0 ; i < size; i++)
  {
    new_courses[i].CRN = (*my_courses)[i].CRN; 
    strcpy(new_courses[i].subject, (*my_courses)[i].subject);
    strcpy(new_courses[i].course, (*my_courses)[i].course);
  }//for

  free(*my_courses);
  *my_courses = new_courses; 
}//resize

void resize_students(student **students, int size)
{
  int i;
  student *new_students = (student*)malloc(2 * size * sizeof(student));
  for(i = 0 ; i < size; i++)
    new_students[i] = (*students)[i];
  for(i = size; i < 2 * size; i++)
    new_students[i].count = 0;
  free(*students);
  *students = new_students;
}//resize

void deallocate(course *my_courses, student *students, int student_size)
{
  int i;
  free(my_courses);
  for(i = 0; i < student_size; i++)
  {
    free(students[i].last_name);
    free(students[i].first_name);
  }
  free(students);
}//deallocate
