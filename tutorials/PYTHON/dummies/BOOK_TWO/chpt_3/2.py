# Adding an item to the end of a list

# Create a list of strings (names)
students = ["Mark", "Amber", "Todd", "Anita", "Sandy"]

# Add the name Goober to the list
students.append("Goober")

new_student = "Amanda"
# Add whatever name is in new_student to the list.
students.append(new_student)

# Print the entire list
print(students)
student_name = "Amanda"

# Add student_name but only if not already in the list
if student_name in students:
    print(student_name + " already in the list")
else:
    students.append(student_name)
    print(student_name + " added to the list")
