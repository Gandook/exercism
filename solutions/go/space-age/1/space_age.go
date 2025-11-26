package space

type Planet string

func Age(seconds float64, planet Planet) float64 {
	var yearLength float64 = 31557600.0

    switch planet {
    case "Mercury":
        yearLength *= 0.2408467
    case "Venus":
        yearLength *= 0.61519726
    case "Mars":
        yearLength *= 1.8808158
    case "Jupiter":
        yearLength *= 11.862615
    case "Saturn":
        yearLength *= 29.447498
    case "Uranus":
        yearLength *= 84.016846
    case "Neptune":
        yearLength *= 164.79132
    case "Sun":
        return -1.0
    }

    return seconds / yearLength
}
