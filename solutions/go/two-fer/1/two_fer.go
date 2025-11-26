// twofer helps you create customized messages for when you want to share a cookie with someone.
package twofer

import "fmt"

// ShareWith receives a name and returns a string in this format:
// 1. "One for you, one for me." if name is empty.
// 2. "One for <name>, one for me." (replace <name> with the actual name) otherwise.
func ShareWith(name string) string {
    var receiver string

    if name == "" {
        receiver = "you"
    } else {
        receiver = name
    }
    
	return fmt.Sprintf("One for %s, one for me.", receiver)
}
