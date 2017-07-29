################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Database.cpp \
../src/Main.cpp \
../src/RegressionTests.cpp \
../src/TraceDbManager.cpp 

OBJS += \
./src/Database.o \
./src/Main.o \
./src/RegressionTests.o \
./src/TraceDbManager.o 

CPP_DEPS += \
./src/Database.d \
./src/Main.d \
./src/RegressionTests.d \
./src/TraceDbManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


