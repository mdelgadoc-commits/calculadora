# Compilador en Español — Flex + Bison (C++)

Interprete de lenguaje de programacion en español implementado con **Flex** (analizador lexico) y **Bison** (analizador sintactico), desarrollado en C++.

---

## Caracteristicas

- Analizador lexico con deteccion de errores lexicos
- Analizador sintactico con gramatica definida
- Analizador semantico con tabla de simbolos por alcances
- Generacion de AST (Arbol Sintactico Abstracto)
- Generacion de CST (Arbol Sintactico Concreto)
- Generacion de codigo intermedio de 3 direcciones
- Deteccion de errores lexicos, sintacticos y semanticos
- Soporte para bucles `para` y `mientras`
- Soporte para funciones con parametros
- Soporte para arreglos
- Deteccion de division por cero
- Reporte de errores con numero de linea

---

## Estructura del proyecto
calculadora/

├── calc.l          # Analizador lexico (Flex)

├── calc.y          # Analizador sintactico (Bison)

├── nodo.h          # Estructura base del arbol sintactico

├── ast.h           # Generacion del AST

├── cst.h           # Generacion del CST

├── semantica.h     # Tabla de simbolos y verificacion de tipos

├── intermedio.h    # Generacion de codigo intermedio

├── ast_salida.txt  # AST guardado por instruccion

├── cst_salida.txt  # CST guardado por instruccion

└── codigo_intermedio.txt  # Codigo de 3 direcciones generado
---

## Compilacion

```bash
bison -d calc.y
flex calc.l
g++ lex.yy.c calc.tab.c -lm -o calc
```

---

## Ejecucion

```bash
./calc
```

Escribe tu codigo y presiona **Ctrl+D** para finalizar.

---

## Sintaxis del lenguaje

### Tipos de datosentero x;

decimal y;

texto nombre;

entero numeros[5];

### Asignacion
x = 10;

y = 3.14;

### Mostrar en pantalla
mostrar << "Hola mundo";

mostrar << x;

mostrar << x + y;

### Leer datos
datoingresado >> x;

### Condicional
si (x > 5) {

mostrar << "Mayor que 5";

}

sino {

mostrar << "Menor o igual a 5";

}

### Bucle mientras
entero i;

i = 0;

mientras (i < 5) {

mostrar << i;

i = i + 1;

}

### Bucle para
entero x;

para (x = 0; x < 3; x = x + 1) {

mostrar << x;

}

### Funciones
funcion entero sumar(entero a, entero b) {

retornar a + b;

}

entero resultado;

resultado = sumar(3, 4);

mostrar << resultado;

### Arreglos
entero numeros[5];

numeros[0] = 10;

numeros[1] = 20;

mostrar << numeros[0];

---

## Tipos de errores detectados

| Tipo | Ejemplo | Mensaje |
|------|---------|---------|
| ERROR LEXICO | `1.22.33` | Numero invalido |
| ERROR LEXICO | `@` | Caracter desconocido |
| ERROR SINTACTICO | `(4 + 3;` | Parentesis sin cerrar |
| ERROR SEMANTICO | `mostrar << z;` | Variable no declarada |
| ERROR SEMANTICO | `entero x; entero x;` | Variable ya declarada |
| ERROR SEMANTICO | `a / 0` | Division por cero |

---

## Salida del programa

Al ejecutar el programa se genera:

1. **AST y CST** por cada instruccion en pantalla
2. **Tabla de simbolos** con variables y sus valores
3. **Codigo intermedio** de 3 direcciones
4. **Resumen de errores** al final

---

## Ejemplo de ejecucion

**Codigo ingresado:**
entero a;

entero b;

a = 10;

b = 5;

mostrar << a + b;

**Salida:**
--- AST ---

mostrar

└── expr: +

├── var(a)=10

└── var(b)=5
--- CST ---

mostrar

├── expr: +

│   ├── var(a)=10

│   ├── var(b)=5

│   └── token: '+'

└── token: '<<'
TABLA DE SIMBOLOS

entero a = 10

entero b = 5
CODIGO INTERMEDIO

a = DECL entero

b = DECL entero

a = 10

b = 5

t0 = a + b

PRINT t0
RESUMEN DE ERRORES

Sin errores. Codigo valido.

---

## Tecnologias utilizadas

- **Flex** 2.6.4 — Analizador lexico
- **Bison** 3.8.2 — Analizador sintactico
- **G++** 13.3.0 — Compilador C++
- **Ubuntu** 24.04 — Sistema operativo
- **VS Code** — Editor de codigo
