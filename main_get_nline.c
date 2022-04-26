#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int	fd2;

	fd1 = open("texts/text3.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
	 	line = get_next_line(fd1);
	 	printf("line main: [%02d]: %s\n", i, line);
	 	free(line);
		line = get_next_line(fd2);
	 	printf("line02 [%02d]: %s\n", i, line);
	 	free(line);
	 	i++;
	}
	close(fd1);
	return (0);
}









