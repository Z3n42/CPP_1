# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cardinality.one_or_more.feature                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 14:49:06 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 14:49:20 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:datatype.features/cardinality.one_or_more.feature
Feature: Data Type with Cardinality one or more (MANY, List<T>)

  Scenario: Many list, comma-separated
    Given I go to a meeting
    When I meet Alice, Bob, Dodo
    And  I meet Charly
    Then the following persons are present:
      | name   |
      | Alice  |
      | Bob    |
      | Charly |
      | Dodo   |

  Scenario: Many list with list-separator "and"
    Given I go to a meeting
    When I meet Alice and Bob and Charly
    Then the following persons are present:
      | name   |
      | Alice  |
      | Bob    |
      | Charly |
