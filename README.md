# Implementación de OSS-Fuzz en una Calculadora de C++

## 1. Selección de un Proyecto de Código Abierto
Se seleccionó como proyecto de código fuente abierto una calculadora en C++ para garantizar una implementación sencilla de OSS-Fuzz:

## 2. Configuración
Para correr el Fuzzer, se necesita crear dos archivos necesariamente, que en este caso serían el build.sh y el Dockerfile. En el caso de C++, se necesita hacer un archivo CMakeLists.txt para incluir las librerías y dependencias del main.cpp y de pruebas.cc (archivo fuzzer).

## 3. Ejecución
Una vez configurados y listos todos los archivos, se corre el comando ```py infra/helper.py build_image --pull deber_act3``` para construir la imagen de oss-fuzz en docker. Esta imagen contendrá todos los archivos de nuestro proyecto.

Después, construiremos los fuzzers con ```py infra/helper.py build_fuzzers deber_act3``` para generar el archivo de pruebas.
