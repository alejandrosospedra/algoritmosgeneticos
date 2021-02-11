# algoritmosgeneticos
En esta práctica de algoritmos genéticos hemos implementado seis procedimientos con el objetivo de encontrar una solución óptima a un problema. 
Cada procedimiento depende de la anterior y, a partir de la llamada de todos los procedimientos, encontramos la solución más óptima que puede ser la esperada.
El conjunto de procedimientos se basan en la teoría de la evolución de Darwin.
A partir de una población inicial, los mejores de cada generación se empareja entre ellos, de tal manera que, su descendencia será una combinación de los mejores y quizás sufrirán mutaciones, según si las mutaciones son favorables o desfavorables tendrán mayor posibilidades de supervivencia para pasar a la siguiente generación.
Por lo tanto, los mejores sobreviven y cada generación es mejor. Entonces, en el paso de las generaciones habrá más posibilidades de encontrar el mejor y este individuo será la solución más óptima en nuestro problema.
En nuestro problema la población inicial es un conjunto de combinaciones de 0 y 1 de tamaño 30 (genes) que son las posibles contraseñas de una caja fuerte donde cada fila se guarda una contraseña diferente (cromosoma). Por lo tanto, la solución a nuestro problema es encontrar la contraseña.
