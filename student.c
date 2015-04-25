#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
#include "student.h"
#include "vector.h"

void read_students(char student_file_name[], student **students, 
  int *student_size, int *student_count)
{
  *student_count = 0;
  char temp_buffer[100], *name, *temp_ptr = NULL;
  int class_count;
  FILE *student_file = fopen(student_file_name, "r");

  if(student_file == NULL)
    exit(1);

  initialize_students(students); 
  *student_size = 10;
  
  while(fgets(temp_buffer, 100, student_file) != NULL)
  {
    class_count = 0;
    name = strtok(temp_buffer, ",");
    (*students)[*student_count].last_name = (char*)malloc(strlen(name) + 1);
    strcpy((*students)[*student_count].last_name, name);
    name = strtok(NULL, ",");
    (*students)[*student_count].first_name = (char*)malloc(strlen(name) + 1);
    strcpy((*students)[*student_count].first_name, name);
    strcpy((*students)[*student_count].SID, strtok(NULL, ","));
    temp_ptr = strtok(NULL, ", \n");
    while(temp_ptr != NULL)
    {
      (*students)[*student_count].CRN[class_count] = atoi(temp_ptr);
      temp_ptr = strtok(NULL, ", \n");
      class_count++;
    }
    (*students)[*student_count].count = class_count; 
    (*student_count)++;
    
    if(*student_count == *student_size)
    { 
      resize_students(students, *student_size);
      *student_size *= 2;
    }//if
  }
  fclose(student_file);
}//read_courses
