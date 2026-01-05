package romannumerals

import (
    "errors"
    "strings"
)

func ToRomanNumeral(input int) (string, error) {
	if input < 1 || input >= 4000 {
        return "", errors.New("indescribable number")
    }

    var roman strings.Builder

    for i := 0; i < input / 1000; i++ {
        roman.WriteByte('M')
    }

    input %= 1000
	hundreds := input / 100

    if hundreds < 4 {
        for j := 0; j < hundreds; j++ {
            roman.WriteByte('C')
        }
    } else if hundreds == 4 {
        roman.WriteString("CD")
    } else if hundreds == 9 {
        roman.WriteString("CM")
    } else {
        roman.WriteByte('D')
        for j := 0; j < hundreds - 5; j++ {
            roman.WriteByte('C')
        }
    }

    input %= 100
    tens := input / 10

    if tens < 4 {
        for j := 0; j < tens; j++ {
            roman.WriteByte('X')
        }
    } else if tens == 4 {
        roman.WriteString("XL")
    } else if tens == 9 {
        roman.WriteString("XC")
    } else {
        roman.WriteByte('L')
        for j := 0; j < tens - 5; j++ {
            roman.WriteByte('X')
        }
    }

    input %= 10
	ones := input

    if ones < 4 {
        for j := 0; j < ones; j++ {
            roman.WriteByte('I')
        }
    } else if ones == 4 {
        roman.WriteString("IV")
    } else if ones == 9 {
        roman.WriteString("IX")
    } else {
        roman.WriteByte('V')
        for j := 0; j < ones - 5; j++ {
            roman.WriteByte('I')
        }
    }

    return roman.String(), nil
}
