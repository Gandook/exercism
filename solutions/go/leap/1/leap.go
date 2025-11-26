// leap helps you find out if a specific year is a leap year.
package leap

// IsLeapYear determines if a given year is a leap year.
func IsLeapYear(year int) bool {
	if year % 4 != 0 {
        return false
    }
    if year % 100 == 0 && year % 400 != 0 {
        return false
    }
    return true
}
