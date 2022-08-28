# Eu_Distance
Se debe ejecutar el archivo main.cpp, este le dará dos opciones:
 - Para realizar un test completo (Se prueba todas las dimensiones con
   todas las cantidades de datos, los datos de prueba por defecto en
   este caso son todos de tipo float) ingrese 1.  
 - Para realizar un test unitario (Se prueba una dimensión "x", con una cantidad "y" de datos, en este apartado se puede escoger que tipo de datos ingresaran, sea int  o float) ingrese 0.

Una vez ejecutado se generara un conjunto de archivos .csv que contendrá toda la información de las distancia euclidianas halladas.

---
Finalmente se debe ejecutar el archivo visual.py que se encargara de tomar la información de los .csv y generar sus respectivos gráficos.

visual.py contiene una función *install* que descarga las librerías **matplotlib**
y **pandas** de manera automática.
 - Para obtener las graficas del test completo debe ingresar 0.  
 - Para obtener las graficas del test unitario debe ingresar 1.
