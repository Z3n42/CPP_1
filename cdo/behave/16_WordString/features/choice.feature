# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    choice.feature                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 16:33:28 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 16:39:29 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:datatype.features/choice.feature
Feature: User-Defined Choice Type

    | The user-defined choice type supports only the following
    | choice of words:  apples, beef, potatoes, pork

    Scenario: Good Case
        Given I go to a shop to buy ingredients for a meal
        When I buy apples
         And I buy beef

    @xfail
    Scenario: Bad Case -- Undefined step definition for "diamonds"
        Given I go to a shop to buy ingredients for a meal
        When I buy apples
         And I buy pork
         And I buy diamonds
