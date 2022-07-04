# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 16:47:24 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 16:50:17 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- FILE: features/environment.py (location 1, global types)
#    FILE: features/steps/step.py  (location 2, more locally used types)
# ------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ------------------------------------------------------------------------
from behave import register_type
from parse_type import TypeBuilder

# -- CHOICE2: Constrain to a list of supported items (as string).
offered_shop_items = [ "apples", "beef", "potatoes", "pork" ]
parse_shop_item2 = TypeBuilder.make_choice2(offered_shop_items)
register_type(ShopItem2=parse_shop_item2)

# -- FILE: features/steps/step.py
# ------------------------------------------------------------------------
# STEPS:
# ------------------------------------------------------------------------
from behave import given, when, then

@given("I buy {shop_item:ShopItem2}")
def step_impl(context, shop_item):
    # EXAMPLE: "potatoes" => (selected_index=2, selected_text="potatoes")
    selected_index, selected_text = shop_item
    assert 0 <= select_index < len(offered_shop_items)
    shop_item_id = context.shop.shop_item_index2id(selected_index)
    context.shopping_cart.append(shop_item_id)

# file:datatype.features/steps/step_choice.py
# ------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ------------------------------------------------------------------------
from behave import register_type
from parse_type import TypeBuilder

# -- CHOICE: Constrain to a list of supported items (as string).
offered_shop_items = [ "apples", "beef", "potatoes", "pork" ]
parse_shop_item = TypeBuilder.make_choice(offered_shop_items)
register_type(ShopItem=parse_shop_item)

# file:datatype.features/steps/step_choice.py
# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave import given, when, then

@given(u"I go to a shop to buy ingredients for a meal")
def step_given_I_go_to_a_shop(context):
    context.shopping_cart = [ ]

@when(u"I buy {shop_item:ShopItem}")
def step_when_I_buy(context, shop_item):
    assert shop_item in offered_shop_items
    context.shopping_cart.append(shop_item)
