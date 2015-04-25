#Author: Ling Pei Li
rsvp.out: rsvp.o student.o course.o vector.o 
	gcc -o rsvp2.out student.o rsvp.o course.o vector.o
rsvp.o: rsvp.c student.h course.h vector.h 
	gcc -Wall -g -c rsvp.c
student.o: student.c student.h course.h vector.h
	gcc -Wall -g -c student.c
course.o: course.c student.h course.h vector.h
	gcc -Wall -g -c course.c
vector.o: vector.c student.h course.h vector.h
	gcc -Wall -g -c vector.c

clean: 
	rm -f rsvp.o student.o course.o vector.o rsvp2.out
