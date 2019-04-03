#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include "stopper.h"

int main() {
    stopper st;
    startS(&st);
    #define M 4056
    #define N 1000000

    int randomNumbers[M];
    int in, im;

    im = 0;

    for (in = 0; in < N && im < M; ++in) {
        int rn = N - in;
        int rm = M - im;
        if (rand() % rn < rm)
            randomNumbers[im++] = in + 1;
    }

    assert(im == M);

//    for (int i = 0; i<M; i++) {
//        printf("%d\n",randomNumbers[i]);
//    }
//
//    printf("szamharmasok \n");


    int harmasok = 0;
    int hasznosharmasok = 0;
    int i,j,k;
    #pragma omp parallel num_threads(2)
    {
//        #pragma omp for lastprivate(i)
        for (i = 0; i < M; i++) {
//            #pragma omp for lastprivate(j)
            for (j = i + 1; j < M; j++) {
                #pragma omp for lastprivate(k)
                for (k = j + 1; k < M; k++) {
                    int a = randomNumbers[i];
                    int b = randomNumbers[j];
                    int c = randomNumbers[k];

                    if ((a + b > c) && (a + c > b) && (b + c > a)) {
//                        printf(" - %d, %d, %d   harmoszog lehet\n", a, b, c);

                        hasznosharmasok++;
                    }
                    harmasok++;
                }
            }
        }
    }
    printf("harmasok: %d \n",harmasok);
    printf("hasznosharmasok: %d\n",hasznosharmasok);

    stopS(&st);
    tprintf(&st,"\n");

    return 0;
}