# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 20:27:12 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/13 21:26:35 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

try:
    arg = sys.argv[1]
    string = ' '.join(sys.argv[1:])
    print(string[::-1].swapcase())
except IndexError:
    raise SystemExit(f"Usage: {sys.argv[0]} <string_to_reverse>")
