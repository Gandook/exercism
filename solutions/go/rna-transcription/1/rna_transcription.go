package strand

import "strings"

func ToRNA(dna string) string {
	var sb strings.Builder

    for _, r := range dna {
        switch r {
        case 'G':
            sb.WriteByte('C')
        case 'C':
            sb.WriteByte('G')
        case 'T':
            sb.WriteByte('A')
        case 'A':
            sb.WriteByte('U')
        }
    }

    return sb.String()
}
