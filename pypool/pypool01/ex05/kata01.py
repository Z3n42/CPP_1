# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    kata01.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 13:26:13 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/25 14:02:12 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

kata = {
'Python': 'Guido van Rossum',
'Ruby': 'Yukihiro Matsumoto',
'PHP': 'Rasmus Lerdorf',
}

if __name__== "__main__":
    print(f"{'>':=<40}<")
    for lang in kata.items():
        print (lang[0], "was created by", lang[1])
    print(f"{'>':=<40}<")
    for lang in kata.items():
        print (f"{lang[0]} was created by {lang[1]}")
    print(f"{'>':=<40}<")
    for key, value in kata.items():
        print (f"{key} was created by {value}")
    print(f"{'>':=<40}<")
