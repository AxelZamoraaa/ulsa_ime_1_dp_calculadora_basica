# Receta: Calculadora básica

<!-- Esta receta YA ESTÁ RESUELTA. No la modifiques.
     Tu trabajo es traducirla a C++ en main.cpp, paso por paso.
     Si encuentras algo que la receta no contempla, anótalo en la bitácora de mejoras de tu README.md.
     Si haces un reto opcional, agrega tus pasos nuevos al final, en la sección "Cambios para el reto". -->

``` text
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

## Cambios para el reto (opcional)

<!-- Solo si haces un reto opcional: escribe aquí los pasos nuevos o modificados. -->