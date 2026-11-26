

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"



int main(void)
{
    int fd;
    fd = open("openfile.txt", O_RDONLY);
    if (fd < 0)
        return (1);
	{
		char *f = get_next_line(fd);
		printf("%s", f);
		free(f);
	}
	//printf("%s", get_next_line(fd));


	// char *line;
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }

    close(fd);
    return (0);
}



