#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - tokenize a string
 *
 * @str: the string
 * @delims: the separating delimiters
 *
 * Return:pointer to tokens
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - confirm if there is a delimiter in the string
 *
 * @ch: the character to check
 *
 * @delims: point to delimiter array
 *
 * Return: success or failure
 */

int is_delim(char ch, char *delims)
{
	int m = 0;

	while (delims[m])
	{
		if (delims[m] == ch)
			return (1);
		m++;
	}
	return (0);
}

/**
 * get_word_length - what is the word length
 *
 * @str: the string
 * @delims: delimiter
 *
 * Return: the length
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, m = 0;

	while (*(str + m))
	{
		if (is_delim(str[m], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[m], delims))
			break;
		m++;
	}
	return (wLen);
}

/**
 * get_word_count - count number of words in a string
 *
 * @str: the string
 * @delims: delimiter
 *
 * Return: the number of words
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - fetch the next word from a string
 *
 * @str: string to get next word from
 * @delims: the delimiters
 *
 * Return: a pointer to the first character of the next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int m = 0;

	while (*(str + m))
	{
		if (is_delim(str[m], delims))
			pending = 1;
		else if (pending)
			break;
		m++;
	}
	return (str + m);
}
