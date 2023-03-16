# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 19:36:13 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/16 20:44:40 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys 
import string

def text_analyzer(line: str):
    '''

    This function counts the number of upper characters, lower characters,
    punctuation and spaces in a given text.
    '''
    u = l = p = s = 0
    for c in line:
        u += 1 if c.isupper() else 0
        l += 1 if c.islower() else 0
        p += 1 if c in string.punctuation else 0
        s += 1 if c.isspace() else 0
    print(f"The text contains {len(line)} character(s):",f"- {u} upper letter(s)",
         f"- {l} lower letter(s)", f"- {p} punctuation mark(s)", f"- {s} space(s)", sep = '\n')

if __name__ == "__main__":
    try:
        assert len(sys.argv) == 2
        text_analyzer(sys.argv[1])
    except:
        print("un mensaje de error.")


