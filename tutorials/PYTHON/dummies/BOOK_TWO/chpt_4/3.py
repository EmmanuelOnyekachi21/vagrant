# Make a dictionary named people
people = {
        'htanaka': 'Haru Tanaka',
        'sport': 'Football',
        'bargacia': 'Benjamin Alberto Garcia',
        'zmin': 'Zhang Min',
        'papatel': 'Pratyush Aarav',
        'hrjackson': 'Henry Jackson',
        'afarooqi': 'Ayesha Farooqi'
        }

print(people['htanaka'])

people['htanaka'] = "Hannah Tanaka"

print(people['htanaka'])

# adding or changing dictionary data
people.update({'hrjackson': 'Henrietta Jackson'})
people.update({'wwiggins': 'wright wanda'})
print(people)
# Show what's in the data dictionary now.
for person in people.keys():
    print(person + " = " + people[person])
