# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 19:36:13 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/15 20:54:25 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys 
import string

def text_analyzer(line: str):
    u = l = p = s = 0
    for c in line:
        u += 1 if c.isupper() else 0
        l += 1 if c.islower() else 0
        p += 1 if c in string.punctuation else 0
        s += 1 if c.isspace() else 0
    print(f"The text contains {len(line)} character(s):",f"- {u} upper letter(s)",
         f"- {l} lower letter(s)", f"- {p} punctuation mark(s)", f"- {s} space(s)", sep = '\n')

