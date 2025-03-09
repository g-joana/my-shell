#include "minishell.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	substr = malloc ((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	get_tabsize(char const *s, char *c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (ft_strchr(c, s[i]))
		i++;
	while (s[i])
	{
		if ((ft_strchr(c, s[i]) && ft_strchr(c, s[i - 1]) || (s[i + 1] == '\0' && !ft_strchr(c, s[i]))))
			size++;
		i++;
	}
	return (size);
}

static int	get_substr_len(const char *s, char *c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (ft_strchr(c, s[len]))
			break ;
		len++;
	}
	return (len);
}

static char	**split_tab(char **split, const char *s, char *c)
{
	int	tabsize;
	int	itab;
	int	istart;
	int	slen;

	istart = 0;
	itab = 0;
	tabsize = get_tabsize(s, c);
	while (itab < tabsize && s[istart])
	{
		while (ft_strchr(c, s[istart]))
		{
			istart++;
			slen++;
		}
		slen = get_substr_len(&s[istart], c);
		split[itab] = ft_substr(s, istart, slen);
		istart += slen;
		itab++;
	}
	split[itab] = NULL;
	return (split);
}

char	**lexer(char const *s, char *c)
{
	int		tabsize;
	char	**tab;

	if (s == NULL)
		return (NULL);
	tabsize = get_tabsize(s, c);
	tab = (char **) malloc ((tabsize + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	split_tab(tab, s, c);
	return (tab);
}
