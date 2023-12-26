import matplotlib.pyplot as plt
import numpy as np

def print_graphic(path):
    x1, y1, z1 = np.loadtxt(f"{path}_sort.txt", unpack=True)
    

    plt.plot(x1, y1, marker='o', linestyle=':')
    plt.plot(x1, z1, marker='o', linestyle=':')

    x2, y2, z2 =  np.loadtxt(f"{path}_sort2.txt", unpack=True)
    

    plt.plot(x2, y2, marker='o', linestyle=':')
    plt.plot(x2, z2, marker='o', linestyle=':')

    x3, y3, z3 =  np.loadtxt(f"{path}_sort3.txt", unpack=True)
    
    plt.plot(x3, y3, marker='o', linestyle=':')
    plt.plot(x3, z3, marker='o', linestyle=':')

    plt.title('Scatter Plot of Points')

    plt.xlabel('X')
    plt.ylabel('Y')

    plt.show()


print_graphic('bubble')
print_graphic('quick')
print_graphic('comb')