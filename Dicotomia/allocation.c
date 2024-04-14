#include "allocation.h"

void aloca_vet(double **calculo, uint8_t tamanho)
{
    *calculo = (double*)malloc((tamanho + 1) * sizeof(double));
    if(*calculo == NULL)
    {
        printf("Erro ao alocar memoria para o vetor de fatores multiplicadores.\n");
        exit(1);
    }
    printf("alocou o vetor!\n");
}

void aloca_struct(data_calculo_t **calcule, uint32_t tamanho)
{
    *calcule = (data_calculo_t*)malloc((tamanho + 1) * sizeof(data_calculo_t));
    if(*calcule == NULL)
    {
        printf("Erro ao alocar memoria para a struct de calculo.\n");
        exit(1);
    }
    printf("alocou a struct!\n");
}

