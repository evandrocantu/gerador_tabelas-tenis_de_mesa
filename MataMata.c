//Arquivo MataMata.c

//Programa Gerador de Tabelas Esportivas
//Função matamata utilizada pelo programa principal.

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

//matamata: Função para determinar as partidas de uma eliminatória simples.
//          Recebe como parâmetro o número de jogadores e
//          o vetor com os jogadores
void matamata (int n, char jogadores[32][20])
{
  char tabela[] = "Tabelas.txt";
  FILE *arq;
  arq = fopen(tabela, "a");
  fprintf(arq, "\n+----------------------------------------------------+\n");
  fprintf(arq, "\nPARTIDAS ELIMINATÓRIAS: \n");
  switch (n)
  {
    case 2:
      fprintf(arq, "\n%20s ----+", jogadores[0]);  
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 3:
      fprintf(arq, "\n%18sSF       F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----","");
      fprintf(arq, "\n%20s ----+    |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 4:
      fprintf(arq, "\n%20s   SF    F\n","");
      fprintf(arq, "\n%20s ----+", jogadores[0]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[3]);
      fprintf(arq, "\n%20s          |----","");
      fprintf(arq, "\n%20s ----+    |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 5:
      fprintf(arq, "\n%18sQF        SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----", jogadores[3]);
      fprintf(arq, "\n%20s               | ","");  
      fprintf(arq, "\n%25s ----+    |", jogadores[2]);
      fprintf(arq, "\n%25s     |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 6:
      fprintf(arq, "\n%18sQF        SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[3]);
      fprintf(arq, "\n%20s               |----","");
      fprintf(arq, "\n%20s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[5]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);

      break;
    case 7:
      fprintf(arq, "\n%18sQF        SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[3]);
      fprintf(arq, "\n%20s               |---","");
      fprintf(arq, "\n%20s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[5]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[6]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 8:
      fprintf(arq, "\n%20s   QF   SF    F\n","");
      fprintf(arq, "\n%20s ----+", jogadores[0]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[7]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[3]);
      fprintf(arq, "\n%20s               |----","");
      fprintf(arq, "\n%20s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[5]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[6]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 9:
      //matamata 5
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%25s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+         |----", jogadores[3]);
      fprintf(arq, "\n%25s               |","");
      //matamata 4
      fprintf(arq, "\n%25s ----+         |", jogadores[2]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+    |    |", jogadores[5]);
      fprintf(arq, "\n%25s          |----+","");
      fprintf(arq, "\n%25s ----+    |", jogadores[6]);
      fprintf(arq, "\n%25s     |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 10:
      //matamata 5
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%25s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+         |", jogadores[3]);
      fprintf(arq, "\n%25s               |----","");
      //matamata 5
      fprintf(arq, "\n%25s ----+         |", jogadores[2]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+    |    |", jogadores[5]);
      fprintf(arq, "\n%25s          |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 11:
      //matamata 5
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%25s ----+    |    |", jogadores[4]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+         |", jogadores[3]);
      fprintf(arq, "\n%25s               |----","");
      //matamata 6
      fprintf(arq, "\n%25s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 12:
      //matamata 6
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%25s ----+         |", jogadores[3]);
      fprintf(arq, "\n%20s                    |-----","");  
      //matamata 6
      fprintf(arq, "\n%25s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 13:
      //matamata 7
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[7]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[8]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |         |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+              |-----", jogadores[3]);
      fprintf(arq, "\n%20s                    |","");  
      //matamata 6
      fprintf(arq, "\n%25s ----+         |", jogadores[2]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 14:
      //matamata 7
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |         |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+              |", jogadores[3]);
      fprintf(arq, "\n%20s                    |-----","");  
      //matamata 7
      fprintf(arq, "\n%20s ----+              |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+    |         |", jogadores[13]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 15:
      //matamata 7
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[7]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |         |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+              |", jogadores[3]);
      fprintf(arq, "\n%20s                    |-----","");  
      //matamata 8
      fprintf(arq, "\n%20s ----+              |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+    |         |", jogadores[13]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[14]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 16:
      //matamata 8
      fprintf(arq, "\n%18sOF        QF   SF    F\n","");
      fprintf(arq, "\n%20s ----+", jogadores[0]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[15]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[7]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |         |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+              |", jogadores[3]);
      fprintf(arq, "\n%20s                    |-----","");  
      //matamata 8
      fprintf(arq, "\n%20s ----+              |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+    |         |", jogadores[13]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |", jogadores[6]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[14]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
    case 18:
      //matamata 9
      fprintf(arq, "\n%22s16F   OF   QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[16]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[15]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%25s ----+    |    |", jogadores[8]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+         |----+", jogadores[7]);
      fprintf(arq, "\n%25s               |    |","");
      fprintf(arq, "\n%25s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%25s     |----+    |    |","");
      fprintf(arq, "\n%25s ----+    |    |    |", jogadores[11]);
      fprintf(arq, "\n%25s          |----+    |","");
      fprintf(arq, "\n%25s ----+    |         |", jogadores[12]);
      fprintf(arq, "\n%25s     |----+         |","");
      fprintf(arq, "\n%25s ----+              |", jogadores[3]);
      fprintf(arq, "\n%25s                    |-----","");
      //matamata 9
      fprintf(arq, "\n%25s ----+              |", jogadores[2]);
      fprintf(arq, "\n%25s     |----+         |","");  
      fprintf(arq, "\n%25s ----+    |         |", jogadores[13]);
      fprintf(arq, "\n%25s          |----+    |","");
      fprintf(arq, "\n%25s ----+    |    |    |", jogadores[10]);
      fprintf(arq, "\n%25s     |----+    |    |","");
      fprintf(arq, "\n%25s ----+         |    | ", jogadores[5]);
      fprintf(arq, "\n%25s               |----+","");  
      fprintf(arq, "\n%25s ----+         |", jogadores[6]);
      fprintf(arq, "\n%25s     |----+    |","");
      fprintf(arq, "\n%25s ----+    |    |", jogadores[9]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[14]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[17]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 24:
      //matamata 12
      fprintf(arq, "\n%18s16F       OF   QF   SF    F\n","");
      fprintf(arq, "\n%25s ----+", jogadores[0]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[16]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |----+", jogadores[15]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[23]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%25s ----+         |", jogadores[7]);
      fprintf(arq, "\n%20s                    |----+","");  
      fprintf(arq, "\n%25s ----+         |    |", jogadores[4]);
      fprintf(arq, "\n%20s          |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |    |", jogadores[20]);
      fprintf(arq, "\n%20s     |----+    |    |    |","");
      fprintf(arq, "\n%20s ----+         |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s               |    |    |","");  
      fprintf(arq, "\n%20s ----+         |----+    |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+    |         |","");
      fprintf(arq, "\n%20s ----+    |    |         |", jogadores[19]);
      fprintf(arq, "\n%20s          |----+         |","");
      fprintf(arq, "\n%25s ----+              |", jogadores[3]);
      fprintf(arq, "\n%20s                         |-----","");
      //matamata 12
      fprintf(arq, "\n%25s ----+              |", jogadores[2]);
      fprintf(arq, "\n%20s          |----+         |","");
      fprintf(arq, "\n%20s ----+    |    |         |", jogadores[18]);
      fprintf(arq, "\n%20s     |----+    |         |","");
      fprintf(arq, "\n%20s ----+         |----+    |", jogadores[13]);
      fprintf(arq, "\n%20s               |    |    |","");  
      fprintf(arq, "\n%20s ----+         |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |    |", jogadores[21]);
      fprintf(arq, "\n%20s          |----+    |    |","");
      fprintf(arq, "\n%25s ----+         |    |", jogadores[5]);
      fprintf(arq, "\n%20s                    |----+","");  
      fprintf(arq, "\n%25s ----+         |", jogadores[6]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[22]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[9]);
      fprintf(arq, "\n%20s               |    |","");  
      fprintf(arq, "\n%20s ----+         |----+", jogadores[14]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[17]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%25s ----+\n", jogadores[1]);
      break;
    case 32:
      //matamata 16
      fprintf(arq, "\n%18s16F       OF   QF   SF    F\n","");
      fprintf(arq, "\n%20s ----+", jogadores[0]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[31]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[16]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+         |", jogadores[15]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |    |", jogadores[8]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[23]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |         |", jogadores[24]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+              |", jogadores[7]);
      fprintf(arq, "\n%20s                    |----+","");  
      fprintf(arq, "\n%20s ----+              |    |", jogadores[4]);
      fprintf(arq, "\n%20s     |----+         |    |","");  
      fprintf(arq, "\n%20s ----+    |         |    |", jogadores[27]);
      fprintf(arq, "\n%20s          |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |    |", jogadores[20]);
      fprintf(arq, "\n%20s     |----+    |    |    |","");
      fprintf(arq, "\n%20s ----+         |    |    |", jogadores[11]);
      fprintf(arq, "\n%20s               |----+    |","");  
      fprintf(arq, "\n%20s ----+         |         |", jogadores[12]);
      fprintf(arq, "\n%20s     |----+    |         |","");
      fprintf(arq, "\n%20s ----+    |    |         |", jogadores[19]);
      fprintf(arq, "\n%20s          |----+         |","");
      fprintf(arq, "\n%20s ----+    |              |", jogadores[28]);
      fprintf(arq, "\n%20s     |----+              |","");
      fprintf(arq, "\n%20s ----+                   |", jogadores[3]);
      fprintf(arq, "\n%20s                         |----+","");
      //matamata 16
      fprintf(arq, "\n%20s ----+                   |", jogadores[2]);
      fprintf(arq, "\n%20s     |----+              |","");
      fprintf(arq, "\n%20s ----+    |              |", jogadores[29]);
      fprintf(arq, "\n%20s          |----+         |","");
      fprintf(arq, "\n%20s ----+    |    |         |", jogadores[18]);
      fprintf(arq, "\n%20s     |----+    |         |","");
      fprintf(arq, "\n%20s ----+         |         |", jogadores[13]);
      fprintf(arq, "\n%20s               |----+    |","");  
      fprintf(arq, "\n%20s ----+         |    |    |", jogadores[10]);
      fprintf(arq, "\n%20s     |----+    |    |    |","");
      fprintf(arq, "\n%20s ----+    |    |    |    |", jogadores[21]);
      fprintf(arq, "\n%20s          |----+    |    |","");
      fprintf(arq, "\n%20s ----+    |         |    |", jogadores[26]);
      fprintf(arq, "\n%20s     |----+         |    |","");  
      fprintf(arq, "\n%20s ----+              |    |", jogadores[5]);
      fprintf(arq, "\n%20s                    |----+","");  
      fprintf(arq, "\n%20s ----+              |", jogadores[6]);
      fprintf(arq, "\n%20s     |----+         |","");  
      fprintf(arq, "\n%20s ----+    |         |", jogadores[25]);
      fprintf(arq, "\n%20s          |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |    |", jogadores[22]);
      fprintf(arq, "\n%20s     |----+    |    |","");
      fprintf(arq, "\n%20s ----+         |    | ", jogadores[9]);
      fprintf(arq, "\n%20s               |----+","");  
      fprintf(arq, "\n%20s ----+         |", jogadores[14]);
      fprintf(arq, "\n%20s     |----+    |","");
      fprintf(arq, "\n%20s ----+    |    |", jogadores[17]);
      fprintf(arq, "\n%20s          |----+","");
      fprintf(arq, "\n%20s ----+    |", jogadores[30]);
      fprintf(arq, "\n%20s     |----+","");
      fprintf(arq, "\n%20s ----+\n", jogadores[1]);
      break;
  }
  fclose(arq);
}
