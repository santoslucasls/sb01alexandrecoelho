/*
 * file_helper.h
 *
 *  Created on: 29/05/2013
 *      Author: lucas
 */

#ifndef FILE_HELPER_H_
#define FILE_HELPER_H_

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int decode_file(FILE* fp);

FILE* open_file(char* file_str);

#endif /* FILE_HELPER_H_ */
