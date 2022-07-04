# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    use_multi_methods.feature                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:23:59 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 17:24:17 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:step_matcher.features/use_multi_methods.feature
Feature: Use Multi-Methods in Step Definitions
  Scenario:
    Given I go to a shop
    When I buy 2 cucumbers
     And I buy 3 apples
     And I buy 4 diamonds

