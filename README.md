# Ejemplos de Manejo de Archivos de Texto en C++

Este repositorio contiene ejemplos educativos progresivos sobre el manejo de archivos de texto en C++, diseñados para el curso de Programación Avanzada. Todos los comentarios están en español y utilizan comentarios de bloque donde es apropiado para mejorar la comprensión.

## 📋 Tabla de Contenidos

- [Descripción del Proyecto](#descripción-del-proyecto)
- [Archivos de Ejemplo](#archivos-de-ejemplo)
- [Estructuras de Datos](#estructuras-de-datos)
- [Archivos de Prueba](#archivos-de-prueba)
- [Compilación y Ejecución](#compilación-y-ejecución)
- [Conceptos Clave](#conceptos-clave)
- [Patrones de Uso](#patrones-de-uso)
- [Ejercicios Propuestos](#ejercicios-propuestos)

## 📖 Descripción del Proyecto

Este proyecto educativo demuestra el procesamiento de archivos de texto en C++ con un enfoque progresivo que va desde operaciones básicas hasta el manejo complejo de datos estructurados. Los ejemplos están diseñados para enseñar:

- Operaciones fundamentales de entrada/salida de archivos
- Manejo de errores en operaciones de archivos
- Diferentes modos de apertura de archivos
- Procesamiento de datos estructurados (CSV)
- Filtrado y ordenamiento de información

## 📁 Archivos de Ejemplo

### 1. **1_reading_text_files.cpp**
**Objetivo**: Introducción a la lectura de archivos de texto

**Conceptos cubiertos**:
- Uso de `fstream` para operaciones de archivo
- Apertura de archivos en modo lectura (`ios::in`)
- Verificación de errores con `file.fail()`
- Lectura línea por línea con `getline()`
- Cierre apropiado de archivos

**Datos de entrada**: `example_reading.txt` (lista de películas en formato CSV)

### 2. **2_reading_text_files_alternative.cpp**
**Objetivo**: Método alternativo de lectura usando el operador `>>`

**Conceptos cubiertos**:
- Lectura palabra por palabra con el operador `>>`
- Uso de `file.eof()` para detectar fin de archivo
- Comparación con el método `getline()`
- Manejo de espacios en blanco

**Datos de entrada**: `example_reading_with_spaces.txt`

### 3. **3_writing_text_files_basic.cpp**
**Objetivo**: Escritura básica en archivos de texto

**Conceptos cubiertos**:
- Apertura de archivos en modo escritura (`ios::out`)
- Uso del operador `<<` para escribir
- Comportamiento de sobrescritura por defecto
- Importancia del cierre de archivos

**Salida**: `example_writing.txt`

### 4. **4_writing_text_files_append_1.cpp**
**Objetivo**: Demostración del comportamiento de sobrescritura

**Conceptos cubiertos**:
- Efecto de múltiples aperturas en modo `ios::out`
- Pérdida de datos al sobrescribir
- Comparación entre escritura y sobrescritura

**Salida**: `example_writing_append_1.txt`

### 5. **5_writing_text_files_append_2.cpp**
**Objetivo**: Agregado de contenido sin pérdida de datos

**Conceptos cubiertos**:
- Modo de agregado (`ios::app`)
- Combinación de modos (`ios::out | ios::app`)
- Preservación de contenido existente
- Mejores prácticas para logs y archivos de salida

**Salida**: `example_writing_append_2.txt`

### 6. **6_movies_example.cpp**
**Objetivo**: Ejemplo práctico con procesamiento de datos estructurados

**Conceptos cubiertos**:
- Integración con estructuras de datos personalizadas
- Procesamiento de archivos CSV
- Filtrado de datos (calificación > 80)
- Ordenamiento múltiple (año y calificación)
- Generación de reportes formateados

**Datos de entrada**: `example_reading.txt` (87 películas con datos reales)

## 🏗️ Estructuras de Datos

### Movie.hh
Estructura central para el manejo de datos de películas:

```cpp
struct Movie {
    int id;           // Identificador único
    int year;         // Año de lanzamiento
    int rating;       // Calificación (0-100)
    char title[256];  // Título (array de tamaño fijo)
}
```

**Características importantes**:
- Uso de arrays de tamaño fijo en lugar de `std::string`
- Implementación de `equals()` y `operator==`
- Función `getMovieFromLine()` para parsing de CSV (incompleta - ejercicio)
- Función `getLineFromMovie()` para serialización

### TextFileHandler.hh
Utilidades para manejo de archivos (estructura preparada para implementación):

```cpp
struct Lines {
    char lines[100][256];  // Array de líneas
    int size;              // Número de líneas
}

struct TextFileHandler {
    // Implementación pendiente
}
```

## 📄 Archivos de Prueba

- **example_reading.txt**: Dataset principal con 87 películas (1968-2016)
- **example_reading_with_spaces.txt**: Datos para probar lectura con espacios

**Formato de datos CSV**:
```
id;year;rating;title
1;1994;90;The Shawshank Redemption
2;1972;90;The Godfather
```

## 🔧 Compilación y Ejecución

### Compilación Manual
```bash
# Compilar un archivo específico
g++ -fcolor-diagnostics -fansi-escape-codes -g <filename>.cpp -o <executable>
clang++ -fcolor-diagnostics -fansi-escape-codes -g 1_reading_text_files.cpp -o 1_reading_text_files

# Ejecutar
./1_reading_text_files

# Para archivos que usan las librerías
g++ -fcolor-diagnostics -fansi-escape-codes -g 6_movies_example.cpp libs/Movie.hh libs/TextFileHandler.hh -o 6_movies_example
clang++ -fcolor-diagnostics -fansi-escape-codes -g 6_movies_example.cpp -o 6_movies_example
```

### Requisitos del Sistema
- Compilador C++ compatible (clang++, g++)
- Soporte para C++11 o superior
- VS Code con extensión C/C++ (recomendado)

## 💡 Conceptos Clave

### 1. **Streams de Archivo**
- `fstream`: Lectura y escritura
- `ifstream`: Solo lectura
- `ofstream`: Solo escritura

### 2. **Modos de Apertura**
- `ios::in`: Lectura
- `ios::out`: Escritura (sobrescribe)
- `ios::app`: Agregado (preserva contenido)
- Combinaciones: `ios::out | ios::app`

### 3. **Manejo de Errores**
```cpp
if (file.fail()) {
    cerr << "Error opening file" << endl;
    exit(1);
}
```

### 4. **Patrones de Lectura**
```cpp
// Línea completa
file.getline(line, 256);

// Palabra por palabra
file >> word;

// Hasta fin de archivo
while (!file.eof()) { ... }
```

### 5. **Gestión de Memoria**
- Uso preferente de arrays de tamaño fijo
- `strncpy()` para manejo seguro de strings
- `strncmp()` para comparaciones

## 🔄 Patrones de Uso

### Lectura Segura de Archivos
```cpp
fstream file;
file.open(fileName, ios::in);
if (file.fail()) {
    cerr << "Error opening file" << endl;
    exit(1);
}
// ... operaciones de lectura
file.close();
```

### Escritura con Verificación
```cpp
fstream file;
file.open(fileName, ios::out);
if (file.fail()) {
    cerr << "Error opening file" << endl;
    exit(1);
}
file << "Contenido" << endl;
file.close();
```

### Procesamiento de CSV
```cpp
while (file.getline(line, 256)) {
    // Parsear línea usando delimitador ';'
    // Crear objeto Movie
    // Procesar datos
}
```

## 📚 Ejercicios Propuestos

### Nivel Básico
1. **Completar `getMovieFromLine()`**: Implementar el parsing de líneas CSV
2. **Contador de líneas**: Crear programa que cuente líneas en un archivo
3. **Filtro personalizado**: Filtrar películas por año específico

### Nivel Intermedio
4. **Ordenamiento múltiple**: Implementar ordenamiento por diferentes criterios
5. **Estadísticas**: Calcular promedio, mediana y moda de calificaciones
6. **Búsqueda**: Implementar búsqueda por título (parcial o completa)

### Nivel Avanzado
7. **Agrupamiento**: Agrupar películas por década
8. **Exportación**: Generar reportes en diferentes formatos
9. **Validación**: Implementar validación de datos de entrada
10. **Optimización**: Mejorar rendimiento para archivos grandes

### Proyectos Integradores
- **Sistema de biblioteca**: Gestión completa de catálogo de películas
- **Análisis temporal**: Tendencias de calificaciones a través del tiempo
- **Recomendaciones**: Sistema básico de recomendación basado en calificaciones

## 🎯 Objetivos de Aprendizaje

Al completar estos ejemplos, los estudiantes deberían poder:

1. **Manejar archivos** de texto de manera segura y eficiente
2. **Procesar datos** estructurados en formato CSV
3. **Implementar filtros** y ordenamientos básicos
4. **Generar reportes** formateados
5. **Gestionar memoria** usando arrays de tamaño fijo
6. **Aplicar buenas prácticas** de programación en C++
7. **Debuggear problemas** comunes con archivos

## 📝 Notas Importantes

- Todos los comentarios están en español para facilitar el aprendizaje
- Se utiliza programación estructurada (no orientada a objetos)
- Los ejemplos progresan en complejidad gradualmente
- Se enfatiza el manejo seguro de memoria y archivos
- Los datos de prueba son reales para mayor realismo
