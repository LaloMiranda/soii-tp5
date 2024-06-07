### Laboratorio 5 - Sistemas Operativos II
## Ingeniería en Compuatación - FCEFyN - UNC
# Sistemas Embebidos

## Introducción
Los _sistemas embebidos_ suelen ser accedidos de manera remota. Existen distintas tenicas para hacerlo, una forma muy utilizada suelen ser las _RESTful APIs_. Estas, brindan una interfaz definida y robusta para la comunicación y manipulación del _sistema embebido_ de manera remota. Definidas para un esquema _Cliente-Servidor_ se utilizan en todas las verticales de la industria tecnológica, desde aplicaciones de _IoT_ hasta juegos multijugador.

## Objetivo
El objetivo del presente trabajo práctico es que el estudiante tenga un visión _end to end_ de una implementación básica de una _RESTful API_ sobre un _sistema embedido_.
El estudiante deberá implementarlo interactuando con todas las capas del procesos. Desde el _testing_ funcional (alto nivel) hasta el código en C del servicio (bajo nivel).


### Desarrollo
En esta primer etapa se pide que se implemente un framework que exponga una _REST API_: se propone utilizar [ulfius][ulfi]. El estudiante puede seleccionar otro, justificando la selección, o implementar el propio (no recomendado).

Se pide que se implemente los siguientes endopints:
- `POST: http://localhost:8537/increment`: Incrementa un contador interno 
- `GET: http://localhost:8537/imprimir`: Devuelve el valor del contador 

Se deberá utilizar y adaptar el cliente IPv$ de los laboratorio anteriores para que envien requiest a ambos endpoints de la _REST API_. Tambien se puede utilizar el comando `curl`.

La validación del sistema se debe realizar mediante la creación de al menos 100 procesos que interactúen con los endpoints creados.

### Interacción con los endpoints
Tenemos tres endpoints para interactuar:

```shell
curl -X POST http://[Server IP]:8537/increment
curl -X GET http://[Server IP]:8537/imprimir
curl -X POST http://[Server IP]:8537/reset
```

El primer endpoint aumenta el contador en uno, el segundo devuelve el valor actual del contador y el tercero lo vuelve a cero, esta para testing nada mas.

### Endpoint default
En caso de no aputnar correctamente a un endpoint este pedido sera redireccionado a un *default endpoint* que devuelve el mensaje:

```shell
Page not found, try http://[Server IP]:8537/increment or http://[Server IP]:8537/imprimir
```

### Test
En el repositorio hay un archivo *test.sh* que realiza una cantidad **amount** de incrementos al contador y luego obtiene el valor del mismo.

```shell
sh ./test.sh
```

## Dependencias
Las dependencias son:
- make
- binutils
- build-essential
- libulfius-dev

Se pueden instalar corriendo *make install*, requiere make.

## Referencias y ayudas
- [Ulfius HTTP Framework](https://github.com/babelouest/ulfius)


[ulfi]: https://github.com/babelouest/ulfius
