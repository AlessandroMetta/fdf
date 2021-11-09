#include "libft.h"

char *ft_strjoin(const char *s1, char const *s2)
{
	char	*str;
	int		c_str;
	int		c_s;

	c_str = 0;
	c_s = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[c_s] != '\0')
		str[c_str++] = s1[c_s++];
	c_s = 0;
	while (s2[c_s] != '\0')
		str[c_str++] = s2[c_s++];
	str[c_str] = '\0';
	return (str);
}
