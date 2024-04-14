/*
 *Kaique Vecchia Alves RA: 235446
 *Nathalia Atamanchuk RA: 235215
 *Anna Julia Andrade RA: -
 */

#include "exibicao.h"
#include "calculo.h"
#include "allocation.h"


int main()
{
    data_calculo_t *calculo = NULL;
    data_static_calcule_t calcule_static;



    print_informe_valor(calculo, &calcule_static);
    aloca_struct(&calculo, calcule_static.iteracao);

    calculo->a = calcule_static.a_aux;
    calculo->b = calcule_static.b_aux;

    print_function(calculo, &calcule_static);

    //print_result(calculo, &calcule_static);

    zero_in_function(calculo, &calcule_static);

    print_header();
    print_chart(calculo, &calcule_static);

    return 0;
}

