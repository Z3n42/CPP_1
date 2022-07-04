# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    calculator.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 13:09:06 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 13:09:21 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:features/steps/calculator.py
# -----------------------------------------------------------------------------
# DOMAIN-MODEL:
# -----------------------------------------------------------------------------
class Calculator(object):

    def __init__(self, value=0):
        self.result = value

    def reset(self):
        self.result = 0

    def add2(self, x, y):
        self.result += (x + y)
        return self.result
