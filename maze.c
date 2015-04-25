//Ling Pei Li
#include <stdio.h>
int find_path();
int main(int argc, char* argv[])
{
  FILE* my_file = fopen(argv[1], "r");
  char maze[8][9];
  int i;

  for(i = 0; i < 8; i++)
  {
    fscanf(my_file, "%s\n", maze[i]);
  }//for
  if(!find_path(maze, 7, 7))
    puts("No path was found");
  fclose(my_file);
  return 0;
}//main

int find_path(char maze[][9], int x, int y)
{
  if(x < 0 || x > 7 || y < 0 || y > 7 || maze[y][x] == 'X')
    return 0;
  maze[y][x] = 'X';
  if((find_path(maze, x - 1, y) || find_path(maze, x, y - 1)) || 
    find_path(maze, x + 1, y) || find_path(maze, x, y + 1) || 
      (y == 0 && x == 1))
  {
    printf("(%d, %d)\n", y, x);
    return 1;
  } //if
  return 0;
}//find_path
