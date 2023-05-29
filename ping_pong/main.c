#include <stdio.h>
#include <math.h>

int main()
{
  // Обозначения границ
  int p1x = 12, p1y = 1, p2x = 12, p2y = 78, bolx = 12, boly = 39, movex = 1, movey = 1;
  int count_left = 0, count_right = 0;

  while (1)
  {
    // Поведение мяча
    bolx += movex;
    boly += movey;
    // Условие касания ракетки слева
    if (bolx == 23 || bolx == 2)
      movex = movex * -1;
    // Условия касания ракетки правой
    if (boly == 78)
    {
      bolx = 12;
      boly = 39;
      movey = movey * -1;
    }
    // Условия касания ракетки левой
    if (boly == 1)
    {
      bolx = 12;
      boly = 39;
      movey = movey * -1;
    }
    if ((boly == 3) && (bolx == p1x || bolx == p1x + 1 || bolx == p1x + 2))
      movey = movey * -1;
    if ((boly == 77) && (bolx == p2x || bolx == p2x + 1 || bolx == p2x + 2))
      movey = movey * -1;
    // Функция счетчика
    if (boly == 77)
      count_left++;
    if (boly == 2)
      count_right++;
    // Создание границ поля
    for (int i = 0; i < 25; i++)
    {
      for (int j = 0; j < 80; j++)
      {
        if (i == 0 || i == 24 || j == 0 || j == 79)
        {
          printf("#");
        }
        else if (j == 40 && boly != 40)
        {
          printf("|");
        }
        else if ((i == p1x && j == p1y) || (i == p1x + 1 && j == p1y) || (i == p1x + 2 && j == p1y))
        {
          printf("]");
        }
        else if ((i == p2x && j == p2y) || (i == p2x + 1 && j == p2y) || (i == p2x + 2 && j == p2y))
        {
          printf("[");
        }
        else if (i == bolx && j == boly)
        {
          printf("o");
        }
        else
        {
          printf(" ");
        }
      }
      printf("\n");
    }
    if (count_left == 21 || count_right == 21)
    {
      if (count_left == 21)
        printf("1st player won!!!\n");
      if (count_right == 21)
        printf("2ed player won!!!\n");
      break;
    }
    else
    {
      printf("%d:%d\n", count_left, count_right);
    }
    char key;
    key = getchar();
    // Условия нажатия кнопок
    if ((key == 'a') && (p1x != 1))
      p1x--;
    if ((key == 'z') && (p1x != 21))
      p1x++;
    if ((key == 'k') && (p2x != 1))
      p2x--;
    if ((key == 'm') && (p2x != 21))
      p2x++;
    printf("\033c");
  }
  return 0;
}