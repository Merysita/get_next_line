*Este proyecto ha sido creado como
parte del currículo de 42 por mantunez*

# get_next_line

### Descripción:
**Get_next_line** es una función que devuelve una linea de un fichero, es decir, que leería el archivo buscando un **\n** (salto de linea) y devolvería esa linea. Si volviesemos a llamarlo buscaria la siguiente, así hasta llegar al final del archivo y no pueda leer más.

### Instrucciones:
A la hora de crear el **main**, como se puede deducir en la descripción deberiamos crear un bucle para comprobar que está leyendo todo el archivo correctamente.

Y a la hora de compilar podemos o no usar -D BUFFER_SIZE=n, donde n sería el número con el que queremos que se lea el archivo. 

> cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 \<archivos>.c

### Recursos:
La verdad es que los pocos tutoriales que vi sobre el proyecto no me ayudaron a entender casi nada, es más sentía más dudas. Así que en principio lo que recomendaría más es enteneder el uso de la variable estática y read, pelearte con el proyecto y preguntar a los compañeros.

**El uso de la IA**:
Este proyecto se ha realizado enteramente sin ayuda de la IA, solo ayuda humana.

### Sección adicional:
**Explicación del algoritmo y justificación**: La lógica que he seguido para hacer el proyecto se trata básicamente en rellenar stash y si se encuentra '\n' dentro devolverlo.
\
Para ello hay que hacer comprobaciones de si se puede leer del fichero o si ya ha terminado. Lo que leemos del fichero se reserva en un buff cuyo size podemos modificar y stash lo rellenamos de lo que hay en buff siguiendo esta lógica: 

* Si no hay nada en stash copiamos buff en stash.
* Si hay algo en stash tenemos que unir lo que hay dentro de stash con lo que hay en buff.

Esto teniendo en cuenta que solo se rellena hasta que no haya más que leer o se encuentre '\n' en stash. Cuando llegamos a esta situación la función devuelve hasta '\n' y lo que queda en stash después del '\n' lo guardamos en stash ya que al ser una variable estática seguirá teniendo esa información la próxima vez que la llamemos y podremos seguir leyendo el fichero.


He usado esta lógica por que es con la que me ha resultado más sencillo entender su funcionanamiento y saber que estoy haciendo en cada paso. 