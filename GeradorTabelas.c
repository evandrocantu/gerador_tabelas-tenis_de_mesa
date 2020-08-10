//Arquivo GeradorTabelas.c

//Programa Gerador de Tabelas Esportivas
//Desenvolvido por Evandro Cantú
//Instituto Federal do Paraná
//Foz do Iguaçu, outubro 2016
//Contato: evandro.cantu@ifpr.edu.br
//Atualização: jun/2017

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

char tabela[] = "Tabelas.txt";
FILE *arq;

//matamata: Função para determinar as partidas de uma eliminatória simples.
//          Recebe como parâmetro o número de jogadores e
//          o vetor com os jogadores
void matamata (int n, char jogadores[32][20]);
//Protótipo: Arquivo fonte MataMata.c

//copa: Função organizar a competição em grupos.
//      Recebe como parâmetros o número de grupos (g), número de
//      jogadores (n), número de classificados por grupo (nc) e
//      o vetor com os jogadores. 
void copa (int r, int g, int n, int nc, char jogadores[80][20]);
//Protótipo: Arquivo fonte Copa.c

//rodizio: Função para determinar as partidas de um rodízio simples,
//         com todos jogando contra todos.
//         Recebe como parâmetro o número de jogadores e
//         o vetor com os jogadores
void rodizio (int n, char jogadores[80][20])
{
  int c = 0;
  int i, j, k;
  char ultimoJogador[20] = {""};
  //SE número impar de jogadores ENTÃO adiciona um jogador vazio
  if (n % 2 == 1) { 
     strcpy(jogadores[n], ultimoJogador);
     n = n + 1;
  }
  arq = fopen(tabela, "a");
  fprintf(arq, "\nPARTIDAS \nDO RODÍZIO: \n\n");
  for (k=0;k<n-1;k++)
  {
    fprintf(arq, "%sRodada: %2d\n", "",k+1);
    for (i=0;i<n/2;i++)
      if ((strcmp(jogadores[i], "") != 0) && (strcmp(jogadores[n-1-i], "") != 0))
        fprintf(arq, "%2d: %20s _ x _ %-20s\n", ++c, jogadores[i], jogadores[n-1-i]);
    //Rotaciona vetor de jogadores, menos primeira posição
    strcpy(ultimoJogador, jogadores[n-1]);
    for (j=n-1;j>0;j--)
      strcpy(jogadores[j], jogadores[j-1]);
    strcpy(jogadores[1], ultimoJogador);
  }
  fclose(arq);
}
//Ref: https://pt.wikipedia.org/wiki/Competições_de_todos_contra_todos

/* FUNÇÃO ANTERIOR SEM ORGANIZAR RODADAS
void rodizio (int n, char jogadores[80][20])
{
  int c = 0;
  int i, j;
  arq = fopen(tabela, "a");
  fprintf(arq, "\nPARTIDAS DO RODÍZIO: \n");
  for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
      fprintf(arq, "%2d: %20s _ x _ %-20s\n", ++c, jogadores[i], jogadores[j]);
  fclose(arq);
}
*/

//embaralhar: Função para embaralhar um vetor.
//            Recebe como parâmetro o vetor com os jogadores
//            a serem embaralhados e o tamanho do vetor.
void embaralhar(char vetor[80][20], int tamVetor)
{
  int i;
  char temp[20];
  srand(time(NULL));
  for (i = 0; i < tamVetor; i++)
  {
    int r = rand() %tamVetor;
    strcpy(temp,   vetor[i]);
    strcpy(vetor[i], vetor[r]);
    strcpy(vetor[r], temp);
  }
}

int main(int argc, char *argv[]) 
//Arquivo com jogadores pode ser fornecido como parâmetro
{
  char jogador[20];
  char jogadores[80][20];
  int n = 0;   //número de jogadores cadastrados
  int g = 0;   //número de grupos
  int nc = 2;  //Número de classificados por GRUPO
  int r;       //Número de jogadores incluídos pelo RANKING nos GRUPOS
  int i;
  char resposta;
  int tam;
  char arquivo[20];
  if (argc == 1)
  {
    printf("\nCADASTRO DE JOGADORES\n");
    printf("\nEntre com NOME DO ARQUIVO com os jogadores:\n");
    fgets(arquivo, sizeof(arquivo), stdin);
    tam = strlen(arquivo);
    if (arquivo[tam - 1] == '\n')
      arquivo[tam - 1] = '\0';
  }
  else
  {
    strcpy (arquivo, argv[1]);
  }
  FILE *arq;
  arq = fopen(arquivo, "r");
  if(arq == NULL) {
    printf("\nNao foi possivel abrir o arquivo!\n");
    printf("\nConfira se o nome do arquivo está correto, incluindo a extensão txt.\n");
    return(1);}
  else
    //Monta vetor com os jogadores
    while( (fscanf(arq,"%s\n", jogador))!=EOF )
    {
      strcpy(jogadores[n], jogador);
      n++;
    }
  fclose(arq);
  arq = fopen(tabela, "w");
  fprintf(arq, "\n+----------------------------------------------------+\n");
  fprintf(arq, "\n       PROGRAMA GERADOR DE TABELAS ESPORTIVAS\n");
  fprintf(arq, "\n+----------------------------------------------------+\n");
  fprintf(arq, "\n  Evento: _________________________________________\n");
  fprintf(arq, "\n  Local:  _________________________________________\n");
  fprintf(arq, "\n  Data:   _________________________________________\n");
  fprintf(arq, "\n+----------------------------------------------------+\n");
  //Data e hora do sistema
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  fprintf(arq, "\n      Geração das Tabelas: %d/%d/%d - %d:%d\n", 
          tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
  fprintf(arq, "\n+----------------------------------------------------+\n");
  //Imprime jogadores cadastrados
  fprintf(arq, "\nJOGADORES CADASTRADOS:\n");
  for (i=0; i<n; i++)
  {
    printf("%2d: %-20s\n", i + 1, jogadores[i]);
    fprintf(arq, "%2d: %-20s\n", i + 1, jogadores[i]);
  }
  fclose(arq);
  //Pergunta sobre formato da competição
  do
  {
    printf("\nESCOHA FORMATO DA COMPETIÇÃO: \n");
    if (n >= 4 && n <= 80)
      printf(" (C) Copa: Grupos + Fase Final\n");
    printf(" (R) Rodízio simples\n");
      if (n <= 16 || n == 24 || n == 32)
      printf(" (E) Eliminatória simples\n");
    scanf (" %c",&resposta);
  } while (resposta != 'c' && resposta != 'C' && 
           resposta != 'r' && resposta != 'R' &&
           resposta != 'e' && resposta != 'e');
  if (resposta == 'r' || resposta == 'R')
    //Chama função rodizio
    rodizio (n, jogadores);
  if (resposta ==  'e' || resposta == 'E') {
    //Pergunta sobre formato do sorteio
    do
    {
      printf("\nESCOLHA FORMATO DO SORTEIO: \n");
      printf(" (R) Manter ordem de RANKING\n");
      printf(" (S) SORTEAR e embaralhar TODOS os jogadores\n");
      scanf (" %c",&resposta);
    } while (resposta != 's' && resposta != 'S' && 
             resposta != 'r' && resposta != 'R');
    if (resposta == 's' || resposta == 'S')
      embaralhar(jogadores, n);
    //Chama função matamata
    matamata(n, jogadores);
    }
  if (resposta ==  'c' || resposta == 'C')
  {
    //Pergunta sobre número de GRUPOS
    do
    {
      printf("\n  Escolha quantos GRUPOS: \n");
      if (n >= 4 && n <= 10) {
        printf("   (2) Dois   GRUPOS (%d ", n / 2);
        if (n % 2 != 0) printf("ou %d ", n / 2 + 1);
        printf("jogadores cada)");
        if (n / 2 == 3 || (n / 2 == 4 && n % 2 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 6 && n <= 15) {
        printf("   (3) Três   GRUPOS (%d ", n / 3);
        if (n % 3 != 0) printf("ou %d ", n / 3 + 1);
        printf("jogadores cada)");
        if (n / 3 == 3 || (n / 3 == 4 && n % 3 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 8 && n <= 20) {
        printf("   (4) Quatro GRUPOS (%d ", n / 4);
        if (n % 4 != 0) printf("ou %d ", n / 4 + 1);
        printf("jogadores cada)");
        if (n / 4 == 3 || (n / 4 == 4 && n % 4 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 10 && n <= 25) {
        printf("   (5) Cinco  GRUPOS (%d ", n / 5);
        if (n % 5 != 0) printf("ou %d ", n / 5 + 1);
        printf("jogadores cada)");
        if (n / 5 == 3 || (n / 5 == 4 && n % 5 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 12 && n <= 30) {
        printf("   (6) Seis   GRUPOS (%d ", n / 6);
        if (n % 6 != 0) printf("ou %d ", n / 6 + 1);
        printf("jogadores cada)");
        if (n / 6 == 3 || (n / 6 == 4 && n % 6 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 14 && n <= 35) {
        printf("   (7) Sete   GRUPOS (%d ", n / 7);
        if (n % 7 != 0) printf("ou %d ", n / 7 + 1);
        printf("jogadores cada)");
        if (n / 7 == 3 || (n / 7 == 4 && n % 7 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 16 && n <= 40) {
        printf("   (8) Oito   GRUPOS (%d ", n / 8);
        if (n % 8 != 0) printf("ou %d ", n / 8 + 1);
        printf("jogadores cada)");
        if (n / 8 == 3 || (n / 8 == 4 && n % 8 == 0))
          printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 24 && n <= 60) {
        printf("   (Z) Doze   GRUPOS (%d ", n / 12);
        if (n % 12 != 0) printf("ou %d ", n / 12 + 1);
        printf("jogadores cada)");
        if (n / 12 == 3 || (n / 12 == 4 && n % 12 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      if (n >= 32 && n <= 80) {
        printf("   (S) Dezeseis GRUPOS (%d ", n / 16);
        if (n % 16 != 0) printf("ou %d ", n / 16 + 1);
        printf("jogadores cada)");
        if (n / 16 == 3 || (n / 16 == 4 && n % 16 == 0))
           printf("  <- melhor escolha\n"); else printf("\n");}
      scanf (" %c",&resposta);
    } while (resposta != '2' && resposta != '3' && resposta != '4' && 
             resposta != '5' && resposta != '6' && resposta != '7' &&
             resposta != '8' && resposta != 'z' && resposta != 'Z' &&
             resposta != 's' && resposta != 'S');
    if (resposta == '2' || resposta == '3'|| resposta == '4'||
        resposta == '5' || resposta == '6')
    {
      if (resposta == '2')
        g = 2;
      if (resposta == '3')
        g = 3;
      if (resposta == '4')
        g = 4;
      if (resposta == '5')
        g = 5;
      if (resposta == '6')
        g = 6;
      if ((g == 2 && n >= 6)  || (g == 3 && n >= 9) || (g == 4 && n >= 12) ||
          (g == 5 && n >= 15) || (g == 6 && n >= 18))
        //Pergunta sobre número de classificados por GRUPO
        do
        {
          printf("\n  Escolha número de classificados por GRUPO: \n");
          printf("   (2) Dois\n");
          printf("   (3) Três\n");
          scanf (" %c",&resposta);
        } while (resposta != '2' && resposta != '3'); 
      if (resposta == '2')
        nc = 2;
      if (resposta == '3')
        nc = 3;
    }
    if (resposta == '7')
      g = 7;
    if (resposta == '8')
      g = 8;
    if (resposta == 'z' || resposta == 'Z')
      g = 12;
    if (resposta == 's' || resposta == 'S')
      g = 16;
    //Pergunta sobre formato do sorteio
    do
    {
      printf("\nESCOLHA O FORMATO DA MONTAGEM DOS GRUPOS: \n");
      printf(" (R) Manter ordem de RANKING para organizar GRUPOS\n");
      printf(" (1) Incluir UM   pelo RANKING e embaralhar demais\n");
      if (n / g >= 2)
        printf(" (2) Incluir DOIS pelo RANKING e embaralhar demais\n");
      if (n / g >= 3)
        printf(" (3) Incluir TRÊS pelo RANKING e embaralhar demais\n");
      printf(" (S) SORTEAR e embaralhar TODOS os jogadores\n");
      scanf (" %c",&resposta);
    } while (resposta != 's' && resposta != 'S' && 
             resposta != '1' && resposta != '2' && resposta != '3' &&
             resposta != 'r' && resposta != 'R');
    if (resposta == 's' || resposta == 'S') 
      r = 0;
    if (resposta == '1')
      r = 1;
    if (resposta == '2')
      r = 2;
    if (resposta == '3')
      r = 3;
    if (resposta == 'r' || resposta == 'R')
      r = 4;
   //Chama função copa
   copa(r, g, n, nc, jogadores);
  }
  arq = fopen(tabela, "a");
  fprintf(arq, "\n+----------------------------------------------------+\n");
  fprintf(arq, "\n Programa desenvolvido por: Evandro Cantú");
  fprintf(arq, "\n Contato: evandro.cantu@ifpr.edu.br");
  fprintf(arq, "\n Data da compilação: %s\n",__DATE__);
  fclose(arq);
  return(0);
}


