GPP = g++
NAME = calculator-app
LINKER_FLAGS = -Wall
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(OBJ_DIR)/main.o \
 	  $(OBJ_DIR)/symbol.o \
 	  $(OBJ_DIR)/operand.o \
	  $(OBJ_DIR)/number.o \
	  $(OBJ_DIR)/constant.o \
	  $(OBJ_DIR)/variable.o \
	  $(OBJ_DIR)/function.o \
	  $(OBJ_DIR)/unary_function.o \
	  $(OBJ_DIR)/binary_function.o \
	  $(OBJ_DIR)/token.o \
	  $(OBJ_DIR)/parser.o \
	  $(OBJ_DIR)/evaluator.o \
	  $(OBJ_DIR)/includes.o
	 
OBJ_PATH = ./$(OBJ_DIR)/
SRC_PATH = ./$(SRC_DIR)/


$(NAME): $(OBJ_DIR) $(OBJ)
	$(GPP) $(OBJ_PATH)*.o $(LINKER_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_PATH)main.o: $(SRC_PATH)main.cpp
	$(GPP) -c -o $@ $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(SRC_PATH)%.hpp
	$(GPP) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	rm $(NAME)
