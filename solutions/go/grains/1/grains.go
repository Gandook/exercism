package grains

import "errors"

func Square(number int) (uint64, error) {
	if 1 <= number && number <= 64 {
        return uint64(1) << (number - 1), nil
    }
    return 0, errors.New("invalid square number")
}

func Total() uint64 {
	var total uint64 = 0
    var grainsToAdd uint64

    for i := 1; i <= 64; i++ {
        grainsToAdd, _ = Square(i)
        total += grainsToAdd
    }

    return total
}
