#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

// Função para comparar atributos
float pegarValorAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8515767, 1.9, 50, 214000000.0 / 8515767};
    Carta carta2 = {"Japão", 125000000, 377975, 4.9, 40, 125000000.0 / 377975};

    int opcao1, opcao2;

    printf("===== SUPER TRUNFO =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Menu do primeiro atributo
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Menu do segundo atributo (dinâmico)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Comparação
    float valor1_c1 = pegarValorAtributo(carta1, opcao1);
    float valor1_c2 = pegarValorAtributo(carta2, opcao1);
    float valor2_c1 = pegarValorAtributo(carta1, opcao2);
    float valor2_c2 = pegarValorAtributo(carta2, opcao2);

    // Para densidade, regra é invertida (menor vence)
    int vencedorAtributo1 = (opcao1 == 5) 
                            ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0))
                            : (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    int vencedorAtributo2 = (opcao2 == 5) 
                            ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0))
                            : (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // Resultado final
    printf("\n===== RESULTADO =====\n");
    printf("Atributo 1: %s\n", nomeAtributo(opcao1));
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor1_c1, carta2.nome, valor1_c2);

    printf("\nAtributo 2: %s\n", nomeAtributo(opcao2));
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor2_c1, carta2.nome, valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    if (soma1 > soma2) {
        printf("\n>>> %s VENCEU! <<<\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\n>>> %s VENCEU! <<<\n", carta2.nome);
    } else {
        printf("\n>>> EMPATE! <<<\n");
    }

    return 0;
}