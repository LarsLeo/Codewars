package main

import (
	"fmt"
	"strconv"
	"strings"
)

func Is_valid_ip(ip string) bool {
	sections := strings.Split(ip, ".")
	if len(sections) != 4 {
		return false
	}

	for _, section := range sections {
		if len(section) > 1 && section[0:1] == "0" {
			return false
		}

		intVal, err := strconv.Atoi(section)
		if err != nil {
			return false
		}

		if intVal > 255 || intVal < 0 {
			return false
		}
	}

	return true
}

func main() {
	fmt.Print(Is_valid_ip("123.045.067.089"))
}
