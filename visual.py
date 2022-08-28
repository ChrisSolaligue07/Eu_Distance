from cgi import test
from re import A
import pip

def install(package):
    pip.main(['install', package])

try:
    import matplotlib
    import pandas
except:
    install('matplotlib')
    install('pandas')

import matplotlib.pyplot as plt
import pandas
import inspect, os


dimensiones = [10, 20, 30, 40, 50]
vectores = [10000, 20000, 30000, 40000, 50000]

dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
images_ = dir + "\\images"

wtest = int(input("Caso unitario [1]\nCasos multiples [0]\n-> "))
wtest = bool(wtest)

if wtest:
    test_ = dir + "\\res_info.csv"
    with open(test_) as f:
            df = pandas.read_csv(f)
            columns = list(df.keys())
            print(df)
            df.plot(x='frec', y='data',kind = 'hist', legend=None, bins= int(180/5), color='blue', edgecolor='black')
            plt.xlabel('EU Distance')
            plt.ylabel('Frecuency')
            plt.title(f'Test con {columns[2]} dimensiones y {columns[3]} vectores')
            plt.savefig(dir + "\\res_info.png")
            plt.close()
            print("Imagen generada.")
else:
    j = 0
    x = 0

    for i in range(1, 26):

        test_ = dir + "\\test\\res_info" + str(i) + ".csv"
        
        with open(test_) as f:
            df = pandas.read_csv(f)
            print(df)
            df.plot(x='frec', y='data',kind = 'hist', legend=None, bins= int(180/5), color='blue', edgecolor='black')
            plt.xlabel('EU Distance')
            plt.ylabel('Frecuency')
            plt.title(f'Test con {dimensiones[x]} dimensiones y {vectores[j]} vectores')
            plt.savefig(images_ + "\\res_info" + str(i) + ".png")
            plt.close()
            # plt.show()
            print(f"Imagen {i} generada.")

        j += 1
        if j == 5:
            x += 1
            j = 0
        if x == 5:
            x = 0
