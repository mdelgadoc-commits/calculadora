```markdown
# 🧮 Intérprete de Lenguaje - Calculadora Estructural Avanzada

Este repositorio contiene el código fuente para el intérprete y analizador de un lenguaje de programación propio. El proyecto procesa la sintaxis del lenguaje, construye árboles de decisión matemática y genera un análisis semántico completo utilizando herramientas fundamentales de la teoría de compiladores.

Desarrollado utilizando **Flex** (Analizador Léxico), **Bison** (Analizador Sintáctico) y **C/C++**.

## 🚀 Características del Lenguaje
* **Análisis Léxico Eficiente:** Reconocimiento de tokens, palabras clave, variables y operadores mediante expresiones regulares (`calc.l`).
* **Análisis Sintáctico Robusto:** Definición de una Gramática Libre de Contexto (CFG) con manejo de precedencia y asociatividad (`calc.y`).
* **Árbol de Sintaxis Abstracta (AST):** Construcción dinámica de estructuras jerárquicas de nodos para representar la lógica del programa (`ast.h`, `nodo.h`).
* **Verificación Semántica:** Validación de tipos de datos, existencia de variables y consistencia en tiempo de compilación (`semantica.h`).

## 📁 Estructura del Repositorio

* `calc.l`: Archivo de especificación para **Flex** (Lexer).
* `calc.y`: Archivo de especificación para **Bison** (Parser).
* `main.cpp`: Código principal que arranca el proceso de lectura y compilación.
* `ast.h` / `nodo.h`: Definiciones de estructuras de datos para el árbol (AST).
* `semantica.h`: Módulo encargado de la validación de reglas semánticas.
* `codigo_intermedio.txt`: Volcado o traza de la representación intermedia generada.

## 🛠️ Requisitos del Sistema

Para compilar este compilador en Linux o Windows Subsystem for Linux (WSL), necesitas instalar las herramientas de desarrollo esenciales:

```bash
sudo apt update
sudo apt install flex bison build-essential -y
