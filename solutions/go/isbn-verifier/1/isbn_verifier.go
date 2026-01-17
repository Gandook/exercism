package isbn

import (
    "strings"
)

func IsValidISBN(isbn string) bool {
	isbn = strings.ReplaceAll(isbn, "-", "")

    if len(isbn) != 10 {
        return false
    }

    sum := 0

    for i := 0; i < 9; i++ {
        if isbn[i] < '0' || isbn[i] > '9' {
            return false
        }

        sum += int(isbn[i] - '0') * (10 - i)
    }

    if isbn[9] == 'X' {
        sum += 10
    } else if isbn[9] < '0' || isbn[9] > '9' {
        return false
    } else {
        sum += int(isbn[9] - '0')
    }

    return sum % 11 == 0
}
