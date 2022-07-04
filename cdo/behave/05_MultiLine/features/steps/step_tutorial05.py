# file:features/steps/step_tutorial05.py
# ----------------------------------------------------------------------------
# STEPS:
# ----------------------------------------------------------------------------
from behave   import given, when, then
from hamcrest import assert_that, equal_to
from frobu import Frobulator 

@given('a sample text loaded into the frobulator')
def step_impl(context):
    frobulator = getattr(context, "frobulator", None)
    if not frobulator:
        context.frobulator = Frobulator()
    context.frobulator.text = context.text  #< STEP-DATA from context.text

@when('we activate the frobulator')
def step_impl(context):
    context.frobulator.activate()

@then('we will find it similar to {language}')
def step_impl(context, language):
    assert_that(language, equal_to(context.frobulator.seems_like_language()))
