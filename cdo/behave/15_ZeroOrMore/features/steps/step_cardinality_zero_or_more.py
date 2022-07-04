# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step_cardinality_zero_or_more.py                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 15:08:56 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 15:10:07 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:datatype.features/steps/step_cardinality_zero_or_more.py
# ------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ------------------------------------------------------------------------
from behave import register_type
from parse_type import TypeBuilder

def slurp_space(text):
    return text
slurp_space.pattern = r"\s*"
register_type(slurp_space=slurp_space)

parse_color = TypeBuilder.make_choice([ "red", "green", "blue", "yellow" ])
register_type(Color=parse_color)

# -- MANY-TYPE: Persons := list<Person> with list-separator = "and"
# parse_colors = TypeBuilder.with_many0(parse_color, listsep="and")
parse_colors0A= TypeBuilder.with_zero_or_more(parse_color, listsep="and")
register_type(OptionalColorAndMore=parse_colors0A)

# -- NEEDED-UNTIL: parse_type.cfparse.Parser is used by behave.
parse_colors0C = TypeBuilder.with_zero_or_more(parse_color)
type_dict = {"Color*": parse_colors0C}
register_type(**type_dict)

# file:datatype.features/steps/step_cardinality_zero_or_more.py
# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave import given, when, then

# -- MANY-VARIANT 1: Use Cardinality field in parse expression (comma-separated)
@when(u'I paint with{:slurp_space}{colors:Color*}')
def step_when_I_paint_with_colors(context, _, colors):
    for color in colors:
        context.used_colors.add(color)

# -- MANY-VARIANT 2: Use special many data type ("and"-separated)
@when(u'I paint with{:slurp_space}{colors:OptionalColorAndMore}')
def step_when_I_paint_with_color_and_more(context, _, colors):
    for color in colors:
        context.used_colors.add(color)


# ----------------------------------------------------------------------------
# MORE STEPS:
# ----------------------------------------------------------------------------
from hamcrest import assert_that, contains, has_length

@given('I am a painter')
def step_given_I_am_a_painter(context):
    context.used_colors = set()

@then('no colors are used')
def step_then_no_colors_are_used(context):
    assert_that(context.used_colors, has_length(0))

@then('the following colors are used')
def step_then_following_colors_are_used(context):
    assert context.table, "table<color> is required"
    used_colors     = sorted(context.used_colors)
    expected_colors = [ row[0]  for row in context.table ]
    # -- LIST-COMPARISON:
    assert_that(used_colors, contains(*sorted(expected_colors)))
