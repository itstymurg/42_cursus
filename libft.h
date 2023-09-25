/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:21:53 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/30 06:06:31 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

unsigned int	ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_isalnum(int n);
int				ft_isalpha(int n);
int				ft_isascii(int n);
int				ft_isdigit(int n);
int				ft_isprint(int n);
void			*ft_memchr(const void *str, int chr, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t num);
void			*ft_memcpy(void *s1, const void *s2, unsigned int n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *p, int c, unsigned int n);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strnstr(const char *str,
					const char *buscar, size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_tolower(int n);
int				ft_toupper(int n);
char			*ft_itoa(long int number);
char			**ft_split(char const *s, char c);

#endif