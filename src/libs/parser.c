/*
 * parser.c
 *
 *  Created on: 28/05/2013
 *      Author: Alexandre Coelho
 */

#include "../includes/parser.h"
#include "../includes/instrucao.h"

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

const char separatorns[] = " ,.-\t;";


int is_a_diretiva(char* token){
	if (!strcmp(token, "SPACE") || !strcmp(token, "CONST")){
		return TRUE;
	}
	return FALSE;
}

int is_a_minemonic(char* token){

	if ((!strcmp(token, "ADD   ")) || (!strcmp(token, "SUB   "))
			|| (!strcmp(token, "MULT")) || (!strcmp(token, "DIV"))
			|| (!strcmp(token, "JMP")) || (!strcmp(token, "JMPN"))
			|| (!strcmp(token, "JMPP")) || (!strcmp(token, "JMPZ"))
			|| (!strcmp(token, "COPY")) || (!strcmp(token, "LOAD"))
			|| (!strcmp(token, "STORE")) || (!strcmp(token, "INPUT"))
			|| (!strcmp(token, "OUTPUT")) || (!strcmp(token, "STOP"))) {
	return TRUE;
	}

	return FALSE;
}


instruction* decode_diretiva_instruction(char** tokens){
	instruction* inst = (instruction*) malloc(sizeof(instruction));

	return inst;
}


void prepair_instruct_by_minemonic(instruction** _inst){
	instruction* inst;
	inst = *_inst;

	if(!strcmp(inst->mnemonico,"ADD")) { inst->qtd_op = 1; inst->cod = 1 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"SUB")) { inst->qtd_op = 1; inst->cod = 2 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"MULT")) { inst->qtd_op = 1; inst->cod = 3 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"DIV")) { inst->qtd_op = 1; inst->cod = 4 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"JMP")) { inst->qtd_op = 1; inst->cod = 5 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"JMPN")) { inst->qtd_op = 1; inst->cod = 6 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"JMPP")) { inst->qtd_op = 1; inst->cod = 7 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"JMPZ")) { inst->qtd_op = 1; inst->cod = 8 ; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"COPY")) { inst->qtd_op = 2; inst->cod = 9 ; inst->tamanho = 3;}
	if(!strcmp(inst->mnemonico,"LOAD")) { inst->qtd_op = 1; inst->cod = 10; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"STORE")) { inst->qtd_op = 1; inst->cod = 11; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"INPUT")) { inst->qtd_op = 1; inst->cod = 12; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"OUTPUT")) { inst->qtd_op = 1; inst->cod = 13; inst->tamanho = 2;}
	if(!strcmp(inst->mnemonico,"STOP")) { inst->qtd_op = 0; inst->cod = 14; inst->tamanho = 1;}

}

instruction* decode_mnemonic_instruction(char** tokens){
	instruction* inst = (instruction*) malloc(sizeof(instruction));
	char** tokens_tmp;
	int count = 0;

	tokens_tmp = tokens;
	inst->mnemonico = *tokens_tmp;
	prepair_instruct_by_minemonic(&inst);

	int i;
	for(i = 1; i <= inst->qtd_op; i++){
		if (i == 1){
			inst->op1 = *(tokens_tmp + 1);
		}else if(i == 2){
			inst->op2 = *(tokens_tmp + 2);
		}else if(i == 3){
			inst->op2 = *(tokens_tmp + 3);
		}
	}

	inst->qtd_op = count - 1;
	inst->type = 1;


	return inst;
}

instruction* make_instruction(char** tokens){
	if(is_a_minemonic(*tokens)){
		printf("debug: eh um minemonico");
		return decode_mnemonic_instruction(tokens);
	}else if(is_a_diretiva(*tokens)){
		printf("debug: eh um label");
		return decode_diretiva_instruction(tokens);
	}

	return NULL;
}

char* clean_comment(char *str){
	char* str_tmp;
	str_tmp = str;

	while(*str_tmp){
		if (*str_tmp == ';'){
			*str_tmp = '\0';
		}
		str_tmp++;
	}

	return str;
}

instruction* str_to_instrction(char *str1){

	  char* pch;
	  char** all_tokens;
	  char** all_tokens_tmp;

	  printf ("Splitting string \"%s\" into tokens:\n", str1);
	  clean_comment(str1);
	  pch = strtok (str1,separatorns);

	  if (pch != NULL){
		  all_tokens = (char**)malloc(sizeof(char**));
		  all_tokens_tmp = all_tokens;
	  }else {
		  return NULL;
	  }

	  while (pch != NULL)
	  {

		*all_tokens_tmp = pch;
		printf("%s\n", *all_tokens_tmp);
		all_tokens_tmp++;

	    pch = strtok (NULL, separatorns);
	  }

	  *all_tokens_tmp = NULL;
	  // debug

	  all_tokens_tmp = all_tokens;
	  while (*all_tokens_tmp)
	  	  {
		  printf("debug: %s\n", *all_tokens_tmp);
		  all_tokens_tmp++;
	  	  }

	  all_tokens_tmp = NULL;

	  return make_instruction(all_tokens);

}












