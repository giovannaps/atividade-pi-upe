
#include <stdio.h>
#include <stdlib.h>

#define N 5

struct cad {
    char nome[50];
    float renda;
    int ano;
    char carro;
};
struct cad clientes[N];

float media()
{
    float media = 0, soma = 0;
    int atual = 0;

    do {
        soma += (clientes + atual)->renda;
        atual += 1;
    } while (atual < N);

    media = soma / N;
    return media;
}

int conta_renda()
{
    int qnt_ram = 0, atual = 0;
    float media_ = media();

    do {
        if ((clientes + atual)->renda > media_) {
            qnt_ram += 1;
        }
        atual += 1;
    } while (atual < N);

    return qnt_ram;
}

void cadastro()
{
    int total = N, atual = 0;

    do {
        printf("cadastro de cliente %d:\n", atual + 1);
        printf("nome: ");
        scanf(" %[^\n]", (clientes + atual)->nome);

        printf("renda: ");
        scanf("%f", &( (clientes + atual)->renda ));

        printf("ano de nascimento: ");
        scanf("%d", &( (clientes + atual)->ano ));

        printf("tem carro?(s/n): ");
        scanf(" %c", &( (clientes + atual)->carro ));

        atual += 1;
    } while (atual < N);
}

int conta_carro()
{
    int clientes_com_carro = 0, atual = 0;

    do {
        if ((clientes + atual)->carro == 's' || (clientes + atual)->carro == 'S') {
            clientes_com_carro += 1;
        }
        atual += 1;
    } while (atual < N);

    return clientes_com_carro;
}

int idades()
{
    int atual = 0, clientes_idade = 0;

    do {
        if ((clientes + atual)->ano >= 1960 && (clientes + atual)->ano <= 1980) {
            clientes_idade += 1;
        }
        atual += 1;
    } while (atual < N);

    return clientes_idade;
}

int main()
{
    int acmed, tc, nasc;
    cadastro();
    acmed = conta_renda();
    tc = conta_carro();
    nasc = idades();

    printf("%d clientes tem renda acima da media\n", acmed);
    printf("%d clientes tem carro\n", tc);
    printf("%d clientes nasceram entre 1960 e 1980\n", nasc);

    return 0;
}

