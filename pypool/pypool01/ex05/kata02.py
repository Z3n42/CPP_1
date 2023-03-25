# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata02.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 14:02:24 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/25 14:39:14 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import datetime

kata = (2019, 9, 25, 3, 30)

if __name__=='__main__':
    a = datetime.datetime(*kata)
    print(f"{'>':=<15}<")
    print(f"{a.day}/0{a.month}/{a.year} 0{a.hour}:{a.minute}")
    print(f"{'>':=<15}<")
    print(f"0{a.month}/{a.day}/{a.year} 0{a.hour}:{a.minute}")
    print(f"{'>':=<15}<")
    print(a.strftime("%m/%d/%Y %H:%M"))
    print(f"{'>':=<15}<")
    print(datetime.datetime(*kata).strftime("%m/%d/%Y %H:%M"))
    print(f"{'>':=<15}<")
