# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude
LDFLAGS =

# Diretórios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fonte
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Nome do executável
TARGET = $(BIN_DIR)/tetris_stack

# Regra principal
all: directories $(TARGET)

# Cria diretórios necessários
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Regra para criar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Compilacao concluida! Execute com: ./$(TARGET)"

# Regra para compilar arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Arquivos temporarios removidos."

# Executa o programa
run: all
	./$(TARGET)

# Dependências
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/nivel_basico.h $(INC_DIR)/nivel_intermediario.h $(INC_DIR)/nivel_avancado.h
$(OBJ_DIR)/peca.o: $(SRC_DIR)/peca.c $(INC_DIR)/peca.h
$(OBJ_DIR)/fila.o: $(SRC_DIR)/fila.c $(INC_DIR)/fila.h $(INC_DIR)/peca.h
$(OBJ_DIR)/pilha.o: $(SRC_DIR)/pilha.c $(INC_DIR)/pilha.h $(INC_DIR)/peca.h
$(OBJ_DIR)/nivel_basico.o: $(SRC_DIR)/nivel_basico.c $(INC_DIR)/nivel_basico.h $(INC_DIR)/fila.h $(INC_DIR)/peca.h
$(OBJ_DIR)/nivel_intermediario.o: $(SRC_DIR)/nivel_intermediario.c $(INC_DIR)/nivel_intermediario.h $(INC_DIR)/fila.h $(INC_DIR)/pilha.h $(INC_DIR)/peca.h
$(OBJ_DIR)/nivel_avancado.o: $(SRC_DIR)/nivel_avancado.c $(INC_DIR)/nivel_avancado.h $(INC_DIR)/fila.h $(INC_DIR)/pilha.h $(INC_DIR)/peca.h

.PHONY: all clean run directories