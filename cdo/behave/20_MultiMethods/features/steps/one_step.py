# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    one_step.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:24:51 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:32:26 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- FILE: step_matcher.features/steps/one_step.py
from behave import given, when, then

@when("I buy {amount:n} {shop_item:w}")
def step_when_I_buy_shop_item(context, amount, shop_item):
    pass    # -- HERE comes the logic how to distinguish the cases.
