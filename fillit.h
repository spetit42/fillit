#ifndef FILLIT_H
#define FILLIT_H
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <stdio.h> 

typedef struct 	s_map
{
	int 		size;
	char 		**array;
}				t_map;
#endif