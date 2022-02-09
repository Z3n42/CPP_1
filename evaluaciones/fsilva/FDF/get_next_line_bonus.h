/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:29:04 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/06 12:36:16 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 80

typedef struct s_node
{
	char			*data;
	int				key;
	struct s_node	*next;
}					t_node;

char	*get_next_line(int fd);
int		ft_lenchr(const char *s, char c);
char	*ft_strjoin_gnl(char **tmp1, char *buf);
char	*ft_subs_gnl(char **s, int start, int len, int s_free);
char	*check_nl(char **tmp1, t_node **head, int fd);
char	*process_file(char **tmp1, int ret[2], char **buf, t_node **head);
int		add_new_node(t_node **head, char **data, int key);
char	*del_node_key(t_node **head, int key);

#endif
