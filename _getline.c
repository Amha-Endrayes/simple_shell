
#include "main.h"

/**
* _getline - Read The Input By User From Stdin
* Return: Input
*/
char *_getline()
{
int i, buffsize = BUFSIZE, rd;
char c = 0;
char *_buffer = malloc(buffsize);

	if (_buffer == NULL)
	{
		free(_buffer);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(_buffer);
			exit(EXIT_SUCCESS);
		}
		_buffer[i] = c;
		if (_buffer[0] == '\n')
		{
			free(_buffer);
			return ("\0");
		}
		if (i >= buffsize)
		{
			_buffer = _realloc(_buffer, buffsize, buffsize + 1);
			if (_buffer == NULL)
			{
				return (NULL);
			}
		}
	}
	_buffer[i] = '\0';
	removeComments(_buffer);
	return (_buffer);
}

/**
 * removeComments - remove everything after #
 * @_buffer: input;
 * Return:void
 */
void removeComments(char *_buffer)
{
	int i;

		for (i = 0; _buffer[i] != '\0'; i++)
		{
			if (_buffer[i] == '#')
			{
			_buffer[i] = '\0';
			break;
			}
	}
}
