#include <stdio.h>
#include <locale.h>
#include <string.h>

#define LIN 5 //lugares linha
#define COL 5 //lugares coluna

enum Pago {
    SIM,
    NAO
};

typedef struct pessoa {
    char nome[100];
    int lugar;
    enum Pago Faturado;
} Pessoa;

// protótipos
void iniciaLugares(char lugares[LIN][COL]);
char desenhaMenu();
short criaReserva(Pessoa pessoas[LIN*COL], char lugares[LIN][COL], int *reservas);
void mostraLugaresVagos(char lugares[LIN][COL]);
short lugarValido(char lugares[LIN][COL], int lugar, int *posicao);
short eliminaReserva(Pessoa pessoas[LIN*COL], int *reservas, char lugares[LIN][COL]);
void listaReservas(Pessoa pessoas[LIN*COL], int reservas);

int main() {
    setlocale(LC_ALL, "Portuguese");

    char op = ' ';
    short quit = 0;
    char lugares[LIN][COL];
    Pessoa pessoas[LIN*COL];
    int reservas = 0;

    iniciaLugares(lugares);

    do {
        op = desenhaMenu();

        switch (op) {
            case '1':
                // cria reserva
                mostraLugaresVagos(lugares);
                if (criaReserva(pessoas, lugares, &reservas) == 0) {
                    printf("\nNão conseguiu criar reserva!!\n");
                } else {
                    printf("\nReserva criada!\n");
                }
                break;
            case '2':
                // Eliminar uma reserva;
                mostraLugaresVagos(lugares);
                if (eliminaReserva(pessoas, &reservas, lugares) == 0) {
                    printf("\nErro a eliminar reserva!\n");
                } else {
                    printf("\nReserva eliminada com sucesso!\n\n");
                }
                break;
            case '3':
                // Apresenta Mapa da ocupação da sala
                mostraLugaresVagos(lugares);
                break;
            case '4':
                // Listar as reservas já realizadas
                listaReservas(pessoas, reservas);
                break;
            case 'q':
            case 'Q':
                printf("\n\nObrigado!");
                quit = 1;
                break;
            default:
                printf("\nOpção inválida!!!\n");
        }
    } while (quit == 0);

    printf("\n");
    return 0;
}

short eliminaReserva(Pessoa pessoas[LIN*COL], int *reservas, char lugares[LIN][COL]) {
    if (*reservas > 0) {
        short lugar = 0;
        printf("\nQual o lugar da reserva a eliminar? ");
        scanf(" %hd", &lugar);

        for (int i = 0; i < *reservas; ++i) {
            if (pessoas[i].lugar == lugar) {
                // Marca o lugar como vago
                for (int l = 0; l < LIN; ++l)
                    for (int c = 0; c < COL; ++c) {
                        if (l * COL + c + 1 == lugar) {
                            lugares[l][c] = ' '; // Marca como vago
                        }
                    }

                // Remove a reserva movendo todas as seguintes para a frente
                for (int j = i; j < *reservas - 1; ++j) {
                    pessoas[j] = pessoas[j + 1]; // Move a reserva para a posição anterior
                }
                *reservas = *reservas - 1; // Decrementa o número de reservas
                return 1; // Reserva eliminada com sucesso
            }
        }
    } else {
        printf("\nNão existem reservas!\n\n");
    }
    return 0;
}

void listaReservas(Pessoa pessoas[LIN*COL], int reservas) {
    if (reservas != 0) {
        for (int i = 0; i < reservas; ++i) {
            printf("\nLugar %d\nNome: %s\nPago: %s;\n", pessoas[i].lugar, pessoas[i].nome, (pessoas[i].Faturado == SIM) ? "Sim" : "Não");
        }
    } else {
        printf("\nNão existem reservas para mostrar!!\n");
    }
}

short criaReserva(Pessoa pessoas[LIN*COL], char lugares[LIN][COL], int *reservas) {
    if (*reservas == LIN*COL) {
        printf("\n\nNão existem reservas disponíveis.\nESGOTADO!!!\n\n");
    } else {
        Pessoa p;
        char op = ' ';
        int pos = 0;
        printf("\nNome da Pessoa: ");
        getchar();  // Limpa o buffer de entrada antes de usar fgets
        fgets(p.nome, 100, stdin);
        p.nome[strcspn(p.nome, "\n")] = 0; // Remove o caractere de nova linha

        do {
            printf("\nLugar: ");
            scanf(" %d", &p.lugar);
        } while (lugarValido(lugares, p.lugar, &pos) == 0);

        do {
            printf("\nPago S/N: ");
            scanf(" %c", &op);
        } while (op != 's' && op != 'S' && op != 'n' && op != 'N');

        if (op == 's' || op == 'S') p.Faturado = SIM;
        else p.Faturado = NAO;

        // Copia pessoa lida para vetor pessoas
        strcpy(pessoas[pos].nome, p.nome);
        pessoas[pos].lugar = p.lugar;
        pessoas[pos].Faturado = p.Faturado;

        *reservas = *reservas + 1;
        printf("\nReserva criada com sucesso!\n");

        return 1;
    }

    return 0; //não cria reserva
}

short lugarValido(char lugares[LIN][COL], int lugar, int *posicao) {
    for (int i = 0; i < LIN; ++i)
        for (int j = 0; j < COL; ++j)
            if (i * COL + j + 1 == lugar) {
                if (lugares[i][j] == ' ') {
                    lugares[i][j] = 'X'; // Assinala o lugar como ocupado
                    *posicao = lugar - 1;
                    return 1; // Lugar válido
                } else {
                    return 0; // Lugar já ocupado
                }
            }
    return 0; // Lugar inválido
}

void mostraLugaresVagos(char lugares[LIN][COL]) {
    printf("\nLugares vagos sem X!!\n\n");
    for (int i = 0; i < LIN; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (lugares[i][j] == ' ') {
                printf("[%d]", i * COL + j + 1);
            } else {
                printf("[X]");
            }
        }
        printf("\n");
    }
}

char desenhaMenu() {
    char op;

    printf("\n1- Criar uma nova reserva;");
    printf("\n2- Eliminar uma reserva;");
    printf("\n3- Apresenta Mapa da ocupação da sala;");
    printf("\n4- Listar as reservas já realizadas;");
    printf("\nq- Sair;");
    printf("\n\nOpção: ");

    scanf(" %c", &op);

    return op;
}

void iniciaLugares(char lugares[LIN][COL]) {
    for (int i = 0; i < LIN; ++i)
        for (int j = 0; j < COL; ++j) {
            lugares[i][j] = ' ';
        }
}
