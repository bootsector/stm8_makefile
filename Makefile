CC = /Applications/sdcc-3.8.0/bin/sdcc
ASM = /Applications/sdcc-3.8.0/bin/sdasstm8
OBJCOPY = /Applications/sdcc-3.8.0/bin/sdobjcopy
RM = rm -f

DEVICE = stm8s103f3

TARGET = BLINK

SRC_MAIN = main.c
SRC_OTHERS = delay.c
SRC_ASM =

OBJ_OTHERS = $(SRC_OTHERS:%.c=%.rel)
OBJ_ASM = $(SRC_ASM:%.s=%.rel)

INCLUDE = -I .
PARAMS = -lstm8 -mstm8 --opt-code-size --std-sdcc11

all: sdccversion build

sdccversion:
	@$(CC) -v

%.rel : %.c
	${CC} -c ${INCLUDE} ${PARAMS} $< $(OBJ_ASM)

%.rel : %.s
	${ASM} -l -o $<

$(TARGET).ihx: $(OBJ_ASM) $(OBJ_OTHERS) 
	${CC} ${SRC_MAIN} ${INCLUDE} ${PARAMS} ${OBJ_ASM} ${OBJ_OTHERS} --out-fmt-ihx -o ${TARGET}.ihx

$(TARGET).bin: $(TARGET).ihx
	${OBJCOPY} -I ihex ${TARGET}.ihx -O binary ${TARGET}.bin

build: $(TARGET).ihx

flash: $(TARGET).ihx
	stm8flash -c stlinkv2 -p ${DEVICE} -w $(TARGET).ihx

clean:
	${RM} *.asm *.cdb *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.rst *.bin
