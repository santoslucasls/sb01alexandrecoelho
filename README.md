sb01alexandrecoelho
===================
Trabalho 01; softare basico.
aluno: Alexandre coelho

1 Introduc~ao
O trabalho consiste em implementar um metodo de traduc~ao de uma linguagem
de montagem simples para uma representac~ao intermediaria adequada para simulac~ao
em uma arquitetura moderna.
2 Metodo
A linguagem de montagem utilizada sera a linguagem simbolica hipotetica apre-
sentada em sala, consistindo em um conjunto de apenas 14 instruc~oes, com programas
divididos em segmentos de codigo e dados. A linguagem hipotetica n~ao e sensvel ao
caso, n~ao havendo diferenciac~ao entre maiusculas e minusculas. Para cada instruc~ao
da maquina hipotetica, a Tabela 1 abaixo contem o mnem^onico, quantidade de ope-
randos, codigo de operac~ao utilizado na montagem, tamanho em palavras da instruc~ao
montada e uma breve descric~ao da sua utilidade. As linhas nais da tabela denem as
diretivas para alocac~ao de memoria no segmento de dados.
Os identicadores de variaveis e rotulos s~ao limitados em 1000 caracteres e seguem
as regras comuns da linguagem C, sendo compostos por letras, numeros ou o caractere
(underscore) e com a restric~ao de que o primeiro caractere n~ao pode ser um numero.
Por simplicidade, o segmento de dados deve sempre seguir a instruc~ao STOP, como
ilustra o exemplo abaixo:
ROT: INPUT N1
COPY N1, N2 ; comentario qualquer
OUTPUT N2
STOP
N1: SPACE
N2: CONST -0x10
1Instruc~oes
Mnem^onico Operandos Codigo Tamanho Descric~ao
ADD 1 1 2 ACC <- ACC + MEM[OP]
SUB 1 2 2 ACC <- ACC - MEM[OP]
MULT 1 3 2 ACC <- ACC * MEM[OP]
DIV 1 4 2 ACC <- ACC / MEM[OP]
JMP 1 5 2 PC <- OP
JMPN 1 6 2 Se ACC < 0, PC <- OP
JMPP 1 7 2 Se ACC > 0, PC <- OP
JMPZ 1 8 2 Se ACC = 0, PC <- OP
COPY 2 9 3 MEM[OP2] MEM[OP1]
LOAD 1 10 2 ACC <- MEM[OP]
STORE 1 11 2 MEM[OP] <- ACC
INPUT 1 12 2 MEM[OP] <- STDIN
OUTPUT 1 13 2 STDOUT <- MEM[OP]
STOP 0 14 1 Encerrar execuc~ao.
Diretivas
SPACE 0 - 1 Reservar memoria n~ao-inicializada para
armazenamento de uma palavra.
CONST 1 - 1 Reservar memoria para armazena-
mento de uma constante inteira de 16
bits em base decimal ou hexadecimal.
Tabela 1: Intruc~oes e diretivas.
O programa de traduc~ao deve ser capaz de realizar as fases de analise e sntese,
mantendo informac~ao intermediaria armazenada em estruturas de dados e interrom-
pendo a execuc~ao mediante a ocorr^encia de qualquer erro. A escolha apropriada de
estruturas de dados faz parte do escopo do trabalho. O tratamento de erros deve
abranger os aspectos abaixo:
 Erros lexicos causados pela presenca de caracteres invalidos no programa de en-
trada;
 Erros sintaticos causados pela presenca de linhas que desviam por qualquer mo-
tivo da gramatica elementar vista em sala;
 Erros sem^anticos causados por declarac~oes ausentes ou repetidas, desvios condici-
onais e incondicionais para enderecos no segmento de dados, escrita em memoria
reservada para armazenamento de constantes e divis~ao por constantes inicializa-
das com valor zero. Observe que a maioria dos montadores n~ao restringe operan-
dos de desvios ou escritas, mas adotaremos essa restric~ao para ns didaticos.
O programa de traduc~ao deve receber dois argumentos, um arquivo de entrada
contendo um programa em Assembly na linguagem hipotetica e um arquivo de sada
2para armazenar o codigo objeto resultante. O formato do codigo objeto gerado pelo
processo de traduc~ao deve ser a simples concatenac~ao de todos os inteiros de 16 bits
que representam as instruc~oes e seus operandos no segmento de codigo, seguido por
um segmento de dados contendo todas as variaveis e constantes de 16 bits declaradas
no programa de entrada. Por convenc~ao e apesar da diretiva SPACE n~ao garantir a
inicializac~ao de variaveis, utilizaremos o valor 0 para representar as posic~oes de memoria
alocadas com essa diretiva.
O programa de simulac~ao deve receber um unico argumento, o arquivo objeto
gerado pelo programa de traduc~ao. A simulac~ao deve ser capaz de conservar o funci-
onamento correto do programa de entrada e encerrar execuc~ao na primeira ocorr^encia
de uma instruc~ao STOP. Os unicos erros tratados pelo programa de simulac~ao s~ao a
divis~ao por zero e o fornecimento de valores acima do limite de representac~ao para a
instruc~ao INPUT.
3 Avaliac~ao
O prazo de entrega do trabalho e 24 de Maio de 2013. A entrega consistira em:
 Codigo-fonte completo e comentado com instruc~oes de compilac~ao dos programas
de traduc~ao e simulac~ao;
 Programas de exemplo que demonstrem o funcionamento correto dos programas
de traduc~ao e simulac~ao.
A forma de entrega e por e-mail, de prefer^encia utilizando o rotulo [SB]. Todas
as entregas receber~ao mensagem de conrmac~ao. O trabalho pode ser feito individu-
almente ou em dupla e sera premiado o trabalho que obtiver o melhor desempenho
na combinac~ao total do tempo de execuc~ao consumido pelas fases de traduc~ao e si-
mulac~ao. A analise de desempenho sera realizada pelo professor com programas de
benchmarking sucientemente extensos, utilizando o mesmo nvel de otimizac~ao -O2
para a compilac~ao de todos os trabalhos, e apenas se aplicara a trabalhos que produzem
o resultado correto dos programas de benchmarking. Desta forma, a bonicac~ao total
do trabalho e de no maximo 2 pontos, divididos em ate 2 alunos diferentes, a serem
aplicados exclusivamente na primeira prova.
