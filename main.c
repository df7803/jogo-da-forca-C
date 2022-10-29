#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


//https://www.youtube.com/watch?v=JYMAid8-aOE
void forca(int estado)
{
    if(estado ==0)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==1)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==2)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|          |");
        printf("\n|");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==3)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         /|");
        printf("\n|");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==4)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         /|\\");
        printf("\n|");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==5)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         /|\\");
        printf("\n|           \\");
        printf("\n|");
        printf("\n_");
    }
    else if (estado==6)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|          O");
        printf("\n|         /|\\");
        printf("\n|         / \\");
        printf("\n|");
        printf("\nATENCAO!!! ");
    }
    else if (estado==7)
    {
        printf("\n------------");
        printf("\n|          |");
        printf("\n|         ___");
        printf("\n|         ");
        printf("\n|         ");
        printf("\n|");
        printf("\nVOCE PERDEU!!! ");
    }
}

int main(void)
{

    char psec[100];// faz a palavra ficar oculta
    printf("jogador 1\n");
    printf("informe a palavra secreta: \n");
    fgets(psec, 100, stdin);  // captura palavras com espaço
    printf("a palavra secreta e: %s", psec);
    system("cls");
    printf("\na palavra tem %lu caracteres\n", strlen(psec)-1);
    // retira o ultimo caracter devido ao fgets()
    psec[strlen(psec)-1]= '\0';
    char ptela[100];//palavra na tela
    strcpy(ptela,psec);// copia de p_sec para p_tela
    //substitue letras por underscore
    for(int i = 0; i < strlen(ptela); i++ )
    {
        ptela[i] = '_';
    }
    int erros = 0;
    while (1)
    {
        //imprimir a  forca
        forca(erros);
        //imprimir os underline/underscores   '_' para cada letra secreta
        printf("\nadivinha: ");
        for(int i = 0; i < strlen(ptela); i++)
        {
            printf(" %c ",ptela[i]);
        }
        // se a letra esta correta atualiza palavra na tela e verifica se o jogo acabou
        char letra;
        printf("\nletra: ");
        scanf(" %c", &letra);
        //verifica se a letra esta correta
        int seraQueErrou = 1;
        for(int i = 0; i<strlen(ptela); i++)
        {
            if(letra == psec[i])
            {
                ptela[i]=letra;
                seraQueErrou=0;
            }
        }
        //se não incrementa erros
        if(seraQueErrou==1)
        {
            erros++;
        }
        // verifica se ganhou
        if (strcmp(ptela,psec)==0)
        {
            printf("\nacertou: ");
            for(int i = 0; i < strlen(ptela); i++)
            {
                printf(" %c ",ptela[i]);
            }
            //verifica se venceu
            printf("VOCE VENCEU");
            break;
        }
        // verifica se o jogo acabou
        if (erros ==7)
        {
            forca(erros);
            break;
        }
    }


    return 0;

}
