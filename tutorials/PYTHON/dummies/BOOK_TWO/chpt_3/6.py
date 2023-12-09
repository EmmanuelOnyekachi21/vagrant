# Creates a list of strings
letters = ["A", "B", "C", "D", "C", "E", "C"]

# Remove "C" from the list.
letters.remove("C")

# SHow me the new list
print(letters)


# To remove all occurence occurences of "C"
while "C" in letters:
    letters.remove("C")
print(letters)
