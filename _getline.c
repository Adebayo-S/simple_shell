#include "shell.h";

char *_getline(void)
{
	int buffer_size = 2048;
	char *mem = malloc(buffer_size * sizeof(char));
	int _size = 0;
	char single_val;

	if (mem == NULL)
	{
		fprintf(stderr, "error: memory creation failed\n");
		exit(EXIT_FAILURE);
	}
	
	/*Each character inputted*/
	single_val = getchar();

	while (single_val != '\n')
	{
		/* did user enter ctrl+d ?*/
		if (single_val == EOF)
		{
			free(mem);
			return NULL;
		}

		/* allocate more memory for input if exceeded */
		if (input_size >= buffer_size)
		{
			buffer_size = 2 * buffer_size;
			mem = realloc(mem, buffer_size);
		}

		mem[input_size++] = single_val;
	}

    mem[input_size] = '\0';
    return mem;
}