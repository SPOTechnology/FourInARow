################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/benimaxMove.cpp \
../src/canEnd.cpp \
../src/checkState.cpp \
../src/main.cpp \
../src/neuralMove.cpp \
../src/playGame.cpp \
../src/possibleMove.cpp \
../src/printBoard.cpp \
../src/random.cpp \
../src/refPointers.cpp \
../src/resetBoard.cpp \
../src/writeFile.cpp 

OBJS += \
./src/benimaxMove.o \
./src/canEnd.o \
./src/checkState.o \
./src/main.o \
./src/neuralMove.o \
./src/playGame.o \
./src/possibleMove.o \
./src/printBoard.o \
./src/random.o \
./src/refPointers.o \
./src/resetBoard.o \
./src/writeFile.o 

CPP_DEPS += \
./src/benimaxMove.d \
./src/canEnd.d \
./src/checkState.d \
./src/main.d \
./src/neuralMove.d \
./src/playGame.d \
./src/possibleMove.d \
./src/printBoard.d \
./src/random.d \
./src/refPointers.d \
./src/resetBoard.d \
./src/writeFile.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


