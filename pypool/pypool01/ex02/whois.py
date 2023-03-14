# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whois.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 20:15:32 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/14 21:15:29 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import sys

try:
    assert len(sys.argv) == 2, "AssertionError: ore than one argument are provided"
    assert sys.argv[1].isdigit(), "AssertionError: argument is not an integer"
    assert int(sys.argv[1]) != 0,  "I'm Zero."
    assert int(sys.argv[1]) % 2 == 0 , "I'm Odd." 
    print("I'm Even.")
except AssertionError as msg:
    print(msg)

