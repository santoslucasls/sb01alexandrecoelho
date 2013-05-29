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

typedef struct label_code {
	char* label_name;
	int label_addr;
} pair_label_code_addr;

typedef struct label_data {
	char* label_name;
	int label_addr;
} pair_label_data_addr;


typedef struct instrucao_tipica {
	char* str_linha;
	char* mnemonico;
	char* op1;
	char* op2;
	char* op3;
	int* cod;
	int tamanho;
	int qtd_op;
	int addr;
	int type;

	pair_label_code_addr* label_code;
	pair_label_data_addr* label_data;

} instruction;



instruction* str_to_instrction(char *str);




#endif /* PARSER_H_ */
