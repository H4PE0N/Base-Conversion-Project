
SOURCE_FOLDER := Source-Programs-Folder
OBJECT_FOLDER := Object-Programs-Folder
BINARY_FOLDER := Binary-Programs-Folder
HEADER_FOLDER := Header-Programs-Folder

SOURCE_PROGRAMS := $(wildcard $(SOURCE_FOLDER)/*.c)
HEADER_PROGRAMS := $(wildcard $(HEADER_FOLDER)/*.h)
OBJECT_PROGRAMS := $(patsubst $(SOURCE_FOLDER)/%.c, $(OBJECT_FOLDER)/%.o, $(SOURCE_PROGRAMS))

BINARY_PROGRAM := base-conversion-program

COMPILOR := gcc
COMP_FLAGS := -Wall -Werror

$(BINARY_FOLDER)/$(BINARY_PROGRAM): $(OBJECT_PROGRAMS)
	$(COMPILOR) $(COMP_FLAGS) $^ -o $@

$(OBJECT_FOLDER)/%.o: $(SOURCE_FOLDER)/%.c $(HEADER_FOLDER)/%.h
	$(COMPILOR) $(COMP_FLAGS) $< -c -o $@