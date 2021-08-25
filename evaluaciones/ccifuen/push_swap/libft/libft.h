/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:40:44 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/19 21:26:30 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_flags
{
	int		width;
	int		prec;
	int		zero;
	int		minus;
	int		plus;
	int		sharp;
	int		space;
	int		dot;
	int		num;
	char	type;
}		t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *h, const char *n, size_t l);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long int	ft_atoi(const char *str);
int			ft_isprint(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_count_m(char const *s, char c);
char		**ft_free(char **p, size_t count);;
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void(*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_printf(const char *cpy, ...);
void		ft_putchar(int c);
void		ft_putstr(char *str);
int			ft_print_arg(char *arg, char *fl);
char		*ft_alloc_char(char c);
int			ft_count_hex(uintptr_t n);
char		*ft_alloc_upperx(uintptr_t n);
char		*ft_alloc_hex(uintptr_t n);
char		*ft_alloc_ptr(uintptr_t n);
void		ft_clean(char *fl, char *arg);
char		*ft_flags_info(char *str);
char		ft_check_type(char c);
t_flags		ft_init_flags(void);
t_flags		ft_handle_flags(char *fl, t_flags flags);
void		ft_print_width(t_flags flags, char *arg);
void		ft_print_zeros(t_flags flags, char *arg);
int			ft_get_width(char *str);
t_flags		ft_check_print_num(t_flags flags, char *arg);
t_flags		ft_num_prec(char *arg, t_flags flags);
t_flags		ft_num_zero(char *arg, t_flags flags);
t_flags		ft_print_num(char *arg, t_flags flags);
t_flags		ft_isnum(char *arg, t_flags flags);
char		*ft_itoa_u(unsigned int n);
t_flags		ft_print_arg_char(t_flags flags, char *arg);
t_flags		ft_print_arg_str(t_flags flags, char *arg);
t_flags		ft_print_num(char *arg, t_flags flags);
int			ft_all_digits(char *arg);

#endif