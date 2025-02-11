import sys


def main():
    try:
        if len(sys.argv) != 2:
            raise AssertionError("Too many arguments.")

        str = sys.argv[1]
        for i in str:
            if not i.isalnum():
                raise AssertionError("Invalid argument.")

        NESTED_MORSE = {
            'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.',
            'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
            'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
            'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
            'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
            'Z': '--..', '0': '-----', '1': '.----', '2': '..---',
            '3': '...--', '4': '....-', '5': '.....', '6': '-....',
            '7': '--...', '8': '---..', '9': '----.', ' ': '/',
        }

        morse_str = ""

        for i in str.upper():
            if i in NESTED_MORSE:
                morse_str += NESTED_MORSE[i]
                morse_str += " "
            else:
                raise AssertionError("Invalid character: {}".format(i))

        print(morse_str)

    except AssertionError as e:
        print("AssertionError:", e, file=sys.stderr)


if __name__ == "__main__":
    main()
