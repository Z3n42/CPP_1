# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 17:33:18 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/26 19:26:27 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pprint

cookbook = {
        'sandwich' : {
                'ingredients' : ['ham', 'bread', 'cheese', 'tomato'],
                'meal' : 'lunch',
                'prep_time' : 10 
                },
        'cake' : {
                'ingredients' : ['flour', 'sugar', 'eggs'],
                'meal' : 'dessert',
                'prep_time' : 60
                },
        'salad' : {
                'ingredients' : ['avocado', 'arugula', 'tomatoes', 'spinach'],
                'meal' : 'lunch',
                'prep_time' : 15
                }
        }

def names(coockbook):
    for key in cookbook.keys():
        print(key);
        
def recipe(coockbook, recipe):
    if recipe in cookbook.keys():
        print(recipe, ':', cookbook[recipe]);
        
def delete(coockbook, recipe):
    if recipe in cookbook.keys():
        cookbook.pop(recipe)
        print(recipe, 'Deleted');

def add(cookbook, name, ingr, typ, time):
    cookbook[name] = {'ingredients': ingr, 'meal': typ, 'prep_time' : time}

def ingredients():
    lst = []
    while True:
        ing = input()
        if not ing:
            break
        lst.append(ing)
    return lst

def time():
    while True:
        print("Enter a preparation time:")
        tm = input()
        if tm.isdigit():
            break
        print("Onty numbers.. Try Again.")
    return (int(tm))

def menu(cookbook):
    print("Enter a name :")
    name = input()
    print("Enter ingredients:")
    ingr = ingredients()
    print("Enter a meal type:")
    typ = input()
    tm = time()
    add(cookbook, name, ingr, typ, tm)

if __name__ == '__main__':
    print(f"{'>':=<10}<", "Parte 2.1", f"{'>':=<50}<")
    names(cookbook)
    print(f"{'>':=<10}<", "Parte 2.2", f"{'>':=<50}<")
    recipe(cookbook, 'cake')
    print(f"{'>':=<10}<", "Parte 2.3", f"{'>':=<50}<")
    pprint.pprint(cookbook)
    delete(cookbook, 'cake')
    print(f"{'>':=<10}<", "Parte 2.4", f"{'>':=<50}<")
    pprint.pprint(cookbook)
    menu(cookbook)
    print(f"{'>':=<10}<", "Parte 3", f"{'>':=<50}<")
    print(f"{'>':=<70}<")
    pprint.pprint(cookbook)

