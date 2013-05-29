/*
 * parser.h
 *
 *  Created on: 28/05/2013
 *      Author: lucas
 */

#ifndef PARSER_H_
#define PARSER_H_


#define TIPO_DE_INSTR_NORMAL = 0
#define TIPO_DE_INSTR_DIRTVA = 1





typedef struct instrucao_tipica {
	char* str_linha;
	char* mnemonico;
	char* op1;
	char* op2;
	char* op3;
	int* cod;
	int tamanho;
	int qtd_op;

	int type;

} instruction;

instruction* str_to_instrction(char *str);

#endif /* PARSER_H_ */
