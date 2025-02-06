import sys

def main():
	# your tests and your error handling
	text = None
	try:
		text = sys.argv[1]
	except:
		while not text:
			text = input("By Odin, write something!: ")

	print("The text contains", len(text), "characters:")

	count = 0
	for c in text:
		if c.isupper(): count += 1
	print(count, "upper letters")

	count = 0
	for c in text:
		if c.islower(): count += 1
	print(count, "lower letters")

	count = 0
	for c in text:
		if c in "&<>'!.;*:,?-_/()[]" + '"': count += 1
	print(count, "punctuation marks")

	count = 0
	for c in text:
		if c == " ": count += 1
	print(count, "spaces")

	count = 0
	for c in text:
		if c.isnumeric(): count += 1
	print(count, "digits")

if __name__ == "__main__":
	main()