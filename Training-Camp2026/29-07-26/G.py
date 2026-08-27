n = int(input())

cards = input()

count = {"B": 0, "G": 0, "R": 0}
for c in cards:
    count[c] += 1

n_types = 0
if count["B"]:
    n_types += 1
if count["G"]:
    n_types += 1
if count["R"]:
    n_types += 1


if n == 1:
    if count["B"]:
        print("B")
    if count["G"]:
        print("G")
    if count["R"]:
        print("R")

elif n == 2:

    if n_types == 2:
        if count["B"] == 0:
            print("B")
        if count["G"] == 0:
            print("G")
        if count["R"] == 0:
            print("R")
    
    else:

        if count["B"] > 0:
            print("B")
        if count["G"] > 0:
            print("G")
        if count["R"] > 0:
            print("R")
else:

    if n_types == 3:
        print("BGR")
    elif n_types == 1:
        if count["B"] > 0:
            print("B")
        if count["G"] > 0:
            print("G")
        if count["R"] > 0:
            print("R")
    else:
        if count["G"] >= 2 or count["R"] >= 2:
            print("B", end="")
        if count["B"] >= 2 or count["R"] >= 2:
            print("G", end="")
        if count["G"] >= 2 or count["B"] >= 2:
            print("R", end="")
        print()

