#include "exibicao.h"
#include "calculo.h"


int main()
{
    data_calculo_t calculo;
    data_static_calcule_t calcule_static;


    print_informe_valor(&calculo, &calcule_static);

    print_function(&calculo, &calcule_static);

    print_result(&calculo, &calcule_static);



    zero_in_function(&calculo, &calcule_static);



    print_header();
    print_chart(&calculo, &calcule_static);

    return 0;
}

