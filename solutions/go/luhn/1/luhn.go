package luhn

import (
    "strings"
    "unicode"
)

func Valid(id string) bool {
	id = strings.ReplaceAll(id, " ", "")

    runes := []rune(id)

    if len(runes) < 2 {
        return false
    }

    var digit int
    digitSum := 0

    for i, r := range runes {
        if !unicode.IsDigit(r) {
            return false
        }

        digit = int(r - '0')
        
        if i % 2 == len(runes) % 2 {
            digit *= 2
            if digit > 9 {
                digit -= 9
            }
        }

        digitSum += digit
    }

    return digitSum % 10 == 0
}
