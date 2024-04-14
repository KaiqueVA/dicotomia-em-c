/*
 *Kaique Vecchia Alves RA: 235446
 *Nathalia Atamanchuk RA: 235215
 *Anna Julia Andrade RA: -
 */

#include "exibicao.h"
#include "calculo.h"
#include "allocation.h"


int main() {
    char op;
    data_calculo_t *calculo = NULL;
    data_static_calcule_t calcule_static;

    do {
        system("cls");
        print_informe_valor(calculo, &calcule_static);

        aloca_struct(&calculo, calcule_static.iteracao);

        calculo->a = calcule_static.a_aux;
        calculo->b = calcule_static.b_aux;

        print_function(calculo, &calcule_static);

        zero_in_function(calculo, &calcule_static);

        print_header();
        print_chart(calculo, &calcule_static);

        free(calcule_static.vet_multi);
        free(calculo);

        printf("Deseja realizar outra operacao? (S/N): ");
        scanf(" %c", &op);
    } while (op == 'S' || op == 's');


    return 0;
}
