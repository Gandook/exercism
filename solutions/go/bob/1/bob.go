// bob is package using which you can simulate a conversation with Bob.
package bob

import "regexp"

var question = regexp.MustCompile(`^.*\?\s*$`)
var yell = regexp.MustCompile(`^[^a-z]*[A-Z][^a-z]*$`)
var silence = regexp.MustCompile(`^\s*$`)

// isQuestion determines if a given remark is a question.
func isQuestion(remark string) bool {
    return question.MatchString(remark)
}

// isYell determines if a given remark is a yell.
func isYell(remark string) bool {
    return yell.MatchString(remark)
}

// isSilence determines if a given remark is silence.
func isSilence(remark string) bool {
    return silence.MatchString(remark)
}

// Hey returns Bob's reply to a given remark.
func Hey(remark string) string {
	if isSilence(remark) {
        return "Fine. Be that way!"
    }

    if isQuestion(remark) {
        if isYell(remark) {
            return "Calm down, I know what I'm doing!"
        }
        return "Sure."
    } else if isYell(remark) {
        return "Whoa, chill out!"
    }

    return "Whatever."
}
