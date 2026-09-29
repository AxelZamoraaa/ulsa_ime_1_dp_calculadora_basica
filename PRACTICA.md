# Práctica: Calculadora básica

## Sobre esta práctica

**Problema:** escribir un programa en C++ que muestre un menú con cuatro operaciones (suma, resta, multiplicación y división), pregunte al usuario cuál quiere hacer, le pida después los dos números y muestre el resultado.

**Lo que vas a practicar:** decisión múltiple con `switch`, una validación que solo aplica en un caso (el divisor en la división), el tipo de dato `char`, el comportamiento de la división en C++ y, sobre todo, **traducir una receta a código paso por paso**. También refuerzas lo que ya conoces: entrada-proceso-salida, `do-while` para volver a pedir un dato y el uso de funciones ya construidas.

**Idea central:** en la práctica anterior diseñaste la receta desde cero. **Esta vez la receta ya está hecha**, junto con todo el análisis del problema. Tu trabajo es convertirla en código paso por paso, sin saltarte ni inventar pasos, y demostrar con pruebas que tu programa hace exactamente lo que la receta dice. Así se trabaja muchas veces en la vida real: programas a partir del análisis y el diseño que hizo otra persona. Si al programar descubres algo que la receta no contempla, no lo cambies en silencio: anótalo en tu bitácora de mejoras.

**Repositorio base:** https://github.com/narizwallace/ulsa_ime_1_dp_calculadora_basica

**Entregable:** el enlace a tu repositorio, publicado en Google Classroom.

**El proceso que vas a seguir:**

| Fase | Qué haces | ¿Quién la hace? |
|---|---|---|
| 0 | Preparar tu entorno (fork y clonar) | Tú |
| 1 | Entender el problema | Resuelta: léela y verifícala |
| 2 | Diseñar la receta | Resuelta: léela y verifícala |
| 3 | Implementar | Tú |
| 4 | Probar y mejorar | Tú |
| 5 | Publicar en GitHub | Tú |

**Cómo usar el `README.md`:** ya viene en el repositorio base. Las secciones 1 a 6 están resueltas; las secciones 7 a 14 tienen espacios en blanco (`_____`) que vas llenando fase por fase. Cada fase de esta guía te indica qué secciones llenar. No es necesario que uses el archivo README.md, también puedes copiar el contenido y hacerlo en un editor de texto de tu elección. Solo asegúrate de subir el archivo equivalente a tu repositorio.


## Fase 0. Preparar tu entorno

1. Entra al repositorio base: https://github.com/narizwallace/ulsa_ime_1_dp_calculadora_basica
2. Haz clic en **Fork** (arriba a la derecha) para crear tu propia copia en tu cuenta de GitHub.
3. En tu fork, haz clic en **Code**, copia la URL y clónalo en tu computadora.

Estos son los comandos para clonar un repositorio desde tu terminal o línea de comando:
```bash
git clone <URL-de-tu-fork>
cd ulsa_ime_1_dp_calculadora_basica
```
También puedes hacer el clone desde GitHub Desktop como lo hemos hecho antes.


4. Abre la carpeta en tu editor y revisa los archivos:

```
ulsa_ime_1_dp_calculadora_basica/
├── README.md      ← secciones 1 a 6 resueltas; tú llenas de la 7 a la 14
├── PRACTICA.md    ← este documento
├── RECETA.md      ← la receta completa (ya resuelta, no la modifiques)
├── main.cpp       ← punto de partida de tu programa
├── utilerias.h    ← funciones de apoyo para leer números (no lo modifiques)
└── .gitignore     ← evita subir el ejecutable
```

**Todo tu trabajo va dentro de esta carpeta.**

> **Nota técnica: dos funciones en `utilerias.h`.**
> Ahora `utilerias.h` trae las dos funciones que ya conoces: `leerEntero` (Práctica 2), que solo acepta enteros, y `leerDecimal` (Práctica 3), que acepta decimales. En esta práctica usas las dos: `leerEntero` para la opción del menú y `leerDecimal` para los números.
> `int opcion = leerEntero("Elige una opcion (1-4): ");`
> `double a = leerDecimal("Primer numero: ");`
> **Pregunta guía:** ¿por qué la opción del menú se lee con `leerEntero` y no con `leerDecimal`? ¿Qué pasaría si el usuario pudiera elegir la opción 2.5?

---

## Fase 1. Entender el problema

*Esta fase ya está resuelta en las secciones 1 a 4 de tu `README.md`. Léelas con atención; no las modifiques.*

**Resumen del análisis:**

