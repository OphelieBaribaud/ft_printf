/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaribau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:48:11 by obaribau          #+#    #+#             */
/*   Updated: 2020/04/26 23:40:30 by ophelieba        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		print_s_justif(char *s, t_flags *flags)
{
	int ret;

	ret = ft_strlen(s);
	if (flags->precision != -1 && flags->precision < ret)
	{
		ft_putnstr(s, flags->precision);
		return (flags->precision);
	}
	ft_putstr(s);
	return (ret);
}

int		print_s_next(t_flags *flags, int precision, char *s, int champs)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (precision != -1 && precision < len)
	{
		while ((flags->zero == 0 || (flags->zero == 1 && flags->justif == 1))
				&& precision++ < champs && ++i)
			ft_putchar(' ');
		while (flags->zero == 1 && precision++ < champs
				&& ++i && flags->justif == 0)
			ft_putchar('0');
	}
	else
	{
		while ((flags->zero == 0 || (flags->zero == 1
				&& flags->justif == 1)) && len < champs-- && ++i)
			ft_putchar(' ');
		while (flags->zero == 1 && len < champs--
				&& ++i && flags->justif == 0)
			ft_putchar('0');
	}
	return (i);
}

int		print_s(va_list args, t_flags *flags)
{
	char*s;
	int	champs;
	int	precision;
	int	ret;
	int	i;

	champs = flags->taille_champs;
	precision = flags->precision;
	s = va_arg(args, char*);
	if (!s)
		s = "(null)";
	if (flags->justif == 1)
		ret = print_s_justif(s, flags);
	i = print_s_next(flags, precision, s, champs);
	if (flags->justif == 0)
		return (print_s_justif(s, flags) + i);
	return (ret + i);
}
