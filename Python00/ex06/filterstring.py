import sys
from ft_filter import ft_filter


def main():
    try:
        if len(sys.argv) != 3:
            raise AssertionError("Too many arguments.")
        else:
            str = sys.argv[1]
            n = int(sys.argv[2])

        print(list(ft_filter(lambda it: len(it) > n, str.split())))

    except AssertionError as e:
        print("AssertionError:", e, file=sys.stderr)
    except ValueError as e:
        print("ValueError:", e, file=sys.stderr)


if __name__ == "__main__":
    main()
