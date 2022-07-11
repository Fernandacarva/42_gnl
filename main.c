#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}
