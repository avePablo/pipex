#include "pipex.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static char	*d_less_len(char *dest, const char *s, unsigned int start,
		size_t len)
{
	size_t	d;

	d = 0;
	while (d < len)
	{
		dest[d] = s[start + d];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	d_less_len(dest, s, start, len);
	return (dest);
}