- **Entradas:** `opcion` (`int`, de 1 a 4), `a` (`double`) y `b` (`double`).
- **Salida:** `resultado` (`double`), mostrado en la forma `a símbolo b = resultado`. El símbolo (`+`, `-`, `*` o `/`) se guarda en `simbolo` (`char`).
- **Restricciones:** la opción debe estar entre 1 y 4; si la operación es división, `b` no puede ser 0; en la resta y la división el orden importa (`a` op `b`).
- **Invariante:** al llegar al cálculo, `opcion` está entre 1 y 4 y, si es división, `b` es distinto de 0.

**Aunque no escribas esta fase, compruébala:**

1. ¿Entiendes el problema? Explícaselo a un compañero en 1 minuto, sin leer el texto. Si no puedes, vuelve a leer.
2. ¿Por qué `3 - 5` y `5 - 3` no dan lo mismo? ¿Y `7 / 2` y `2 / 7`? ¿Por qué no importa el orden en la suma?
3. ¿Por qué se valida el divisor solo en la división? ¿Qué pasa con `5 + 0`?
4. Revisa los casos resueltos a mano de la sección 4. ¿Obtienes los mismos resultados?

> **Nota técnica: leer un diseño ajeno también es una habilidad.**
> Entender lo que otra persona escribió, y detectar lo que le faltó, es parte del trabajo diario de un programador. No confíes a ciegas en el análisis: verifícalo. Si algo no te cuadra, anótalo en tu bitácora de dudas.

---

## Fase 2. Diseñar la receta

*Esta fase ya está resuelta: la receta completa está en `RECETA.md`. Léela; no la modifiques.*

```
1. MOSTRAR "Calculadora basica"
2. MOSTRAR el menu: 1) Suma  2) Resta  3) Multiplicacion  4) Division
3. REPETIR
      opcion ← leerEntero("Elige una opcion (1-4): ")
      SI opcion < 1 O opcion > 4 ENTONCES
          MOSTRAR "Opcion no valida, elige un numero del 1 al 4"
      FIN SI
   HASTA QUE opcion este entre 1 y 4
4. a ← leerDecimal("Primer numero: ")
5. b ← leerDecimal("Segundo numero: ")
6. SI opcion = 4 ENTONCES
      MIENTRAS b = 0 HACER
          MOSTRAR "No se puede dividir entre cero"
          b ← leerDecimal("Segundo numero (distinto de 0): ")
      FIN MIENTRAS
   FIN SI
7. SEGUN opcion
      1: resultado ← a + b ; simbolo ← '+'
      2: resultado ← a - b ; simbolo ← '-'
      3: resultado ← a * b ; simbolo ← '*'
      4: resultado ← a / b ; simbolo ← '/'
   FIN SEGUN
8. MOSTRAR a, simbolo, b, "=", resultado
9. FIN
```

**Antes de programar, recorre la receta a mano** con el caso: opción 4, `a` = 5, `b` = 0 y luego `b` = 2. Anota cómo cambia cada variable paso a paso. ¿En qué paso se detecta el 0? ¿Cuántas veces se ejecuta el Paso 6?

> **Nota técnica: la decisión múltiple.**
> El Paso 7 elige **un camino entre varios** según el valor de `opcion`. Podrías escribirlo con cuatro `SI` seguidos, pero un `SEGUN` deja más claro que solo uno de los caminos se ejecuta. En C++, el `SEGUN` se escribe con `switch`.

> **Nota técnica: una validación con condición.**
> En la Práctica 3 validabas siempre las medidas. Aquí, el Paso 6 tiene un `SI` antes del `MIENTRAS`: el divisor solo se valida **cuando la operación es división**. Una suma con 0 es perfectamente válida.
> **Pregunta guía:** ¿qué pasaría si quitaras el `SI opcion = 4` y dejaras solo el `MIENTRAS`?

---

## Fase 3. Implementar

*Trabaja sobre `main.cpp`. Llena las secciones 7, 8, 9 y 12 de tu `README.md`.*

**Preguntas guía**

- ¿Qué variables necesitas y de qué tipo será cada una? ¿Con qué valor empiezan? (La sección 2 de tu `README.md` te lo dice.)
- ¿Cada paso de la receta tiene su línea (o líneas) de código? Si no, ¿qué falta?
- ¿Tu código hace **exactamente** lo que dice la receta, ni más ni menos?

**Así se ve tu punto de partida en `main.cpp`:**

```cpp
// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué funciones trae ahora utilerias.h? ¿Qué devuelve cada una?
#include "utilerias.h"

int main() {
    // Variables (siempre inicializadas)
    // TODO: opcion, a, b, resultado y simbolo.
    //       ¿De qué tipo es cada una? Revisa la sección 2 de tu README.
    //       ¿Con qué valor empieza un char?

    // Pasos 1 y 2: título y menú
    // TODO

    // Paso 3: leer la opción con leerEntero y repetir si no está entre 1 y 4
    // TODO: ¿qué ciclo usaste en la Práctica 3 para volver a pedir un dato?

    // Pasos 4 y 5: leer los dos números con leerDecimal
    // TODO

    // Paso 6: SOLO si la opción es división, ¿qué haces si b es 0?
    // TODO

    // Paso 7: decisión múltiple
    // TODO: switch (opcion) { case 1: ... break; ... default: ... }
    //       ¿Qué pasa si olvidas un break? (Experimento A)

    // Paso 8: salida -> a simbolo b = resultado
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}
```

