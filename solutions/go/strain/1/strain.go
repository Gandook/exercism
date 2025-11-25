package strain

func Keep[T any](collection []T, p func(T) bool) []T {
    result := make([]T, 0)
    
    for _, x := range collection {
        if p(x) {
            result = append(result, x)
        }
    }

    return result
}

func Discard[T any](collection []T, p func(T) bool) []T {
    result := make([]T, 0)

    for _, x := range collection {
        if !p(x) {
            result = append(result, x)
        }
    }

    return result
}
