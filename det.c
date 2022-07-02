// Copyright 2022 podsamar
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_dimens(int *cnt1, int *cnt2);
void input_matrix(double **matrix, int const *cnt1, int const *cnt2);
void sub_matr(int n, double M[n-1][n-1], double m[n][n], int I, int J);
double determinant(int n, double m[n][n]);
void exit_print_na();
void output(double **matrix, int *cnt);

int main() {
    int count1, count2;
    input_dimens(&count1, &count2);
    double ** matr = malloc(count1 * sizeof(double * ));
    input_matrix(matr, &count1, &count2);
    output(matr,  &count1);
    return 0;
}
void input_dimens(int *cnt1, int *cnt2) {
    int dim1, dim2;
    if (scanf("%d %d", &dim1, &dim2) == 2) {
        if (dim1 == dim2 && dim1 >0) {
            *cnt1 = dim1;
            *cnt2 = dim2;
        } else {
            exit_print_na();
        }
    } else {
        exit_print_na();
    }
}
void input_matrix(double **matrix, int const *cnt1, int const *cnt2) {
    double tm;
    for (int i = 0; i < *cnt1; i++) {
        matrix[i] = malloc(*cnt2 * sizeof(double));
    }
      for (int i = 0; i < *cnt1; i++) {
        for (int j = 0; j < *cnt2; j++) {
            if (scanf("%lf", &tm) == 1) {
                matrix[i][j] = tm;
            } else {
                exit_print_na();
            }
        }
      }
}

void exit_print_na() {
    printf("%s", "n/a");
    exit(1);
}

double determinant(int n, double m[n][n]) {
      double det = 0;
      if (n == 1) {
          return m[0][0];
        }
      if (n == 2) {
          det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
        } else {
          double M[n - 1][n - 1];
          for (int i = 0; i < n; i++) {
          sub_matr(n, M, m, 0, i);
          det += m[0][i] * pow(-1, i) * determinant(n - 1, M);
          }
        }
      return det;
    }

void sub_matr(int n, double M[n-1][n-1], double m[n][n], int I, int J) {
    int i, a = 0, b = 0;
    int j;
    for (i = 0; i < n; i++) {
        if (i != I) {
            for (j = 0; j < n; j++) {
                if (J != j) {
                    M[a][b] = m[i][j];
                    b++;
                }
            }
            a++;
            b = 0;
        }
    }
}

void output(double **matrix, int *cnt) {
    double m[*cnt][*cnt];
    for (int i = 0; i < *cnt; i++) {
      for (int j = 0; j < *cnt; j++) {
          m[i][j] = matrix[i][j];
      }
    }
    for (int i = 0; i < *cnt; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("%f", determinant(*cnt, m));
}
