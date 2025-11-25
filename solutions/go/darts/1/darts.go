package darts

func Score(x, y float64) int {
	sqDis := x * x + y * y

    if sqDis <= 1.0 {
        return 10
    }
    if sqDis <= 25.0 {
        return 5
    }
    if sqDis <= 100.0 {
        return 1
    }
    return 0
}
