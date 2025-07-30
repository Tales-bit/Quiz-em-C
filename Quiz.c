#include<stdio.h>

char resposta;
int acertos=0;
int erros=0;
int i=0;

void alternativas(int na, int nb, char op, int nc, int a, int b, int c, int d, char co1, char co2){
    for (i=0; i<999; i++){
    printf("Questao %d: Qual o resultado de %d%c%d?", na,nb,op,nc);
    printf("\nAlternativa A: %d", a);
    printf("\nAlternativa B: %d", b);
    printf("\nAlternativa C: %d", c);
    printf("\nAlternativa D: %d", d);
    printf("\nEscolha uma alternativa: ");
    scanf(" %c", &resposta);
     if(resposta==co1 || resposta==co2){
                printf("\nCorreto!\n\n");
                acertos=acertos+1;
                break;
            }else if(resposta=='a' || resposta=='A' || resposta=='b' || resposta=='B' || resposta =='c' || resposta=='C' || resposta=='d' || resposta=='D'){
                printf("\nErrado! A alternativa correta era: %c\n\n", co2);
                erros=erros+1;
                break;
            }else{
                printf("\nPor favor, selecione uma alternativa valida(A-D)\n\n");
            }
        }    
}

int main(){
    int aux;
    int aus;
    FILE*ponteiro;
    char r;
    char nome[99];
    for(aux=0; aux<999; aux++){
        printf("==========================\n");
        printf(" Quiz de matematica em C!\n");
        printf("==========================\n\n");
        printf("Comecar Quiz?(s/n): ");
        scanf(" %c", &r);
        if(r=='s' || r=='S'){
            printf("Digite seu nome: ");
            scanf("%s", nome);
            printf("\n");
            alternativas(1, 18, '+', 42, 50, 60, 70, 80, 'b', 'B');
            alternativas(2, 99, '+', 99, 100, 199, 198, 200, 'c', 'C');
            alternativas(3, 475, '-', 175, 400, 301, 300, 600, 'c', 'C');
            alternativas(4, 972, '-', 184, 788, 800, 798, 787, 'a', 'A');
            alternativas(5, 100, '*', 23, 230, 23000, 230000, 2300, 'd', 'D');
            alternativas(6, 92, '*', 3, 276, 286, 423, 372, 'a', 'A');
            alternativas(7, 230, '/', 5, 64, 46, 55, 50, 'b', 'B');
            alternativas(8, 402, '/', 6, 60, 70, 76, 67, 'd', 'D');
            printf("Parabens, %s! Voce chegou ao final do Quiz!\n", nome);
            printf("Voce acertou %d questoes, e errou %d questoes\n\n", acertos, erros);
            for(aus=0; aus<999; aus++){
                printf("Voce gostaria de criar um arquivo .txt com seu nome e seus acertos?(s/n): ");
                scanf(" %c", &r);
                if(r=='s' || r=='S'){
                    ponteiro=fopen("ranking.txt", "a");
                    fprintf(ponteiro, "Nome: %s\n", nome);
                    fprintf(ponteiro, "Acertos: %d\n", acertos);
                    fclose(ponteiro);
                    printf("Arquivo criado com sucesso!\n");
                    printf("Obrigado por realizar o Quiz, ate a proxima!\n\n");
                    break;
                }else if(r=='n' || r=='N'){
                    printf("Ok, ate uma proxima vez!");
                    break;
                }else {
                    printf("Erro, por favor, selecione 's' para sim, ou 'n' para nao\n\n");
                }
                
            }
            break;
        }else if(r=='n' || r=='N'){
            printf("Ok, ate uma proxima vez!\n");
            break;
        }else {
            printf("Erro, por favor, selecione 's' para sim, ou 'n' para nao\n\n");
        }
    }
}