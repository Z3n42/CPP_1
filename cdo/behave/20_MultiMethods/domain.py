# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    domain.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:28:05 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:28:13 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# @mark.domain_model
# ------------------------------------------------------------------------
# DOMAIN MODEL:
# ------------------------------------------------------------------------
class Shop(object):
    vegetable_price_list = {
        "cucumbers": 0.2,   # Dollars per piece.
        "lettuce":   0.8,   # Dollars per piece.
    }
    fruit_price_list = {
        "apples":     0.5,  # Dollars per piece.
        "pears":      0.6,  # Dollars per piece.
    }
    common_price_list = {
        "diamonds": 1000.    # Dollars for one with 10 karat (only 1 size).
    }

    def calculate_price_for_fruit(self, fruit, amount):
        price_per_unit = self.fruit_price_list[fruit]
        return price_per_unit*amount

    def calculate_price_for_vegetable(self, vegetable, amount):
        price_per_unit = self.vegetable_price_list[vegetable]
        return price_per_unit*amount

    def calculate_price_for(self, shop_item, amount):
        price_per_unit = self.common_price_list[shop_item]
        return price_per_unit*amount

