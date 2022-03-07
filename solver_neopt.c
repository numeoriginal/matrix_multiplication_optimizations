/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double * my_solver(int N, double * A, double * B) {
    int i, j, k;

    double * C;
    double * AB;
    double * ABBt;
    double * AtA;

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
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = i; k < N; k++)
                AB[i * N + j] += A[i * N + k] * B[k * N + j];

    // AB * Bt
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                ABBt[i * N + j] += AB[i * N + k] * B[j * N + k];

    // AtA
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k <= j; k++)
                AtA[i * N + j] += A[k * N + i] * A[k * N + j];

    // C = A x B x Bt + At x A
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            C[i * N + j] = ABBt[i * N + j] + AtA[i * N + j];

    free(AB);
    free(ABBt);
    free(AtA);

    return C;
}