from os import system
for i in range (100):
     dirname = f"folder_{i}"
     system(f"mkdir {dirname}")
     for j in range (123):
             dirname2 = f"folder_{j}"
             system(f"mkdir {dirname}/{dirname2}")
             for z in range(151):
                     system(f"touch {dirname}/{dirname2}/file{z}")

