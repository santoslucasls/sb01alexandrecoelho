/*
 * sb_util.c
 *
 *  Created on: 28/05/2013
 *      Author: Alexandre Coelho
 */
#include "../includes/sb_util.h"

#include "../includes/instrucao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void trim(char **str) {
	size_t len = 0;
	char *frontp = *str - 1;
	char *endp = NULL;

	if (*str == NULL )
		return;

	if (*str[0] == '\0')
		return;

	len = strlen(*str);
	endp = *str + len;

	while (isspace(*(++frontp)));
	while (isspace(*(--endp)) && endp != frontp);

	if (*str + len - 1 != endp)
		*(endp + 1) = '\0';
	else if (frontp != *str && endp == frontp)
		*str = '\0';

	endp = *str;
	if (frontp != *str) {
		while (*frontp)
			*endp++ = *frontp++;
		*endp = '\0';
	}
}

void clean_comment(char **line) {
	char* str_tmp;
	str_tmp = *line;

	while (*str_tmp) {
		if (*str_tmp == ';') {
			*str_tmp = '\0';
			break;
		}
		str_tmp++;
	}
}


void clean_exedentchar(char** line){
	char* pch = *line;
	while (*pch) {
		if (*pch == '\r')
			*pch = '\0';
		pch++;
	}
}

void format_line(char** line) {
	clean_exedentchar(line);
	clean_comment(line);
	trim(line);
}

