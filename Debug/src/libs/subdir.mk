################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libs/parser.c \
../src/libs/sb_util.c 

OBJS += \
./src/libs/parser.o \
./src/libs/sb_util.o 

C_DEPS += \
./src/libs/parser.d \
./src/libs/sb_util.d 


# Each subdirectory must supply rules for building sources it contributes
src/libs/%.o: ../src/libs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


