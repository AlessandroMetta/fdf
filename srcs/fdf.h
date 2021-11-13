#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

void free_map(char ***map);
int dim_line(char **line);
void free_split(char **l_split);
void print_map(char ***map);
char ***reallocate_map(char ***map, int prev_dim, char **line);

#endif
