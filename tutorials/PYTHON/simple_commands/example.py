def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

# Some code that performs a specific task
# This code should not run when imported

if __name__ == "__main__":
    # Code inside this block will run only if this script is run directly
    # It won't run when imported as a module

    result = add(5, 3)
    print("Result of addition:", result)

    result = subtract(10, 4)
    print("Result of subtraction:", result)
