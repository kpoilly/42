def all_thing_is_obj(object: any) -> int:
	# your code here
	types = {list 	: "List",
		  	tuple 	: "Tuple",
			set		: "Set",
			dict	: "Dict"}
	
	obj_type_name = types.get(type(object), "Type not found")
	if (type(object) == str): obj_type_name = object + " is in the kitchen"
	if (obj_type_name != "Type not found"): obj_type_name += " : " + str(type(object))

	print(obj_type_name)
	return 42