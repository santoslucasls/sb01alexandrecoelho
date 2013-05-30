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



FILE* open_file(char* file_str) {
	FILE* fp;

	fp = fopen(file_str, "r");
	return fp;
}
