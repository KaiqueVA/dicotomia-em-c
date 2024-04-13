#include "exibicao.h"
#include "allocation.h"

void print_header(void)
{
	printf("I |  a\t|  b\t|  m\t|  f(a)\t|  f(b)\t|  f(m)\t| fa*fm\t| fm*fb\t|\n");
    printf("--+-----+-------+-------+-------+-------+-------+-------+-------+\n");
}

void print_chart(data_calculo_t *data, data_static_calcule_t *data_static)
{
	int i;
	for(i = 0; i < data_static->iteracao; i++, data++)
	{
		printf("%i |%.2lf|%.2lf\t|%.2lf\t|%.2lf\t|%.2lf\t|%.2lf\t|%.2c\t|%c\t|\n", data_static->iteracao, data->a, data->b, data->m, data->fA, data->fB, data->fM, data->fAfM, data->fMfB);
	}
}

void print_informe_valor(data_calculo_t *data, data_static_calcule_t *data_static)
{
	int i;
	uint32_t k_aux;
	double a_aux, b_aux;

	printf("Informe o grau da funcao (2 a 6): ");
	scanf("%d", &data_static->grau);

	aloca_vet(&data_static->vet_multi, data_static->grau);



	data_static->vet_multi_aux = data_static->vet_multi;

	for(i=(data_static->grau); i>=0; i--, data_static->vet_multi++)
	{
		printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+((data_static->grau)-i));
		scanf("%lf", data_static->vet_multi);
	}

	data_static->vet_multi = data_static->vet_multi_aux;

	printf("Informe o valor de a: ");
	scanf("%lf", &a_aux);
	printf("Informe o valor de b: ");
	scanf("%lf", &b_aux);

	printf("Informe o valor da precisao desejada: ");
	scanf("%lf", &data_static->precisao);

	calculaValorK(a_aux, b_aux, data_static);

	aloca_struct(&data, data_static->iteracao);

	data->a = a_aux;
	data->b = b_aux;
}

void print_function(data_calculo_t *data, data_static_calcule_t *data_static)
{
	int i;
	for(i = data_static->grau; i >= 0; i--, data_static->vet_multi++)
	{
		if(i==0)
			printf("%.2lf = 0", *(data_static->vet_multi));
		else
			printf("%.2lf*x^%i + ", *(data_static->vet_multi), i);
	}
	data_static->vet_multi = data_static->vet_multi_aux;
	printf("\n\n");
}

void print_result(data_calculo_t *data, data_static_calcule_t *data_static)
{
	printf("Resultado: %lf %lf %lf\n\n", funcaoX(data_static, 0), funcaoX(data_static, 1), funcaoX(data_static, 2));
}

