// gigasecond helps you calculate the exact time that is one billion seconds (a gigasecond) after a given time.
package gigasecond

import "time"

// AddGigasecond receives a specific time and calculate the exact time that is one billion seconds (a gigasecond) after that.
func AddGigasecond(t time.Time) time.Time {
	return t.Add(1_000_000_000 * time.Second)
}
