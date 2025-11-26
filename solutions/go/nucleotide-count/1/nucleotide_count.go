package dna

import (
    "regexp"
    "errors"
)

var dnaFormat = regexp.MustCompile(`^[ACGT]*$`)

type Histogram map[rune]int
type DNA string

// Counts generates a histogram of valid nucleotides in the given DNA.
// Returns an error if d contains an invalid nucleotide.
//
// Counts is a method on the DNA type. A method is a function with a special receiver argument.
// The receiver appears in its own argument list between the func keyword and the method name.
// Here, the Counts method has a receiver of type DNA named d.
func (d DNA) Counts() (Histogram, error) {
	if !dnaFormat.MatchString(string(d)) {
        return Histogram{}, errors.New("invalid sequence")
    }
    
    var h Histogram = make(map[rune]int)
    h['A'] = 0
    h['C'] = 0
    h['G'] = 0
    h['T'] = 0

    for _, r := range d {
        h[r]++
    }
    
	return h, nil
}
