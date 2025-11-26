package isogram

import (
    "unicode"
    "strings"
)

func IsIsogram(word string) bool {
	word = strings.ToLower(word)
    
	seenLetters := make(map[rune]bool)

    for _, r := range word {
        if !unicode.IsLetter(r) {
            continue
        }

        if seenLetters[r] {
            return false
        }

        seenLetters[r] = true
    }

    return true
}
