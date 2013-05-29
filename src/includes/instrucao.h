/*
 * instrucao.h
 *
 *  Created on: 28/05/2013
 *      Author: aexandre coelho
 */

/*
Mnem^onico Operandos Codigo Tamanho 		Descric~ao
ADD 		1 			1 		2 		ACC <- ACC + MEM[OP]
SUB 		1 			2 		2 		ACC <- ACC - MEM[OP]
MULT 		1 			3 		2 		ACC <- ACC * MEM[OP]
DIV 		1 			4 		2 		ACC <- ACC / MEM[OP]
JMP 		1 			5 		2 		PC <- OP
JMPN 		1 			6 		2 		Se ACC < 0, PC <- OP
JMPP 		1 			7 		2 		Se ACC > 0, PC <- OP
JMPZ 		1 			8 		2 		Se ACC = 0, PC <- OP
COPY 		2 			9 		3 		MEM[OP2] MEM[OP1]
LOAD 		1 			10 		2 		ACC <- MEM[OP]
STORE 		1 			11 		2 		MEM[OP] <- ACC
INPUT 		1 			12 		2 		MEM[OP] <- STDIN
OUTPUT 		1 			13 		2 		STDOUT <- MEM[OP]
STOP 		0 			14 		1 		Encerrar execuc~ao.

Diretivas

SPACE 0 - 1 Reservar memoria n~ao-inicializada para
armazenamento de uma palavra.

CONST 1 - 1 Reservar memoria para armazena-
mento de uma constante inteira de 16
bits em base decimal ou hexadecimal.

 * */


#ifndef INSTRUCAO_H_
#define INSTRUCAO_H_



#endif /* INSTRUCAO_H_ */