**Construye en pasos pequeños.** Compila, prueba y haz un commit después de cada uno:

1. Pasos 1, 2, 4, 5 y 8 **solo con la suma**: lee la opción (sin validarla todavía), lee los dos números, suma y muestra el resultado.
2. Paso 7 completo: agrega resta, multiplicación y división al `switch`. Haz aquí el Experimento A.
3. Paso 3: agrega la validación de la opción.
4. Haz el Experimento B **antes** de validar el divisor. Después agrega el Paso 6.

**Para compilar y ejecutar:**

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

**Traza la receta en tu código.** Deja un comentario `// Paso N` sobre cada bloque, igual que en la plantilla. Al terminar, llena la sección 8 de tu `README.md`: para cada paso de la receta, la instrucción de C++ que lo implementa. Si un paso no tiene código, o hay código que no corresponde a ningún paso, algo no cuadra.

> **Nota de C++: `switch`, `case`, `break` y `default`.**
> `switch (opcion)` compara el valor de `opcion` con cada `case` y salta al que coincide. `break` termina el `switch`; sin él, el programa **sigue ejecutando el siguiente `case`**. `default` se ejecuta cuando ningún `case` coincide. Gracias al Paso 3 eso "nunca debería pasar", pero es buena práctica incluirlo siempre: si algún día alguien cambia el código y rompe la validación, el `default` lo delata.
> ```cpp
> switch (opcion) {
>     case 1:
>         // ...
>         break;
>     default:
>         std::cout << "Opcion inesperada\n";
>         break;
> }
> ```

> **Nota de C++: el compilador también te habla.**
> **Experimento A (obligatorio):** quita el `break` del `case 1` y compila. Lee con atención lo que te dice el compilador. Después ejecuta una suma con 8 y 5. ¿Qué resultado y qué símbolo aparecen? ¿Por qué? A esto se le llama *fall-through* (el programa "cae" al siguiente `case`). Compilar con `-Wall -Wextra` sirve justamente para esto: una advertencia no detiene la compilación, pero casi siempre señala un error real. Vuelve a poner el `break`.

> **Nota de C++: `switch` solo funciona con enteros y `char`.**
> Puedes hacer `switch` sobre un `int` o un `char`, pero **no** sobre un `double` ni sobre un `std::string`. Por eso el menú usa números enteros. Todo `switch` puede escribirse también con `if` / `else if`; elige el que se lea más claro. Cuando comparas **una sola variable** contra varios valores fijos, `switch` suele ser más claro.

> **Nota de C++: `char` vs. `std::string`.**
> Un `char` guarda **un solo carácter** y se escribe con comillas simples: `'+'`. Un `std::string` guarda un texto y se escribe con comillas dobles: `"+"`. Para el símbolo de la operación basta un `char`. Inicialízalo como cualquier variable, por ejemplo `char simbolo = ' ';` (un espacio).

> **Nota de C++: el error silencioso, otra vez.**
> **Experimento B (obligatorio):** antes de agregar el Paso 6, ejecuta una división con `a` = 5 y `b` = 0. ¿Qué muestra el programa? ¿Tiene sentido? Con `double`, C++ no se detiene ni marca error: entrega un valor especial que significa "infinito". El programa "funciona", pero el resultado no sirve. Por eso validamos.

> **Nota de C++: la división depende del tipo de dato.**
> **Experimento C (opcional):** declara `a` y `b` como `int` (sigue leyéndolos con `leerDecimal`) y divide 7 entre 2. ¿Qué resultado obtienes? ¿Te avisó el compilador? Entre dos `int`, `/` hace **división entera**: descarta la parte decimal. Es uno de los errores más comunes en C++. Vuelve a dejar `double` al terminar. **No** pruebes dividir entre 0 con `int`: a diferencia de `double`, eso puede hacer que el programa termine de golpe.

> **Nota de C++: buenas prácticas.**
> - Usa los nombres de la receta (`opcion`, `a`, `b`, `resultado`, `simbolo`): así cualquiera puede comparar tu código con el diseño.
> - Inicializa siempre tus variables.
> - Los mensajes al usuario deben decir qué se espera: `"Elige una opcion (1-4): "`.
> - Un `case` por operación, y cada uno termina con `break`.
> - Comenta el *porqué* de lo que haces, no lo obvio. Los comentarios `// Paso N` son la excepción: sirven para rastrear la receta.

