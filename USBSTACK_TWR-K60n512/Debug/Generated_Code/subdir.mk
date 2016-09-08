################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/CDC1.c \
../Generated_Code/CS1.c \
../Generated_Code/CS2.c \
../Generated_Code/Cpu.c \
../Generated_Code/LED1.c \
../Generated_Code/LED2.c \
../Generated_Code/LED3.c \
../Generated_Code/LED4.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/LEDpin2.c \
../Generated_Code/LEDpin3.c \
../Generated_Code/LEDpin4.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Rx1.c \
../Generated_Code/Tx1.c \
../Generated_Code/USB0.c \
../Generated_Code/USB1.c \
../Generated_Code/Vectors.c \
../Generated_Code/usb_cdc.c \
../Generated_Code/usb_cdc_pstn.c \
../Generated_Code/usb_class.c \
../Generated_Code/usb_dci_kinetis.c \
../Generated_Code/usb_descriptor.c \
../Generated_Code/usb_driver.c \
../Generated_Code/usb_framework.c \
../Generated_Code/wdt_kinetis.c 

OBJS += \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/CDC1.o \
./Generated_Code/CS1.o \
./Generated_Code/CS2.o \
./Generated_Code/Cpu.o \
./Generated_Code/LED1.o \
./Generated_Code/LED2.o \
./Generated_Code/LED3.o \
./Generated_Code/LED4.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/LEDpin2.o \
./Generated_Code/LEDpin3.o \
./Generated_Code/LEDpin4.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Rx1.o \
./Generated_Code/Tx1.o \
./Generated_Code/USB0.o \
./Generated_Code/USB1.o \
./Generated_Code/Vectors.o \
./Generated_Code/usb_cdc.o \
./Generated_Code/usb_cdc_pstn.o \
./Generated_Code/usb_class.o \
./Generated_Code/usb_dci_kinetis.o \
./Generated_Code/usb_descriptor.o \
./Generated_Code/usb_driver.o \
./Generated_Code/usb_framework.o \
./Generated_Code/wdt_kinetis.o 

C_DEPS += \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/CDC1.d \
./Generated_Code/CS1.d \
./Generated_Code/CS2.d \
./Generated_Code/Cpu.d \
./Generated_Code/LED1.d \
./Generated_Code/LED2.d \
./Generated_Code/LED3.d \
./Generated_Code/LED4.d \
./Generated_Code/LEDpin1.d \
./Generated_Code/LEDpin2.d \
./Generated_Code/LEDpin3.d \
./Generated_Code/LEDpin4.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Rx1.d \
./Generated_Code/Tx1.d \
./Generated_Code/USB0.d \
./Generated_Code/USB1.d \
./Generated_Code/Vectors.d \
./Generated_Code/usb_cdc.d \
./Generated_Code/usb_cdc_pstn.d \
./Generated_Code/usb_class.d \
./Generated_Code/usb_dci_kinetis.d \
./Generated_Code/usb_descriptor.d \
./Generated_Code/usb_driver.d \
./Generated_Code/usb_framework.d \
./Generated_Code/wdt_kinetis.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/kim/workspace.kds/USBSTACK/Static_Code/PDD" -I"/home/kim/workspace.kds/USBSTACK/Static_Code/IO_Map" -I"/home/kim/workspace.kds/USBSTACK/Sources" -I"/home/kim/workspace.kds/USBSTACK/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


