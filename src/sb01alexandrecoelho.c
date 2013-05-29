/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/parser.h"
#include "includes/file_helper.h"


int main ()
{
	FILE * fp;
	fp = open_file("/Users/lucas/prog_in");

	if (fp == NULL )
		exit(EXIT_FAILURE);
	if (decode_file(fp)) {

		return EXIT_SUCCESS;
	}

  return 0;
}
