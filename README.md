# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con una división donde primero escribes 0 como segundo número. -->

Primer numero: 4
Segundo numero: 0
No se puede dividir entre cero
segundo numero distinto de 0: 

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | std::cout << "Calculadora basica" << std::endl; |
| 3. Leer y validar la opción | opcion = leerEntero("Elige una opcion (1-4): "); seguido de while (opcion < 1 || opcion > 4) { ... } |
| 4 y 5. Leer `a` y `b` | a = leerDecimal("Primer numero: "); y b = leerDecimal("Segundo numero: "); |
| 6. Validar el divisor | if (opcion == 4) { while (b == 0) { ... b = leerDecimal(...); } } |
| 7. Decisión múltiple (un `case`) | case 1: resultado = a + b; simbolo = '+'; break; |
| 8. Mostrar el resultado | std::cout << a << " " << simbolo << " " << b << " = " << resultado << std::endl; |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
Lo de hacer que b tuviera que ser distinto que 0, porque no sabia que poner 
## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
el compilador avisó de una falla en el codigo 

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
El programa no aviso ni se cayo, ya que no tiene sentido la division entre 0

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
_____

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | 8 + 5 = 13 | si |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | 3 - 5 = -2 | si |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | 2.5 * 4 = 10 | si |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | -3 * 4 = -12 | si |
| División | 4, 7, 2 | 7 / 2 = 3.5 | 7 / 2 = 3.5 | si |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | 0 / 5 = 0 | si |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | pide b otra vez | si |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | 5 + 0 = 5 (no pide b otra vez) | si |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | vuelve a pedir la opción; 8 + 5 = 13 | si |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | vuelve a pedir la opción; 8 + 5 = 13 | si |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 | toma el .5 como el primer numero | no |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 |elije una opcion valida se repite infinitamente en forma de error | no |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | toma las letras como 0 | no |
| Caso propio 1 | 1, 1, 1 | 1+1=2 | 1+1=2 | si |
| Caso propio 2 | 2, 1, 1 | 1-1=0 | 1-1=0 | si |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Los números se pedían dos veces | deje solo una forma de leer cada numero | si |
| 2 | los cambios no se reflejaban y se quedaban versines viejas | guarde el archivo y volvi a compilar | si |

**¿Encontré algo que la receta no contemplaba? ¿Qué?**
no dice la receta que hacer si el usuario quiere hacer mas de una operacion 

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| Por que con cin el programa se cicla si escribo texto en un número, y leerEntero o leerDecimal no | probe con cin y las funciones de las utilerias |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
a traducir de pseudocodigo a c++

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
guardar y compilar en cada cambio que haga

**¿Qué fue lo más difícil y cómo lo resolví?**
entender porque pedia los numeros 2 veces, lo resolvi comparando lo que salia en la terminal, con el codigo

**¿Qué pregunta me quedó sin responder?**
Cómo hacen leerEntero y leerDecimal para detectar que el usuario escribió texto

**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
si porque ya tenia el orden definido

**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
agregar una quinta opcion para salir de la calculadora

## 14. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 7 a 13 (no quedan `_____`)
- [ ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 4 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom