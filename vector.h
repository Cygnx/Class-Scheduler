#ifndef VECTOR_H
  #define VECTOR_H
void initialize(course **my_courses);
void initialize_students(student **my_students);
void resize(course **my_courses, int size);
void resize_students(student **my_resize, int student_size);
void deallocate(course *my_courses, student *students, int student_size);
#endif
