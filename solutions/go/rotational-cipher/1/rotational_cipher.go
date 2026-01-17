package rotationalcipher

import (
    "strings"
)

func RotationalCipher(plain string, shiftKey int) string {
	var result strings.Builder

    for _, r := range plain {
        if 'A' <= r && r <= 'Z' {
            result.WriteByte(byte((int(r - 'A') + shiftKey) % 26 + 65))
        } else if 'a' <= r && r <= 'z' {
            result.WriteByte(byte((int(r - 'a') + shiftKey) % 26 + 97))
        } else {
            result.WriteRune(r)
        }
    }

    return result.String()
}
