# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cardinality.zero_or_one.feature                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 14:40:33 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 14:40:49 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:datatype.features/cardinality.zero_or_one.feature
Feature: Data Type with Cardinality 0..1 (Optional Part)

  Scenario: Case1 "When attacked by a ..."
    Given the ninja has a black-belt
    When attacked by a samurai

  Scenario: Case2 "When attacked by ..."
    Given the ninja has a black-belt
    When attacked by Chuck Norris

# -- DESCRIPTION:
# "When attacked by ...": Once with "a ", once without it.
# Only one step should be used.
