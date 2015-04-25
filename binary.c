//Ling Pei Li
#include <stdio.h>
#include <string.h>
int display();
int main()
{
  char input[100];
  printf("Binary number: ");
  scanf("%s", input);  
  display(input, 0);
  return 0;
}//main

int display(char temp[], int n)
{
  char *ptr = strchr(temp, 'x');
  char temp_string1[100], temp_string2[100];
  if(n == 0 && ptr == NULL)
    puts(temp);
  
  if(ptr == NULL)
  return 0;

  strcpy(temp_string1, temp);
  strcpy(temp_string2, temp);
  temp_string1[ptr - temp] = '0';
  temp_string2[ptr - temp] = '1';
 
  if(strchr(ptr + 1, 'x') == NULL)
  {
  puts(temp_string1);
  puts(temp_string2);
  }//if
  display(temp_string1, n + 1);
  display(temp_string2, n + 1);
  return 1;
}//display
