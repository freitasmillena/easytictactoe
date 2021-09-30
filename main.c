#include <stdio.h>

char box[10]={'0','1','2','3','4', '5','6','7','8','9'};

void tabuleiro();
void jogadas(int jogada, char simbolo);
int resultados();


int main()
{
    int jogada, jogador=1, i;
    char simbolo;
    do{
        tabuleiro();
        jogador = (jogador % 2) ? 1:2;

        printf("\nJogador %d, digite um numero: ", jogador);
        scanf("%d", &jogada);

        simbolo = (jogador == 1) ? 'X' : 'O';
        jogadas(jogada, simbolo);

        i = resultados();
        jogador++;

    } while(i == -1);

    tabuleiro();

    if(i == 1)
        printf("\nJogador %d ganhou o jogo!", --jogador);
    else
        printf("\nEMPATE");
    return 0;
}

//construção do tabuleiro
void tabuleiro()
{
    printf("\n\n\t   Tic Tac Toe\n\n");
    printf("  Jogador 1: (X) -- Jogador 2: (O)\n\n");
    printf("             |       |      \n");
    printf("         %c   |   %c   |   %c   \n", box[1], box[2], box[3]);
    printf("      -------|-------|-------\n");
    printf("             |       |      \n");
    printf("         %c   |   %c   |   %c   \n", box[4], box[5], box[6]);
    printf("      -------|-------|-------\n");
    printf("             |       |      \n");
    printf("         %c   |   %c   |   %c   \n", box[7], box[8], box[9]);
    printf("      -------|-------|-------\n");
    printf("             |       |      \n");

}

//execução das jogadas
void jogadas(int jogada, char simbolo)
{
    if(jogada == 1 && box[1]=='1')
        box[1] = simbolo;
    else if(jogada == 2 && box[2]=='2')
        box[2] = simbolo;
    else if(jogada == 3 && box[3]=='3')
        box[3] = simbolo;
    else if(jogada == 4 && box[4]=='4')
        box[4] = simbolo;
    else if(jogada == 5 && box[5]=='5')
        box[5] = simbolo;
    else if(jogada == 6 && box[6]=='6')
        box[6] = simbolo;
    else if(jogada == 7 && box[7]=='7')
        box[7] = simbolo;
    else if(jogada == 8 && box[8]=='8')
        box[8] = simbolo;
    else if(jogada == 9 && box[9]=='9')
        box[9] = simbolo;
    else if(jogada < 1 || jogada > 9)
    {
        printf("Posição inválida");
    }
    else
    {
        printf("Posição já ocupada");
    }

}

//avaliação dos resultados
int resultados()
{
    int r;
    //horizontal
    if(box[1] == box[2] && box[2] == box[3])
        r = 1;
    else if(box[4] == box[5] && box[5] == box[6])
        r = 1;
    else if(box[7] == box[8] && box[8] == box[9])
        r = 1;
    //vertical
    else if(box[1] == box[4] && box[4] == box[7])
        r = 1;
    else if(box[2] == box[5] && box[5] == box[8])
        r = 1;
    else if(box[3] == box[6] && box[6] == box[9])
        r = 1;
    //diagonal
    else if(box[1] == box[5] && box[5] == box[9])
        r = 1;
    else if(box[3] == box[5] && box[5] == box[7])
        r = 1;
    //empate
    else if(box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
        r = 0;
    //sem resultado
    else
        r = -1;

    return r;
}