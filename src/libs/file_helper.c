/*
 * file_helper.c

 *
 *  Created on: 29/05/2013
 *      Author: Alexandre Coelho
 */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/parser.h"
#include <string.h>

#define TRUE 1

void format_line(char** line){
	char* pch = *line;
	while(*pch){
		if(*pch == '\r')
			*pch = '\0';
		pch++;
	}

}

int decode_file(FILE* fp) {
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int opc = 0;
	instruction** inst_list;

	inst_list = (instruction**)malloc(sizeof(instruction**));
	instruction** inst_list_tmp = inst_list;
	instruction* current_inst;

	while ((read = getline(&line, &len, fp)) != -1) {
		format_line(&line);
		current_inst = str_to_instrction(line);
		*inst_list_tmp = current_inst;
		current_inst->addr = opc;
		current_inst->label_code->label_addr = opc;
		opc = opc + current_inst->tamanho;

		printf("mm %s, op1 %s, op2 %s, op3 %s, label %s, end %d \n\n", current_inst->mnemonico, current_inst->op1, current_inst->op2, current_inst->op3, current_inst->label_code->label_name, current_inst->addr);

		inst_list_tmp++;
	}
	inst_list_tmp = NULL;
	if (line)
		free(line);

	return TRUE;
}

FILE* open_file(char* file_str) {
	FILE* fp;

	fp = fopen(file_str, "r");
	return fp;
}
