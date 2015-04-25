//Ling Pei Li
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "student.h"
#include "vector.h"
#define BUFFER_LENGTH1 100
#define BUFFER_LENGTH2 10

void read_courses(char file_name[], course **my_courses, int *size, int *count)
{
  *count = 0;
  char temp_buffer[BUFFER_LENGTH1], temp_buffer2[BUFFER_LENGTH2];
  FILE *my_file = fopen(file_name, "r");

  if(my_file == NULL)
    exit(1);

  initialize(my_courses);
  *size = 100; 
  
  while(fgets(temp_buffer, 100, my_file) != NULL) 
  {
    strncpy(temp_buffer2, temp_buffer, 5);
   
    if(temp_buffer[0] == '5' || temp_buffer[0] == '6' || temp_buffer[0] == '7'
      || temp_buffer[0] == '8')
    {
      (*my_courses)[*count].CRN = atoi(strtok(temp_buffer, "\t^"));
      strcpy((*my_courses)[*count].subject, strtok(NULL, "\t^"));
      strcpy((*my_courses)[*count].course, strtok(NULL, "\t"));
      (*count)++; 
       
      if(*count == *size)
      { 
        resize(my_courses, *size);
        *size *= 2;
      }//if
    }//if
  }//while

  fclose(my_file);
}//read_courses

void find_CRN(course **my_courses, student **students, int *count, 
  int *student_count)
{
  int crn, i, j, h;
  printf("Please enter a CRN: ");
  scanf("%d", &crn);

  for(i = 0; i < *count; i++)
  {

    if((*my_courses)[i].CRN == crn)
    {
      printf("%s %s\n", (*my_courses)[i].subject, (*my_courses)[i].course);
      for(j = 0; j < *student_count; j++)
        for(h = 0 ; h < (*students)[j].count; h++ )
          if((*students)[j].CRN[h] == crn)
            printf("%s %s\n", (*students)[j].last_name, 
              (*students)[j].first_name);
      return;
    }//if
  }//for
  printf("CRN %d not found.\n", crn);
}//find_CRN

void find_subject(course **my_courses, int *count)
{
  char subject[10], temp;
  int i, subjects_found = 0;
  printf("Please enter a subject: ");
  scanf("%c", &temp);
  fgets(subject, 4, stdin); 

  for(i = 0; i < *count; i++)
  {
    if(strcmp((*my_courses)[i].subject, subject) == 0)
    {
      printf("%d %s %s\n", (*my_courses)[i].CRN, (*my_courses)[i].subject,
        (*my_courses)[i].course);
      subjects_found++;
    }//for
  }//for

  if(subjects_found == 0)
    printf("No courses were found for %s.\n", subject);
}//find_subject

void add_course(course **my_courses, student **students, int *count, 
  int *student_count)
{  
  int i, sid_found = -1, crn, crn_found = 0;
  char input[12], temp;
  puts("Add Course");
  printf("Please enter the SID of the student: ");
  scanf("%c", &temp);
  fgets(input, 12, stdin);
  for(i = 0; i < *student_count; i++)
  {
    if(strcmp((*students)[i].SID , input) == 0)
      sid_found = i; 
  }//forr
  if(sid_found == -1)
  {
    printf("A student with SID #%s was not found.\n", input);
    return;
  }//if
  if((*students)[sid_found].count >= 5)
  {
    puts("You are already taking 5 courses.");
    return;
  }//if
  printf("Please enter the CRN: ");
  scanf("%c", &temp);
  scanf("%d", &crn);

  for(i = 0; i < *count; i++)
    if((*my_courses)[i].CRN == crn)
      crn_found++;
  
  if(crn_found == 0) 
  {
    printf("There is no course with CRN #%d\n", crn);
    return;
  }//if
  for(i = 0; i < (*students)[sid_found].count; i++)
  {
    if((*students)[sid_found].CRN[i] == crn)
    {
      puts("You are already taking that course.");
      return;
    }//if
  }//for
  (*students)[sid_found].CRN[(*students)[sid_found].count] = crn;
  (*students)[sid_found].count++;
}//add_course


void remove_course(course **my_courses, student **students, int *count, 
  int *student_count)
{  
  int i, sid_found = -1, crn, crn_found = -1;
  char input[12], temp;
  puts("Remove Course");
  printf("Please enter the SID of the student: ");
  scanf("%c", &temp);
  fgets(input, 12, stdin);
  for(i = 0; i < *student_count; i++)
  {
    if(strcmp((*students)[i].SID , input) == 0)
      sid_found = i; 
  }//for
  if(sid_found == -1)
  {
    printf("A student with SID #%s was not found.\n", input);
    return;
  }//if
  printf("Current courses: ");
  for(i = 0; i < (*students)[sid_found].count; i++)
  {
    printf(" %d", (*students)[sid_found].CRN[i]);
  }//for
  printf("\n");
  printf("Please enter the CRN: ");
  scanf("%c", &temp);
  scanf("%d", &crn);

  for(i = 0; i < (*students)[sid_found].count; i++)
    if((*students)[sid_found].CRN[i] == crn)
      crn_found = i;

  if(crn_found == -1)
  {
    puts("You are not taking that course.");
    return;
  }//if 
  (*students)[sid_found].CRN[crn_found] = 
    (*students)[sid_found].CRN[(*students)[sid_found].count - 1];  
  (*students)[sid_found].count--; 
}//remove_course

  
