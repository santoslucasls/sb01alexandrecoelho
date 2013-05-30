/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/parser.h"
#include "includes/file_helper.h"
#include "includes/sb_util.h"

instruction** inst_list;
pair_label_code_addr** table_simbol_code;


void add_to_table_simbol_code(pair_label_code_addr* label){
	label->next = NULL;

	pair_label_code_addr *label_tmp;
	if(*table_simbol_code == NULL){
		*table_simbol_code = label;
		label->next = NULL;

		return;
	}

	label_tmp = *table_simbol_code;

	while(label_tmp->next){
		label_tmp = label_tmp->next;
	}

	label_tmp->next = label;
}

int decode_file(FILE* fp) {
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int opc = 0;

	instruction* current_inst;
	instruction* old_inst;

	old_inst = NULL;
	while ((read = getline(&line, &len, fp)) != -1) {
		format_line(&line);
		if(strcmp(line,"\0")){


			current_inst = str_to_instrction(line);
			current_inst->addr = opc;


			if(current_inst->label_code->label_name != NULL){
				current_inst->label_code->label_addr = opc;
				add_to_table_simbol_code(current_inst->label_code);
			}

			if(*inst_list == NULL){
				*inst_list = current_inst;
			}else{
				old_inst->next = current_inst;
			}

			old_inst = current_inst;
			opc = opc + current_inst->tamanho;
			current_inst->next = NULL;
		}

	}

	current_inst = *inst_list;

	printf("*********instrucoes decodificadas****************\n");
	while(current_inst){
		printf("mm %s, op1 %s, op2 %s, op3 %s, label %s, end %d \n", current_inst->mnemonico, current_inst->op1, current_inst->op2, current_inst->op3, current_inst->label_code->label_name, current_inst->addr);
		current_inst = current_inst->next;
	}

	pair_label_code_addr *label_tmp;
	label_tmp = *table_simbol_code;
	printf("*********tabela de sinbulos****************\n");
	while(label_tmp){
		printf("Nome: %s, end: %d\n", label_tmp->label_name, label_tmp->label_addr);

		label_tmp = label_tmp->next;
	}

	if (line)
		free(line);

	return TRUE;
}

void innit_lists(){
	inst_list = (instruction**)malloc(sizeof(instruction**));
	*inst_list = NULL;

	table_simbol_code = (pair_label_code_addr**)malloc(sizeof(pair_label_code_addr*));
	*table_simbol_code = NULL;
}

int main ()
{
	FILE * fp;
	fp = open_file("/Users/lucas/prog_in");

	if (fp == NULL )
		exit(EXIT_FAILURE);

	innit_lists();

	if (decode_file(fp)) {

		return EXIT_SUCCESS;
	}

  return 0;
}
