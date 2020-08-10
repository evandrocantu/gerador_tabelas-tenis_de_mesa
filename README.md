# gerador_tabelas-tenis_de_mesa

PROGRAMA GERADOR DE TABELAS ESPORTIVAS

Este software permite a geração de tabelas esportivas para organizar competições em diferentes formatos, incluindo:
-> Copa (fase de grupos seguido de eliminatória simples);
-> Rodízio simples (todos contra todos);
-> Eliminatória simples (mata mata).

No formato copa o programa aceita até 80 competidores, organizados em até 16 grupos. No formato eliminatória simples o programa pode organizar confrontos com 2 a 16 jogadores ou 24 ou 32. No formato rodízio simples o programa aceita qualquer número de jogadores.

UTILIZAÇÃO DO PROGRAMA

Entrada dos jogadores:
O cadastro de jogadores (ou equipes) deve ser realizado através de um arquivo de texto, um nome em cada linha. Os nomes podem ter até 20 caracteres, sem acentos ou espaços.

Caso haja um ranking dos jogadores para orientar a formação das tabelas para eliminatórias simples ou para composição de grupos no formato copa, a ordem dos jogadores no arquivo deve seguir a ordem do ranking.

EXECUÇÃO DO PROGRAMA

A execução do programa deve ser feira em um terminal de comandos, no caso do sistema Linux, passando como parâmetro o arquivo com os jogadores cadastrados.

./GeradorTabelas Jogadores.txt

No caso so sistema Windows, deve-se clicar duas vezes no programa executável e será solicitado o nome do arquivo com os jogadores.

O programa solicita ao usuário as opções quanto ao formato das competições e orienta as escolhas em função do número de competidores.

TABELAS DA COMPETIÇÃO

O programa gera como saída o arquivo Tabelas.txt, que contém os confrontos entre os jogadores.

Caso a escolha tenha sido o formato copa, o programa gera os confrontos da fase de grupos e os confrontos das partidas eliminatórias.

O arquivo Tabelas.txt pode ser editado com os resultados das competições.

COMPILAÇÃO DO PROGRAMA

O software foi desenvolvido em linguagem C.

O código fonte do programa está organizado em três arquivos, disponibilizados abaixo:

GeradorTebelas.c
Copa.c
MataMata.c

Para gerar o programa executável, os arquivos fonte devem ser compilados com o comando:

gcc GeradorTabelas.c Copa.c MataMata.c -o GeradorTabelas

