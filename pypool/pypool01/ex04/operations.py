# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:45:00 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/16 21:23:36 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import sys

def operations(A:int, B:int):
    '''
    Usage: python operations.py <number1> <number2>
    '''
    # try:
    print(f"{'Sum:':<12}", (A+B))
    # except 
    #     print("ERROR")

if __name__ == "__main__":
    operations(int(sys.argv[1]), int(sys.argv[2]))
