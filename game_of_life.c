#include <stdio.h>


#define HEIGHT 25
#define WIDTH 80

/* Используется для отображения сетки или рабочей области
и первоначальной установки всех элементов каждого поколения равными нулю. */
void clearscreen(char tableA[HEIGHT][WIDTH], char tableB[HEIGHT][WIDTH]) {
    int height, width;
    for (height=0; height<HEIGHT; height++) {
        for (width=0; width<WIDTH; width++) {
            tableA[height][width]=0;
            tableB[height][width]=0;
        }
    }
    for (height=0; height<HEIGHT; height++) {
        for (width=0; width<WIDTH; width++)
            printf("-");
        printf("\n");
    }
}
 
/* Используется для определения номера живых организмов и их координат */
void takeuser(char tableA[HEIGHT][WIDTH]) {
    int n, i;
    int height = 0, width = 0;
    printf("Введите количество живых организмов в начальном поколении:");
    scanf("%d",&n);
    for( i=0; i<n; i++) {
        printf("Введите координату (x y), в которой будет жить %d организм", i+1);
        scanf("%d", &height);
        scanf("%d", &width);
        if (height>=HEIGHT || width>=WIDTH) {
            printf("Неверные координаты\n");
        } else {
            tableA[height][width]=1;
        }
    }
}
  
/* Используется для отображения сетки */
void display(char tableA[HEIGHT][WIDTH]) {
    int height, width;
    for (height=0; height<HEIGHT; height++) {
        for(width=0; width<WIDTH; width++) {
            if(tableA[height][width]==1) {
                printf("$");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

/* Используется для вычисления количества живых соседей */
void calculate(char tableA[HEIGHT][WIDTH], char tableB[HEIGHT][WIDTH]) {
    int height, width;
    for (height=0; height<HEIGHT; height++)
        for(width=0; width<WIDTH; width++) {
            int neighbor=0;
            if (height==0 || width==0 || height==height-1 || width==width-1) {
                tableA[height][width]=0;
            } else {
                if (tableA[height - 1][width - 1] == 1) neighbor++;
            }
            if (tableA[height - 1][width] == 1) neighbor++;
            if (tableA[height - 1][width + 1] == 1) neighbor++;
            if (tableA[height][width - 1] == 1) neighbor++;
            if (tableA[height][width + 1] == 1) neighbor++;
            if (tableA[height + 1][width - 1] == 1) neighbor++;
            if (tableA[height + 1][width] == 1) neighbor++;
            if (tableA[height + 1][width + 1] == 1) neighbor++;
            if (tableA[height][width] == 1 && neighbor < 2) {
                tableB[height][width] = 0;
            } else if (tableA[height][width] == 1 && neighbor > 3) {
                tableB[height][width] = 0;
            } else if (tableA[height][width] == 1 && (neighbor == 2 || neighbor == 3)) {
                tableB[height][width] = 1;
            } else if (tableA[height][width] == 0 && neighbor == 3) {
                tableB[height][width] = 1;
            }
        }
}
  
/* Используется для замены текущего и следующего поколения */
void swap(char tableA[HEIGHT][WIDTH],char tableB[HEIGHT][WIDTH]) {
    int c, height, width;
    for (height=0; height<HEIGHT; height++)
        for (width=0; width<WIDTH; width++) {
            c = tableA[height][width];
            tableA[height][width]=tableB[height][width];
            tableB[height][width]=tableA[height][width];
        }
}


int main() {
   char tableA[HEIGHT][WIDTH];
   char tableB[HEIGHT][WIDTH];
   int end;
   clearscreen(tableA, tableB);
   takeuser(tableA);
   printf("First Generation\n");
   display(tableA);
   end=1;

   while (end!=0) {
        calculate(tableA,tableB);
        swap(tableA,tableB);
        printf("Следующее поколение\n");
        display(tableA);
        printf("Введите 0, чтобы выйти\nНажмите 1, чтобы продолжить ");
        scanf("%d",&end);
    }
    return 0;
    getch();
}

