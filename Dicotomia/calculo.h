#ifndef CALCULO_H
#define CALCULO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct
{
	char fAfM;
	char fMfB;
	double a;
	double b;
	double m;
	double fA;
	double fB;
	double fM;
}data_calculo_t;

typedef struct
{
	uint8_t grau;
	uint32_t iteracao;
	double precisao;
	double a_aux;
	double b_aux;
	double *vet_multi;
	double *vet_multi_aux;
}data_static_calcule_t;


double funcaoX(data_static_calcule_t *calcule_static, float ponto);

void calculaValorK(double a, double b, data_static_calcule_t *calcule_static);

void zero_in_function(data_calculo_t *calculo, data_static_calcule_t *calcule_static);


#endif
