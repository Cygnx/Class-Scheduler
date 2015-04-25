//Ling Pei Li
#include <stdio.h>
#include "course.h"
#include "student.h"
#include "rsvp.h"
#include "vector.h"

int main(int argc, char *argv[])
{
  int size, student_size, count, student_count;
  course *my_course;
  student *students;
  read_courses(argv[1], &my_course, &size, &count);
  read_students(argv[2], &students, &student_size, &student_count);
  display_info(&my_course, &students, &count, &student_count);
  deallocate(my_course, students, student_count);
  return 0;
}//main

int get_choice()
{
  int choice = 0;
  
  do
  {
    puts("\nRSVP Menu");
    puts("0. Done.");
    puts("1. Find by CRN.");
    puts("2. Find by subject.");
    puts("3. Add course.");
    puts("4. Remove course.");
    printf("Your choice (0 - 4): ");
    scanf("%d", &choice);
  
    if(choice > 4 || choice < 0)
      puts("Your choice is outside the acceptable range.  Please try again.");
  }
  while(choice > 4 || choice < 0);
  return choice;
}//get_choice

void display_info(course **my_courses, student **students, int *count, 
  int *student_count)
{ 
  int choice; 
  
  while(1)
  {
    choice = get_choice();
    
    if(choice == 0)
      break;
    
    switch(choice)
    {
      case 1: find_CRN(my_courses, students ,count, student_count);break;
      case 2: find_subject(my_courses, count);break;
      case 3: add_course(my_courses, students, count, student_count);break;
      case 4: remove_course(my_courses, students, count, student_count); break;
    }//switch
  } //while
}//display_info
