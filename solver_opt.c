/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double * my_solver(int N, double * A, double * B) {

    double * C;
    double * AB;
    double * ABBt;
    double * AtA;
    register int i = 0;
    register int j = 0;
    register int k = 0;

    C = calloc(N * N, sizeof( * C)); // final result
    if (C == NULL) {
        return NULL;
    }
    AB = calloc(N * N, sizeof( * C)); // A * B
    if (AB == NULL) {
        return NULL;
    }
    ABBt = calloc(N * N, sizeof( * C)); // A * B * Bt
    if (ABBt == NULL) {
        return NULL;
    }
    AtA = calloc(N * N, sizeof( * C)); // A * At
    if (AtA == NULL) {
        return NULL;
    }

    // A * B
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double sumAB = 0.0;
            for (k = i; k < N; k++)
                sumAB += A[i * N + k] * B[k * N + j];
            AB[i * N + j] = sumAB;
        }
    }
    // AB * Bt
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double sumABBt = 0.0;
            for (k = 0; k < N; k++)
                sumABBt += AB[i * N + k] * B[j * N + k];
            ABBt[i * N + j] = sumABBt;
        }
    }

    // AtA
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double sumAtA = 0.0;
            for (k = 0; k <= j; k++)
                sumAtA += A[k * N + i] * A[k * N + j];
            AtA[i * N + j] = sumAtA;
        }
    }

    // C = A x B x Bt + At x A
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            C[i * N + j] = ABBt[i * N + j] + AtA[i * N + j];

    free(AB);
    free(ABBt);
    free(AtA);

    return C;
}