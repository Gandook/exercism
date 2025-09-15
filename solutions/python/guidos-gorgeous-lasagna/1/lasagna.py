"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2


def bake_time_remaining(passed_time):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - passed_time


def preparation_time_in_minutes(layer_count):
    """Calculate the time needed to make all the layers.

    :param layer_count: int - the number of layers.
    :return: int - total preparation time (in minutes).

    Function that takes the number of layers and calculates the total amount of time needed for making all of them. The amount of time needed for one layer (in minutes) is `PREPARATION_TIME`.
    """
    
    return layer_count * PREPARATION_TIME


def elapsed_time_in_minutes(layer_count, elapsed_bake_time):
    """Calculate the total elapsed time in minutes.

    :param layer_count: int - the number of layers.
    :param elapsed_bake_time: int - the time spent on baking so far.
    :return: int - total elapsed time (in minutes).

    Function that takes the number of layers and the time spent on baking, and calculates the total amount of elpased time by calculating the preparation time and adding that to `elapsed_bake_time`.
    """
    
    return preparation_time_in_minutes(layer_count) + elapsed_bake_time
