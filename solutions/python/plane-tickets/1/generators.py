"""Functions to automate Conda airlines ticketing system."""


def generate_seat_letters(number):
    """Generate a series of letters for airline seats.

    :param number: int - total number of seat letters to be generated.
    :return: generator - generator that yields seat letters.

    Seat letters are generated from A to D.
    After D it should start again with A.

    Example: A, B, C, D

    """

    seat_letters = ["A", "B", "C", "D"]

    for i in range(number):
        yield seat_letters[i % 4]


def generate_seats(number):
    """Generate a series of identifiers for airline seats.

    :param number: int - total number of seats to be generated.
    :return: generator - generator that yields seat numbers.

    A seat number consists of the row number and the seat letter.

    There is no row 13.
    Each row has 4 seats.

    Seats should be sorted from low to high.

    Example: 3C, 3D, 4A, 4B

    """

    letter_generator = generate_seat_letters(number)
    generated_seats = 0
    row_num = 0
    letter = ""
    
    while generated_seats < number:
        letter = next(letter_generator)
        if letter == "A":
            row_num += 1
            if row_num == 13:
                row_num = 14

        yield f"{row_num}{letter}"
        generated_seats += 1

def assign_seats(passengers):
    """Assign seats to passengers.

    :param passengers: list[str] - a list of strings containing names of passengers.
    :return: dict - with the names of the passengers as keys and seat numbers as values.

    Example output: {"Adele": "1A", "Björk": "1B"}

    """

    seat_generator = generate_seats(len(passengers))

    return {name: next(seat_generator) for name in passengers}

def generate_codes(seat_numbers, flight_id):
    """Generate codes for a ticket.

    :param seat_numbers: list[str] - list of seat numbers.
    :param flight_id: str - string containing the flight identifier.
    :return: generator - generator that yields 12 character long ticket codes.

    """

    ticket_id = ""
    
    for seat_num in seat_numbers:
        ticket_id = seat_num + flight_id
        while len(ticket_id) < 12:
            ticket_id += "0"

        yield ticket_id
