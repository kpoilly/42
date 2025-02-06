
def NULL_not_found(object: any) -> int:
	#your code here
	if (object and object == object): 
		print("Type not found")
		return 1
	
	types = {list 	: "List",
		  	float 	: "Cheese",
			int		: "Zero",
			str		: "Empty",
			bool	: "Fake",
			type(None)	: "Nothing"}
	
	obj_type_name = types.get(type(object), "Type not found")
	if (obj_type_name != "Type not found"): obj_type_name += " : " + str(object) + " " + str(type(object))
	print(obj_type_name)
	return 0