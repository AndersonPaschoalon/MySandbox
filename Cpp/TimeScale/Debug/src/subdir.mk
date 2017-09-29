################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AbsClass.cpp \
../src/BaseClass.cpp \
../src/D1Class.cpp \
../src/D2Class.cpp \
../src/Main.cpp 

OBJS += \
./src/AbsClass.o \
./src/BaseClass.o \
./src/D1Class.o \
./src/D2Class.o \
./src/Main.o 

CPP_DEPS += \
./src/AbsClass.d \
./src/BaseClass.d \
./src/D1Class.d \
./src/D2Class.d \
./src/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


