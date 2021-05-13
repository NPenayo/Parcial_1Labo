################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Arrays.c \
../src/Income.c \
../src/Menu.c \
../src/Taxpayer.c \
../src/Validations.c \
../src/parcial1_labo.c 

OBJS += \
./src/Arrays.o \
./src/Income.o \
./src/Menu.o \
./src/Taxpayer.o \
./src/Validations.o \
./src/parcial1_labo.o 

C_DEPS += \
./src/Arrays.d \
./src/Income.d \
./src/Menu.d \
./src/Taxpayer.d \
./src/Validations.d \
./src/parcial1_labo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


