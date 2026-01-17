package clock

import "fmt"

type Clock struct {
    Hour, Minute int
}

func New(h, m int) Clock {
    for m < 0 {
        m += 60
        h -= 1
    }
    for h < 0 {
        h += 24
    }
	
    return Clock{
        Hour: (h + m / 60) % 24,
        Minute: m % 60,
    }
}

func (c Clock) Add(m int) Clock {
	return Clock{
        Hour: (c.Hour + (c.Minute + m) / 60) % 24,
        Minute: (c.Minute + m) % 60,
    }
}

func (c Clock) Subtract(m int) Clock {
    toAdd := -m
    for toAdd < 0 {
        toAdd += 24 * 60
    }
	return c.Add(toAdd)
}

func (c Clock) String() string {
	return fmt.Sprintf("%02d:%02d", c.Hour, c.Minute)
}
