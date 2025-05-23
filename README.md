# Sistema de Gestión para Bibliotecas

Este proyecto es un **sistema básico de gestión de bibliotecas** desarrollado en C++ como proyecto final para la materia de Programación, realizado por un estudiante de segundo semestre de Ingeniería en Sistemas.

## Descripción

El sistema permite gestionar libros en una biblioteca a través de un menú interactivo en la consola. Puedes consultar, agregar, buscar y modificar el estado de los libros. Además, al cerrar el programa, se registra la fecha y hora de la sesión en un archivo de texto.

### Funcionalidades principales

- **Consultar libros**: Muestra todos los libros registrados y su información.
- **Agregar libros**: Permite añadir nuevos libros a la biblioteca.
- **Buscar libros**: Busca libros por título y muestra sus detalles.
- **Cambiar estado de un libro**: Cambia el estado de disponibilidad de un libro específico.
- **Registro de sesión**: Al salir del programa, guarda la fecha y hora de la sesión en un archivo `registro.txt`.

## Estructura del código

- Uso de **clases** (`Libro`, `Biblioteca`) para organizar la información.
- Uso de **vectores** dinámicos para almacenar la colección de libros.
- Manejo de **archivos** para el registro de la sesión.
- Menú interactivo para una experiencia sencilla y amigable.

## Cómo ejecutar el programa

1. **Compila el programa** (por ejemplo, usando g++):
    ```bash
    g++ -o biblioteca biblioteca.cpp
    ```
2. **Ejecuta el archivo generado**:
    ```bash
    ./biblioteca
    ```
3. Sigue las instrucciones del menú para interactuar con el sistema.

## Requisitos

- Compilador C++ (g++, MinGW, etc.)
- Sistema operativo Windows, Linux o MacOS

## Notas

- El sistema almacena el registro de inicio/salida en `registro.txt`.
- Actualmente, los libros solo se guardan en memoria; si cierras el programa, se pierden los datos de los libros.

## Autor

- **JesusLuis493**  
  Segundo semestre de Ingeniería en Sistemas

---

¡Gracias por revisar mi proyecto! Si tienes sugerencias para mejorar el sistema, no dudes en dejar un comentario o abrir un pull request.