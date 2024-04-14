#include "calculo.h"


double funcaoX(data_static_calcule_t *calcule_static, float ponto)
{
	int i, j;
    float resultado;
    resultado = 0;

    calcule_static->vet_multi = calcule_static->vet_multi_aux;

    for(i=0, j = calcule_static->grau; i<= calcule_static->grau; i++, j--, calcule_static->vet_multi++)
    {
        resultado += *(calcule_static->vet_multi)*pow(ponto, j);
    }

    calcule_static->vet_multi = calcule_static->vet_multi_aux;

    return resultado;
}

void calculaValorK(double a, double b, data_static_calcule_t *calcule_static)
{
    double fValorK;

    fValorK = (log10(b - a) - log10(calcule_static->precisao))/log10(2);

    calcule_static->iteracao = ceil(fValorK);
}


void zero_in_function(data_calculo_t *calculo, data_static_calcule_t *calcule_static)
{
    int i;
    double a_aux = 0, b_aux = 0, m_aux = 0;

    for(i = 0; i < calcule_static->iteracao; i++, calculo++)
    {
        a_aux = calculo->a;
        b_aux = calculo->b;
        calculo->m = (calculo->a + calculo->b)/2;
        calculo->fA = funcaoX(calcule_static, calculo->a);
        calculo->fB = funcaoX(calcule_static, calculo->b);

        calculo->fM = funcaoX(calcule_static, calculo->m);
        if(calculo->fA * calculo->fM > 0)
        {
            calculo->fAfM = '+';
            m_aux = calculo->m;
            calculo++;
            calculo->a = m_aux;
            calculo->b = b_aux;
            calculo--;
        }
        else
        {
            calculo->fAfM = '-';
        }
        if((calculo->fM * calculo->fB) > 0)
        {
            calculo->fMfB = '+';
            m_aux = calculo->m;
            calculo++;
            calculo->b = m_aux;
            calculo->a = a_aux;
            calculo--;
        }
        else
        {
            calculo->fMfB = '-';

        }
    }
}
