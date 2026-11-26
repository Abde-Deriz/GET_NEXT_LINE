#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"


typedef struct Point
{
	int x, y;
}Point;


#include <fcntl.h>

// void fchar()
// {
// 	FILE *f= fopen("file.txt","r+");

// 	perror("fopen");
// 	printf("  fileno  %i", fileno(f));
// 	char buf[10] ;
// 	size_t n = fread(buf,1 ,10, f);
// 	buf[n] = '\0';
// 	printf("\nread from buf :    %s", buf);
// }

// void  fwriteint(void) {
//     int data[5] = {10, 20, 30, 40, 50};
//     FILE *f = fopen("file.txt", "wb");
//     fwrite(data, sizeof(int), 5, f);
//     fclose(f);
// }

// int main()
// {
// 	fwriteint();
// 	FILE *f= fopen("file.txt","r+");

// 	perror("fopen");
// 	printf("  fileno  %i", fileno(f));
// 	int buf[10] ;
// 	size_t n = fread(buf,sizeof(int) ,10, f);
// 	printf("read %zu values : ", n);
// 	perror("printf");

// 	size_t i = 0;
// 	while ( n -- != 0)
// 	{
// 		printf("\nread from buf :    %i", buf[i]);
// 		i++;
// 	}
// 	fclose(f);
// 	return (0);
// }

int main(void)
{
	// remove("missing.txt");
	// sleep(2);
   // int fd = open("missing.txt", O_RDONLY);
	//rename("file.txt", "openfile.txt");
    // if (fd == -1)
    // {
    //     printf("errno = %s\n", strerror(errno));
    //     perror("open");
    // }

	// FILE *file = fopen("openfile.txt", "a+");
	// fprintf(file, "some test writing on file");
	// perror("fprintf");
	// fflush(file); 
	// ftruncate(fileno(file), 0);
	// fclose(file);

	char  *s1 = "hello";
	char  *s2 = "hello";
	printf("%s", strjoin(s1,s2));

}


// first version
char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *result;
    ssize_t bytes_read;
    int i = 0;

    result[0] = '\0';

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';

        i = 0;
        while (i < bytes_read)
        {
            result[strlen(result)] = buffer[i];
            result[strlen(result) + 1] = '\0';

            if (buffer[i] == '\n')
                return (result);
            i++;
        }
    }

    if (result[0])
        return (result);
    return (NULL);
}