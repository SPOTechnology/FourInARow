################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/alphabetaMove.cpp \
../src/benimaxMove.cpp \
../src/canEnd.cpp \
../src/checkState.cpp \
../src/compare.cpp \
../src/main.cpp \
../src/minimaxMove.cpp \
../src/neuralMove.cpp \
../src/playGame.cpp \
../src/possibleMove.cpp \
../src/printBoard.cpp \
../src/random.cpp \
../src/readWeights.cpp \
../src/refPointers.cpp 

OBJS += \
./src/alphabetaMove.o \
./src/benimaxMove.o \
./src/canEnd.o \
./src/checkState.o \
./src/compare.o \
./src/main.o \
./src/minimaxMove.o \
./src/neuralMove.o \
./src/playGame.o \
./src/possibleMove.o \
./src/printBoard.o \
./src/random.o \
./src/readWeights.o \
./src/refPointers.o 

CPP_DEPS += \
./src/alphabetaMove.d \
./src/benimaxMove.d \
./src/canEnd.d \
./src/checkState.d \
./src/compare.d \
./src/main.d \
./src/minimaxMove.d \
./src/neuralMove.d \
./src/playGame.d \
./src/possibleMove.d \
./src/printBoard.d \
./src/random.d \
./src/readWeights.d \
./src/refPointers.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


