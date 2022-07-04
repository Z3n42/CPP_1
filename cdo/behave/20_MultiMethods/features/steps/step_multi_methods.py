# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step_multi_methods.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:25:31 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:32:37 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:step_matcher.features/steps/step_multi_methods.py
# ------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ------------------------------------------------------------------------
from behave import register_type
from parse_type import TypeBuilder

parse_vegetable = TypeBuilder.make_choice(["cucumbers", "lettuce"])
register_type(Vegetable=parse_vegetable)

parse_fruit = TypeBuilder.make_choice(["apples", "pears"])
register_type(Fruit=parse_fruit)

# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave import given, when, then
from domain import Shop

@given(u"I go to a shop")
def step_given_I_go_to_a_shop(context):
    context.shop = Shop()
    context.shopping_cart = [ ]

# -- STEP-ORDERING-IMPORTANT: Else step must be last.
@when(u"I buy {amount:n} {vegetable:Vegetable}")
def step_when_I_buy_vegetable(context, amount, vegetable):
    price = context.shop.calculate_price_for_vegetable(vegetable, amount)
    context.shopping_cart.append((vegetable, amount, price))

@when(u"I buy {amount:n} {fruit:Fruit}")
def step_when_I_buy_fruit(context, amount, fruit):
    price = context.shop.calculate_price_for_fruit(fruit, amount)
    context.shopping_cart.append((fruit, amount, price))

@when(u"I buy {amount:n} {anything_else:w}")
def step_when_I_buy_anything_else(context, amount, anything_else):
    price = context.shop.calculate_price_for(anything_else, amount)
    context.shopping_cart.append((anything_else, amount, price))
