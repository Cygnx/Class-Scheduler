#ifndef COURSE_H
  #define COURSE_H
#define NUMBER_OF_SUBJECTS 4
#define NUMBER_OF_COURSE 6
#define SID_LENGTH 12
#define CRN_LENGTH 5
typedef struct
{
  int CRN;
  char subject[NUMBER_OF_SUBJECTS], course[NUMBER_OF_COURSE];
}course;
typedef struct
{
  char *first_name, *last_name, SID[SID_LENGTH];
  int CRN[CRN_LENGTH], count; 
}student;
void read_courses(char file_name[], course **my_courses, int *size,
  int *count);
void find_CRN(course **my_courses, student **students, int *count, 
  int *student_count);
void find_subject(course **my_courses, int *count);
void add_course(course **my_courses, student **students, int *count, 
  int *student_count);
void remove_course(course **my_courses, student **students, int *count, 
  int *student_count);
#endif
