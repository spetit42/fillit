#include "libft.h"

t_list *ft_create_elem(void *content)
{
	t_list *tmp;
 
    if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
        return (NULL);
    if (tmp)
    {
        tmp->content = content;
        tmp->next = NULL;
    }
    return (tmp);
}