**Bitácora de dudas:** ¿qué dudas quieres cubrir con el profesor? Anótalas en la sección 12 de tu `README.md`, junto con lo que ya intentaste para resolverlas.

---

## Fase 4. Probar y mejorar

*Llena las secciones 10 y 11 de tu `README.md`.*

**Tabla de pruebas** (en tu `README.md` completa las columnas "Obtenido" y "¿Pasó?"):

| Caso | Entradas (opción, a, b) | Resultado esperado |
|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 |
| División | 4, 7, 2 | 7 / 2 = 3.5 |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 |

**Agrega al menos 2 casos propios.**

**Preguntas guía**

- En "Dividendo cero" (0 / 5), ¿por qué el programa no se queja, pero en "Divisor cero" sí?
- En "Suma con cero", ¿tu programa volvió a pedir `b`? Si lo hizo, ¿qué parte de la receta no seguiste?
- En "Opción decimal" y "Opción fuera de rango", ¿quién detectó el error: `leerEntero` o tu programa?
- ¿Alguna prueba falló? ¿El error estaba en tu código, en la receta o en el resultado esperado?

**Ciclo de mejora:** identifica → cambia una sola cosa → vuelve a probar todo. Registra cada cambio en tu bitácora de mejoras. Si encontraste algo que la receta no contemplaba, anótalo también ahí.

**Retos opcionales (para tu insatisfacción positiva):**

Si haces un reto, escribe primero los pasos nuevos en la sección "Cambios para el reto" de `RECETA.md` y después prográmalos.

1. Agrega la opción **5) Salir** y repite la calculadora hasta que el usuario la elija. ¿Qué ciclo envuelve a todo el programa? ¿Cómo cambia la validación del Paso 3?
2. Permite elegir la operación escribiendo el **símbolo** (`+`, `-`, `*`, `/`) en lugar de un número. Pista: `switch` también funciona con `char`.
3. Muestra el resultado siempre con **2 decimales** (investiga `<iomanip>`).
4. Reemplaza los "números mágicos" 1, 2, 3 y 4 por **constantes con nombre** (por ejemplo, `const int SUMA = 1;`). ¿Qué ganas en claridad?
5. Curiosidad: multiplica 0 por -5. ¿Por qué aparece `-0`? Investiga qué es el "cero negativo" en los números de punto flotante.
6. Guarda los **últimos 5 resultados** en un arreglo y muéstralos al salir (combínalo con el reto 1; recuerda la Práctica 2).

---

## Fase 5. Publicar en GitHub

1. Verifica que tu `README.md` esté completo, sin `_____` pendientes, que no modificaste la receta de `RECETA.md` y que tu programa compile sin advertencias.
2. Sube tus cambios a tu fork. Debes tener **al menos 4 commits** hechos durante el trabajo, uno por cada paso pequeño de la Fase 3, con mensajes que digan qué cambió, por ejemplo: `Agrega suma con menu`, `Agrega las cuatro operaciones con switch`, `Agrega validacion de la opcion`, `Agrega validacion del divisor`.

Con los siguientes comandos puedes hacer un commit y publicarlo desde tu terminal o línea de comando:

```bash
git add .
git commit -m "Agrega validacion del divisor"
git push origin main
```
También puedes usar GitHub Desktop como lo hemos hecho antes.

3. Abre tu repositorio en GitHub y comprueba que ahí aparezcan tu código y tu `README.md` actualizados. Tu fork tiene esta forma:
   `https://github.com/<tu-usuario>/ulsa_ime_1_dp_calculadora_basica`
4. Entrega en Google Classroom el enlace a **tu fork**.

> **Nota técnica: commits pequeños.**
> Cada commit es un punto al que puedes volver si algo sale mal. Confirma cambios cada vez que completes un paso pequeño que funcione, como los de la Fase 3. Te será especialmente útil en los experimentos: si algo se rompe, puedes regresar al último commit.

---

## Cierre y reflexión

*Llena la sección 13 de tu `README.md` antes de entregar.*

1. ¿Qué aprendiste con esta práctica?
2. Ahora que la terminaste, ¿qué cambiarías de tu proceso?
3. ¿Qué fue lo más difícil y cómo lo resolviste?
4. ¿Qué pregunta te quedó sin responder?
5. ¿Fue más fácil programar a partir de una receta ajena que de la tuya? ¿Por qué?
6. Si tú hubieras diseñado la receta, ¿qué le cambiarías?

---

## Lista de verificación antes de entregar

- [ ] Llené las secciones 7 a 13 de mi `README.md` (no quedan `_____`)
- [ ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 4 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_calculadora_basica` y el código está en `main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom