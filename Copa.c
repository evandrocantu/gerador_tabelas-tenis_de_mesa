//Arquivo Copa.c

//Programa Gerador de Tabelas Esportivas
//Função copa utilizada pelo programa principal.

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

void matamata (int n, char jogadores[32][20]);
void rodizio (int n, char jogadores[80][20]);
void embaralhar(char vetor[80][20], int tamVetor);

//calExtra: Função auxiliar da função copa, permtindo verificar se
//          há jogadores extra em um grupo, quando a divisão entre
//          o número de jogadores e o número de grupos não é exata.
int calExtra (int *mod)
{
  if (*mod > 0)
  { 
    *mod = *mod - 1;
    return (1);
  }
  return (0);
}

//copa: Função organizar a competição em grupos.
//      Recebe como parâmetros o número de jogadores a serem incluídos
//      pelo Ranking (r), o número de grupos (g), número de
//      jogadores (n), número de classificados por grupo (nc) e
//      o vetor com os jogadores. 
void copa (int r, int g, int n, int nc, char jogadores[80][20])
{
  char tabela[] = "Tabelas.txt";
  FILE *arq;
  char grupos[16][80][20];
  char nomeGrupo[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
  int i, j;
  int c = 0;
  int div, mod;
  div = n / g; //Número mínimo de jogadores por GRUPO
  mod = n % g; //Jogador(es) extra para alocar em GRUPO(s)
  int ng = n;  //Número de jogadores além incluídos pelo RANKING
  int extra[8];
  int offset = 0;
  arq = fopen(tabela, "a");
  fprintf(arq, "\nCOMPETIÇÃO NO FORMATO COPA: \n");
  fprintf(arq, "-> %2d GRUPOS\n-> %2d Classificados cada GRUPO\n", g, nc);
  fprintf(arq, "\n+----------------------------------------------------+");
  fprintf(arq, "\n                 TABELAS DE JOGOS: ");
  fprintf(arq, "\n+----------------------------------------------------+");
  fclose(arq);
  //Inclusão de jogadores nos GRUPOS de acordo com RANKING
  if (r >= 1)
  {
    for (i = 0; i < g; i++) //Cabeças de GRUPO
      strcpy(grupos[i][0], jogadores[i]);
    ng = n - g;  //Número total de jogadores restantes
    c = 1;       
  }
  if (r >= 2)
  {
    for (i = 0; i < g; i++) //Segundo integrante do GRUPO na ordem inversa
      strcpy(grupos[i][1], jogadores[2 * g - 1 - i]);
    ng = n - 2 * g; //Número total de jogadores restantes
    c = 2;       
  }
  if ((r >= 3) && (n / g > 2))
  {
    for (i = 0; i < g; i++) //Terceiro integrante do GRUPO
      strcpy(grupos[i][2], jogadores[2 * g + i]);
    ng = n - 3 * g; //Número total de jogadores restantes
    c = 3;
  }
  if ((r == 4) && (n / g > 3))
  {
    for (i = 0; i < g; i++) //Terceiro integrante do GRUPO
      strcpy(grupos[i][3], jogadores[4 * g - 1 - i]);
    ng = n - 4 * g; //Número total de jogadores restantes
    c = 4;
  }
  for (i = 0; i < ng; i++)             
    strcpy(jogadores[i], jogadores[c * g + i]);  //Retira jogadores já incluídos
  if (r != 4)
    embaralhar(jogadores, ng); //Embaralha restantes
  //Monta GRUPOS, verificado através da função callExtra se
  //há jogadores extra em um grupo, quando a divisão entre
  //o número de jogadores e o número de grupos não é exata.
  for (j = 0; j < g; j++)              
  {
    extra[j] = calExtra(&mod);
    for (i = 0; i < ng/g + extra[j]; i++)
      //Inclui o restante dos jogadores nos GRUPOS
      strcpy(grupos[j][i+c], jogadores[i + offset]);
    //offset marca no vetor com os jogadores a posição do próximo
    //jogador a ser incluídos no próximo GRUPO.      
    offset = offset + ng/g + extra[j];
    arq = fopen(tabela, "a");
    fprintf(arq, "\n+------------------------------------------------+");
    fprintf(arq, "\n| GRUPO %c : Jogadores | Vitórias | Saldo de Sets |", nomeGrupo[j]);
    fprintf(arq, "\n+---------------------+----------+---------------+\n");
    //Imprime os membros de cada GRUPO
    for (i = 0; i < n/g + extra[j]; i++)
      fprintf(arq, "|%20s |          |               |\n", grupos[j][i]);
    fprintf(arq, "+------------------------------------------------+\n");
    fclose(arq);
    //Chama a função rodízio para determinar as partidas do GRUPO
    rodizio (n/g + extra[j], grupos[j]);
  }
  //Sequência de vetores de strings que definem a ordem dos confrontos
  //para as Finais no formato Copa, considerando o número de grupos (g)
  //e o número de classificados (c) por grupo.
  char final2g2c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", 
"2o Grupo A ________", "2o Grupo B ________"};
  char final2g3c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "2o Grupo A ________", 
"2o Grupo B ________", "3o Grupo A ________", "3o Grupo B ________"};
  char final3g2c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"2o Grupo B ________", "2o Grupo C ________", "2o Grupo A ________"};
  char final3g3c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"2o Grupo B ________", "2o Grupo C ________", "2o Grupo A ________", 
"3o Grupo A ________", "3o Grupo B ________", "3o Grupo C ________"};
  char final4g2c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", "1o Grupo D ________", 
"2o Grupo B ________", "2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________"};
  char final4g3c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", "1o Grupo D ________", 
"2o Grupo B ________", "2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________", 
"3o Grupo B ________", "3o Grupo A ________", "3o Grupo D ________", "3o Grupo C ________"};
  char final5g2c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"1o Grupo D ________", "1o Grupo E ________",
"2o Grupo A ________", "2o Grupo E ________", "2o Grupo B ________", 
"2o Grupo C ________", "2o Grupo D ________"};
  char final5g3c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"1o Grupo D ________", "1o Grupo E ________",
"2o Grupo A ________", "2o Grupo E ________", "2o Grupo B ________", 
"2o Grupo C ________", "2o Grupo D ________",
"3o Grupo D ________", "3o Grupo A ________", "3o Grupo E ________", 
"3o Grupo B ________", "3o Grupo C ________",};
  char final6g2c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"1o Grupo D ________", "1o Grupo E ________", "1o Grupo F ________", 
"2o Grupo E ________", "2o Grupo F ________", "2o Grupo B ________", 
"2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________"};
  char final6g3c[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"1o Grupo D ________", "1o Grupo E ________", "1o Grupo F ________", 
"2o Grupo E ________", "2o Grupo F ________", "2o Grupo B ________", 
"2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________",
"3o Grupo A ________", "3o Grupo B ________", "3o Grupo C ________", 
"3o Grupo D ________", "3o Grupo E ________", "3o Grupo F ________"};
  char final7g[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", 
"1o Grupo D ________", "1o Grupo E ________", "1o Grupo F ________", "1o Grupo G ________", 
"2o Grupo B ________", "2o Grupo G ________", "2o Grupo A ________", 
"2o Grupo D ________", "2o Grupo C ________", "2o Grupo F ________", "2o Grupo E ________"};
  char final8g[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", "1o Grupo D ________", 
"1o Grupo E ________", "1o Grupo F ________", "1o Grupo G ________", "1o Grupo H ________", 
"2o Grupo B ________", "2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________", 
"2o Grupo F ________", "2o Grupo E ________", "2o Grupo H ________", "2o Grupo G ________"};
  char final12g[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", "1o Grupo D ________", 
"1o Grupo E ________", "1o Grupo F ________", "1o Grupo G ________", "1o Grupo H ________", 
"1o Grupo I ________", "1o Grupo J ________", "1o Grupo K ________", "1o Grupo L ________", 
"2o Grupo C ________", "2o Grupo D ________", "2o Grupo E ________", "2o Grupo F ________", 
"2o Grupo G ________", "2o Grupo H ________", "2o Grupo A ________", "2o Grupo B ________", 
"2o Grupo J ________", "2o Grupo L ________", "2o Grupo I ________", "2o Grupo K ________"};

  char final16g[][20] = {
"1o Grupo A ________", "1o Grupo B ________", "1o Grupo C ________", "1o Grupo D ________", 
"1o Grupo E ________", "1o Grupo F ________", "1o Grupo G ________", "1o Grupo H ________", 
"1o Grupo I ________", "1o Grupo J ________", "1o Grupo K ________", "1o Grupo L ________", 
"1o Grupo M ________", "1o Grupo N ________", "1o Grupo O ________", "1o Grupo P ________", 
"2o Grupo B ________", "2o Grupo A ________", "2o Grupo D ________", "2o Grupo C ________", 
"2o Grupo F ________", "2o Grupo E ________", "2o Grupo H ________", "2o Grupo G ________", 
"2o Grupo J ________", "2o Grupo I ________", "2o Grupo L ________", "2o Grupo K ________",
"2o Grupo N ________", "2o Grupo M ________", "2o Grupo P ________", "2o Grupo O ________"};
  switch (g)
  {
    case 2:
      if (nc == 2)
        matamata(g * nc, final2g2c);  
      if (nc == 3)
        matamata(g * nc, final2g3c);  
      break;
    case 3:
      if (nc == 2)
        matamata(g * nc, final3g2c);  
      if (nc == 3)
        matamata(g * nc, final3g3c);  
      break;
    case 4:
      if (nc == 2)
        matamata(g * nc, final4g2c);  
      if (nc == 3)
        matamata(g * nc, final4g3c);  
      break;
    case 5:
      if (nc == 2)
        matamata(g * nc, final5g2c);  
      if (nc == 3)
        matamata(g * nc, final5g3c);    
      break;
    case 6:
      if (nc == 2)
        matamata(g * nc, final6g2c);  
      if (nc == 3)
        matamata(g * nc, final6g3c);    
      break;
    case 7:
      matamata(g * nc, final7g);  
      break;
    case 8:
      matamata(g * nc, final8g);  
      break;
    case 12:
      matamata(g * nc, final12g);  
      break;
    case 16:
      matamata(g * nc, final16g);  
      break;
  }
}
