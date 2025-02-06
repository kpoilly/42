import sys

try:
	assert len(sys.argv) <= 2, "AssertionError: more than one argument is provided"
	sys.argv[1] 
	try:
		int(sys.argv[1])
	except:
		raise AssertionError("AssertionError: argument is not an integer")
	print("I'm", ("Even.", "Odd.")[int(sys.argv[1]) % 2])
except AssertionError as msg:
	print(msg)
except IndexError:
	pass