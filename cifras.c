/*

developed by Lárisson Aquino
Brazil - 2017

------------------------------- LEIA-ME ------------------------------------
É DEVIDAMENTE PROIBIDA A VENDA DESTE SOFTWARE, ASSIM COMO SEU CÓDIGO-FONTE.
O PROGRAMA É LIVRE PARA TERCEIROS.
CASO QUEIRA UTILIZÁ-LO, POR FAVOR, DÊ OS SEUS DEVIDOS CRÉDITOS. OBRIGADO.
----------------------------------------------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAXSIZE 10000

void cifrar_substituicao(){
    char str[MAXSIZE];
    int i, k, t;

    printf("\n\tCifra de Substituição\n\n");
    printf("Informe o texto a ser cifrado: ");
    setbuf(stdin, NULL);
    gets(str);
    t = strlen(str);
    printf("Informe a chave de deslocamento: ");
    scanf("%d", &k);

    for(i=0; i<t; i++)
        str[i] = toupper(str[i]);

    for(i=0; i<t; i++){
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i] + k;
            if(str[i]>90)
                str[i] = str[i] - 26;
            if(str[i]<65)
                str[i] = str[i] + 26;
        }
    }

    printf("\nTexto cifrado: %s\n", str);
    
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void decifrar_substituicao(){
    char str[MAXSIZE];
    int i, k, t;

    printf("\n\tCifra de Substituição\n\n");
    printf("Informe a ser decifrado: ");
    setbuf(stdin, NULL);
    gets(str);
    t = strlen(str);
    printf("Informe a chave de deslocamento: ");
    scanf("%d", &k);

    for(i=0; i<t; i++)
        str[i] = toupper(str[i]);

    for(i=0; i<t; i++){
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i] - k;
            if(str[i]>90)
                str[i] = str[i] - 26;
            if(str[i]<65)
                str[i] = str[i] + 26;
        }
    }

    printf("\nTexto decifrado: %s\n", str);
    
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void cifrar_transposicao(){
    char str_plana[MAXSIZE], str_cifrada[MAXSIZE], k[MAXSIZE], k_ordenada[MAXSIZE], korg, aux;
    int pos, contador, tam_k, tam_plano, linhas, colunas;
    int i, j, w, c;

    printf("\n\tCifra de Transposição\n\n");
    printf("Informe a chave (palavra ou frase):\n");
    setbuf(stdin, NULL);
    gets(k);
    tam_k = strlen(k);
	colunas = tam_k;

    for(i=0; i<tam_k; i++)
        k[i] = toupper(k[i]);
    strcpy(k_ordenada, k);

    korg = 'Z';
    for(j=0; j<tam_k; j++){
        for(i=0; i<tam_k; i++){
            if(i<j)
                continue;
            if(k_ordenada[i]>=65 && k_ordenada[i]<=90){
                if(k_ordenada[i]<korg){
                    korg = k_ordenada[i];
                    pos = i;
                }
            }
        }
        aux = k_ordenada[j];
        k_ordenada[j] = korg;
        k_ordenada[pos] = aux;
        korg = 'Z';
    }

    printf("\nInforme o texto a ser cifrado:\n");
    setbuf(stdin, NULL);
    gets(str_plana);
    tam_plano = strlen(str_plana);

    for(i=0, linhas=0; i<tam_plano; i++){
    	if(str_plana[i] != ' ')
    		linhas++;
	}

    linhas = linhas/tam_k;

	char matriz[++linhas][colunas];

	strcpy(matriz[0], k);

	for(i=1, contador=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
            if(str_plana[contador] == ' ')
                contador++;
            matriz[i][j] = str_plana[contador++];
		}
	}

/* //IMPRIME A MATRIZ
    for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++)
			printf("%c ", matriz[i][j]);
		printf("\n");
	}
*/
	for(c=0, contador=0, w=0; c<colunas; c++){
        for(j=0; j<colunas; j++){
            if(matriz[0][j] == k_ordenada[contador]){
                contador++;
                for(i=1; i<linhas; i++){
                    str_cifrada[w++] = matriz[i][j];
                }
            }
        }
	}
	str_cifrada[w] = '\0';
    printf("\nTexto cifrado:\n%s\n", str_cifrada);

    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void decifrar_transposicao(){
    char str_plana[MAXSIZE], str_cifrada[MAXSIZE], k[MAXSIZE], k_ordenada[MAXSIZE], korg, aux;
    int pos, contador, tam_k, tam_cifrada, linhas, colunas, espacos[MAXSIZE];
    int i, j, w, c;

    printf("\n\tCifra de Transposição\n\n");
    printf("Informe a chave (palavra ou frase):\n");
    setbuf(stdin, NULL);
    gets(k);
    tam_k = strlen(k);
	colunas = tam_k;

    for(i=0; i<tam_k; i++)
        k[i] = toupper(k[i]);
    strcpy(k_ordenada, k);

    korg = 'Z';
    for(j=0; j<tam_k; j++){
        for(i=0; i<tam_k; i++){
            if(i<j)
                continue;
            if(k_ordenada[i]>=65 && k_ordenada[i]<=90){
                if(k_ordenada[i]<korg){
                    korg = k_ordenada[i];
                    pos = i;
                }
            }
        }
        aux = k_ordenada[j];
        k_ordenada[j] = korg;
        k_ordenada[pos] = aux;
        korg = 'Z';
    }

    printf("\nInforme o texto a ser decifrado:\n");
    setbuf(stdin, NULL);
    gets(str_cifrada);
    tam_cifrada = strlen(str_cifrada);

    for(i=0, linhas=0, w=0; i<tam_cifrada; i++){
    	if(str_cifrada[i] != ' ')
    		linhas++;
	}

    linhas = linhas/tam_k;

	char matriz[++linhas][colunas];

	strcpy(matriz[0], k);

	for(c=0, contador=0, w=0; c<colunas; c++){
        for(j=0; j<colunas; j++){
            if(matriz[0][j] == k_ordenada[contador]){
                contador++;
                for(i=1; i<linhas; i++){
                    matriz[i][j] = str_cifrada[w++];
                }
            }
        }
	}

/* //IMPRIME A MATRIZ
    for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++)
			printf("%c ", matriz[i][j]);
		printf("\n");
	}
*/
    for(i=1, contador=0; i<linhas; i++){
		for(j=0; j<colunas; j++)
			str_plana[contador++] = matriz[i][j];
	}
	str_plana[contador] = '\0';

    printf("\nTexto decifrado:\n%s\n", str_plana);

    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void cifrar_uso_unico(){
    char str_plano[MAXSIZE], str_cifrado[MAXSIZE];
    int k[MAXSIZE], i, j, contak, tam_plano, tam_cifrado;

	strcpy(str_cifrado, "");

	printf("\n\tCifra de Uso Único\n\n");
    printf("Informe a chave (em inteiros)\n");
    printf("OBS: Use número negativo para marcar fim de entrada.\n\n");
    
	contak=0;
	while(1){
		scanf("%d", &k[contak]);
		if(k[contak] < 0)
			break;
		contak++;
	}

    printf("\nInforme o texto a ser cifrado:\n");
    setbuf(stdin, NULL);
    gets(str_plano);
    tam_plano = strlen(str_plano);

    for(i=0, j=0; i<tam_plano; i++, j++){
    	if(str_plano[i] == ' '){
			i++;
			j--;
			continue;}
		if(str_plano[i] == k[j]){
    		str_cifrado[i] = '0';
    		continue;}
        str_cifrado[i] = str_plano[i] ^ k[j];
        if(j == contak-1)
			j=-1;
    }

    str_cifrado[i] = '\0';
    tam_cifrado = strlen(str_cifrado);
	
	printf("\nTexto cifrado (em inteiros):\n");
	
    for(i=0; i<tam_cifrado; i++){
    	if(str_cifrado[i] == '0'){
    		printf("%c ", str_cifrado[i]);
    		continue;
    	}
        printf("%d ", str_cifrado[i]);
    }
    printf("\n");

    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void decifrar_uso_unico(){
    char str_plano[MAXSIZE];
    int k[MAXSIZE], i, j, contador, tam_plano, contak, tam_cifrado, str_cifrado[MAXSIZE];
    
    printf("\n\tCifra de Uso Único\n\n");
    printf("Informe a chave\n");
    printf("OBS: Use número negativo para marcar fim de entrada.\n\n");
    
	contak=0;
	while(1){
		scanf("%d", &k[contak]);
		if(k[contak] < 0)
			break;
		contak++;
	}

    printf("\nInforme o texto a ser decifrado (em inteiros)\n");
    printf("OBS: Use número negativo para marcar fim de entrada.\n");
    
    for(i=0, contador=0; i<MAXSIZE; i++, contador++){
    	scanf("%d", &str_cifrado[i]);
    	if(str_cifrado[i] < 0)
    		break;
	}

	for(i=0, j=0; i<contador; i++, j++){
		str_plano[i] = str_cifrado[i] ^ k[j];
		if(j == contak-1)
			j=-1;
	}
	str_plano[i] = '\0';
	
	printf("\nTexto decifrado:\n%s\n", str_plano);
	
	printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void creditos(){
	system("cls");
	printf("\n\tCRÉDITOS / LICENÇA\n\n");
	printf("\nDesenvolvido por Lárisson Aquino\n");
	printf("Brasil, 2017\n");
	printf("\n- LICENÇA\n");
	printf("\nÉ devidamente proibida a venda deste software sob quaisquer circunstâncias.\nProduto de uso livre para terceiros.\n");
	printf("\n- COMENTÁRIOS\n");
	printf("\nPrograma desenvolvido em linguagem C.\n");
	printf("\nFiz esse programa básico para um trabalho da faculdade\ne achei viável compartilhá-lo.\n");
	
	getch();
}

/* 
------------------------------------------------------------------------------------------------------------------------------------
													M	E	N	U	S
------------------------------------------------------------------------------------------------------------------------------------
*/

void substituicao_menu(){
    char op;

    while(1){
        system("cls");
        printf("\n\tCifra de Substituição\n\n");
        printf("\n1 - Cifrar\n");
        printf("\n2 - Decifrar\n");
        printf("\n3 - Voltar ao menu\n");

        op = getch();

        switch(op){
            case '1':
                system("cls");
                cifrar_substituicao();
                break;
            case '2':
                system("cls");
                decifrar_substituicao();
                break;
            case '3':
                menu();
                break;
            default:
                printf("\n\nOpção inválida!\n");
        }
    }
}

void transposicao_menu(){
    char op;

    while(1){
        system("cls");
        printf("\n\tCifra de Transposição\n\n");
        printf("\n1 - Cifrar\n");
        printf("\n2 - Decifrar\n");
        printf("\n3 - Voltar ao menu\n");

        op = getch();

        switch(op){
            case '1':
                system("cls");
                cifrar_transposicao();
                break;
            case '2':
                system("cls");
                decifrar_transposicao();
                break;
            case '3':
                menu();
                break;
            default:
                printf("\n\nOpção inválida!\n");
        }
    }
}

void uso_unico_menu(){
    char op;

    while(1){
        system("cls");
        printf("\n\tCifra de Uso Único\n\n");;
        printf("\n1 - Cifrar\n");
        printf("\n2 - Decifrar\n");
        printf("\n3 - Voltar ao menu\n");

        op = getch();

        switch(op){
            case '1':
                system("cls");
                cifrar_uso_unico();
                break;
            case '2':
                system("cls");
                decifrar_uso_unico();
                break;
            case '3':
                menu();
                break;
            default:
                printf("\n\nOpção inválida!\n");
        }
    }
}

void menu(){
    char op;

    while(1){
        system("cls");
        printf("\n\tBEM VINDO AO CIFRAUNDERCOVER\n\n");
        printf("\n1 - Cifra de Substituição\n");
        printf("\n2 - Cifra de Transposição\n");
        printf("\n3 - Cifra de Uso Único\n");
        printf("\n4 - Créditos / Licença\n");
        printf("\n5 - Sair do programa\n");

        op = getch();

        switch(op){
            case '1':
                substituicao_menu();
                break;
            case '2':
                transposicao_menu();
                break;
            case '3':
                uso_unico_menu();
                break;
            case '4':
            	creditos();
            	break;
            case '5':
                exit(1);
                break;
            default:
                printf("\n\nOpção inválida!\n");
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    menu();

    return 0;
}
