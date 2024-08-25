FROM gcr.io/oss-fuzz-base/base-builder

RUN apt-get update && apt-get install -y make cmake g++

# Copiar los archivos necesarios al contenedor
COPY pruebas.cc $SRC/deber_act3/
COPY main.cpp $SRC/deber_act3/
COPY calculadora.h $SRC/deber_act3/
COPY CMakeLists.txt $SRC/deber_act3/
COPY build.sh $SRC/

WORKDIR $SRC/deber_act3

# Definir el lenguaje de fuzzing y compilar libFuzzer
ENV FUZZING_LANGUAGE=c++
RUN compile_libfuzzer

# Ejecutar el script de construcción
RUN $SRC/build.sh