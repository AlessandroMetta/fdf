#include "fdf.h"

int alloc_line(char ***new, char **line)
{
	int	count_word;
	int	i;

	i = 0;
	count_word = dim_line(line);
	*new = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!(*new))
		return (1);
	while (i < count_word)
	{
		(*new)[i] = ft_strdup(line[i]);
		i++;
	}
	(*new)[i] = NULL;
	return (0);
}

/*
** alloco il contenitore (formato da varie linee) + 1 (NULL)
** alloco quante parole contiene ogni linea + 1 (NULL)
** allocco la parola
** alloco la nuova linea e le nuove parole come precedentemnte fatto
*/
char ***reallocate_map(char ***map, int prev_dim, char **line)
{
	char	***new;
	int	i_line;

	i_line = 0;
	new = (char ***)malloc(sizeof(char **) * (prev_dim + 1));
	if (!new)
		return (NULL);
	while (i_line < prev_dim)
	{
		if (alloc_line(&new[i_line], map[i_line]))
			return (NULL);
		free_split(map[i_line]);
		i_line++;
	}
	if(alloc_line(&new[i_line], line))
		return (NULL);
	new[prev_dim + 1] = NULL;
	free(map);
	return (new);
}
