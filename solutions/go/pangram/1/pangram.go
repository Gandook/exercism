package pangram

import (
    "strings"
    "unicode"
)

func IsPangram(input string) bool {
	var index int
	contains := make(map[int]bool)
	seenSoFar := 0

    input = strings.ToLower(input)

    for _, r := range input {
        if !unicode.IsLetter(r) {
            continue
        }

        index = int(r - 'a')

        if !contains[index] {
            contains[index] = true
            seenSoFar++
        }
    }

    return seenSoFar == 26
}
