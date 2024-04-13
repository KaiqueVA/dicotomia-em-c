#ifndef EXIBICAO_H
#define EXIBICAO_H

#include "calculo.h"


void print_header(void);

void print_chart(data_calculo_t *data, data_static_calcule_t *data_static);

void print_informe_valor(data_calculo_t *data, data_static_calcule_t *data_static);

void print_function(data_calculo_t *data, data_static_calcule_t *data_static);

void print_result(data_calculo_t *data, data_static_calcule_t *data_static);



#endif
