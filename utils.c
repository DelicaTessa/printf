/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 09:53:39 by tclement      #+#    #+#                 */
/*   Updated: 2020/08/26 13:01:21 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isalpha_percent(int arg)
{
	if ((arg >= 'a' && arg <= 'z') || (arg == '%'))
		return (1);
	else if (arg >= 'A' && arg <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_ispositive(int arg)
{
	if (arg >= '1' && arg <= '9')
		return (1);
	else
		return (0);
}
