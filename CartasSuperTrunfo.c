#include <stdio.h>

int main() {

    // Declaração das variáveis das cartas

    char estado1[3] = "SP";
    char codigo1[4] = "A01";
    char cidade1[50] = "Sao Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 699.28; // em bilhões
    int pontosTuristicos1 = 50;

    char estado2[3] = "RJ";
    char codigo2[4] = "B02";
    char cidade2[50] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300.50; // em bilhões
    int pontosTuristicos2 = 30;

    // Cálculos adicionais

    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;


    // Escolha do atributo a ser comparado
    // (altere aqui para comparar outro atributo)

    // Opções: populacao, area, pib, densidade, pibPerCapita

    char atributo[] = "populacao";

    printf("Comparacao de cartas (Atributo: %s):\n\n", atributo);

    // Lógica de comparação com if e if-else
    
    if (atributo[0] == 'p') { // populacao
        printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo[0] == 'a') { // area
        printf("Carta 1 - %s (%s): %.2f km²\n", cidade1, estado1, area1);
        printf("Carta 2 - %s (%s): %.2f km²\n", cidade2, estado2, area2);

        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (area2 > area1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo[0] == 'd') { // densidade populacional (menor vence)
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade1, estado1, densidade1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (densidade2 < densidade1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo[0] == 'P') { // PIB
        printf("Carta 1 - %s (%s): %.2f bilhoes\n", cidade1, estado1, pib1);
        printf("Carta 2 - %s (%s): %.2f bilhoes\n", cidade2, estado2, pib2);

        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pib2 > pib1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (atributo[0] == 'c') { // PIB per capita
        printf("Carta 1 - %s (%s): %.2f reais\n", cidade1, estado1, pibPerCapita1);
        printf("Carta 2 - %s (%s): %.2f reais\n", cidade2, estado2, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}