from behave import *
from newspaper import treat_flags


@Given('the user writes the {flag} and {value}')
def step_impl(context, flag, value):
    context.array = treat_flags(flag, value)

@Then('the user will get a {result} array')
def step_impl(context, result):
    correct_array = [{u'Website': u'http://www.elmundo.es', u'Name': u'El Mundo', u'Language': [u'Spanish'], u'Country': u'Spain', u'Owner': u'Unidad Editorial S.A.', u'Type': u'Daily newspaper'}]
    if (result == "empty"):
        assert (context.array == []) is False
    else:
        assert (context.array == correct_array) is True
