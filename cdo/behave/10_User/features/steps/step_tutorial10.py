# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    step_tutorial10.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 13:06:19 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/03 13:08:19 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# file:features/steps/step_tutorial10.py
# ----------------------------------------------------------------------------
# USER-DEFINED TYPES:
# ----------------------------------------------------------------------------
from behave import register_type
from behave   import given, when, then
from hamcrest import assert_that, equal_to
from calculator import Calculator

def parse_number(text):
    """
    Convert parsed text into a number.
    :param text: Parsed text, called by :py:meth:`parse.Parser.parse()`.
    :return: Number instance (integer), created from parsed text.
    """
    return int(text)
# -- REGISTER: User-defined type converter (parse_type).
register_type(Number=parse_number)

@given('I have a calculator')
def step_impl(context):
    context.calculator = Calculator()

@when('I add "{x:Number}" and "{y:Number}"')
def step_impl(context, x, y):
    assert isinstance(x, int)
    assert isinstance(y, int)
    context.calculator.add2(x, y)

@then('the calculator returns "{expected:Number}"')
def step_impl(context, expected):
    assert isinstance(expected, int)
    assert_that(context.calculator.result, equal_to(expected))
