# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:45:00 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/17 20:38:45 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import sys
import math

def operations(A:int, B:int):
    '''
    Usage: python operations.py <number1> <number2>
    '''
    print(f"{'Sum:':<12}", (A+B))
    print(f"{'Diferences:':<12}", (A-B))
    print(f"{'Product:':<12}", (A*B))
    try:
        print(f"{'Quotient:':<12}", f"{(A/B):.4f}...")
    except ZeroDivisionError as msg:
        print(f"{'Quotient:':<12}", "ERROR", f"({msg})")
    try:
        print(f"{'Reminder:':<12}", (A%B))
    except ZeroDivisionError as msg:
        print(f"{'Reminder:':<12}",  "ERROR", f"({msg})")

if __name__ == "__main__":
    try:
        operations(int(sys.argv[1]), int(sys.argv[2]))
    except: 
        print operations.__doc__
