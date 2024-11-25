#include <unistd.h>
/*
#include <fcntl.h>
#include <stdio.h>*/
#define _GNU_SOURCE
       #include <stdio.h>
       #include <stdlib.h>

void	ft_putint(const char *str)
{
	int i = -1;
	while (str[++i])
	{
		printf("int value of str[%d] -- > %d\n", i, str[i]);
	}
}

int	main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	
	if (argc != 2) {
	    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
	    exit(EXIT_FAILURE);
	}
	
	stream = fopen(argv[1], "r");
	if (stream == NULL) {
	    perror("fopen");
	    exit(EXIT_FAILURE);
	}
	
	while ((nread = getline(&line, &len, stream)) != -1) {
	    printf("Retrieved line of length %zd:\n", nread);
	    fwrite(line, nread, 1, stdout);
	}
	ft_putint(line);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

/*

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char **str = (char **)malloc(sizeof(char *) * 1000);
	size_t res  = getline(str, NULL,);	
	ft_putint(*str);
	return 0;
}*/
