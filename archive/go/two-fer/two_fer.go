package twofer

// ShareWith 
// -param: name a string (default: "you")
// -return: "One for " `name` ", one for me."
func ShareWith(name string) string { 
	// why can't I have a default value for function arguments? 
	if len(name) == 0 { // how do I check if nil? is it `?name`
		name = "you"
	}
	return "One for " + name + ", one for me."
}
