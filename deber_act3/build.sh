#!/bin/bash -eu

# Verifica que las variables de entorno necesarias estén definidas
: "${CXX:?Variable CXX no definida}"
: "${CXXFLAGS:?Variable CXXFLAGS no definida}"
: "${LIB_FUZZING_ENGINE:?Variable LIB_FUZZING_ENGINE no definida}"
: "${OUT:?Variable OUT no definida}"

# Compila el proyecto
mkdir -p build
cd build
cmake ..
make

# Compila el fuzzer como una biblioteca compartida
$CXX $CXXFLAGS -I.. -fPIC -c ../pruebas.cc -o pruebas.o
$CXX $CXXFLAGS -shared pruebas.o $LIB_FUZZING_ENGINE -o libfuzzer.so -lpthread

# Copia la biblioteca compartida del fuzzer al directorio de salida
cp libfuzzer.so $OUT/