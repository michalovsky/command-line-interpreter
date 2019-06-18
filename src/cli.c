#include "cli.h"
#include "usart.h"
#include <string.h>
#include <ctype.h>

// head of CLI command list
static CLI_CommandItem *head = NULL;

// char buffer where command will be stored
static char commandBuffer[100];

/**
 * This function searches the CLI command list and tries to find a descriptor for the provided command.
 * The command format is case-insensitive.
 * Returns pointer to @ref CLI_MenuItem structure if given command was found in the CLI command list.
 *
 * @param command pointer to command (string)
 *
 * @retval pointer to @ref CLI_MenuItem structure desrcibing the command, if command was found
 * @retval NULL if the given command does not match any command regitstered in the CLI command list
 */
static CLI_CommandItem* CLI_GetMenuItemByCommandName(char *command);

/**
 * @bref This function is responsible for collecting the command reading in from USART.
 *
 * This function should check wether the USART interface has some new data. If it does
 * this function reads new characters and stores them in a command buffer. This function
 * is also responsible for providing echo of the input characters back to the buffer.
 *
 * The function exits when:
 * - no more characters are available to read from USART - the function returns false
 * - new line was detected - this function returns true
 *
 * @retval true if command was collected
 * @retval false if command is yet incomplete
 */
static bool CLI_StoreCommand(void);

/**
 * @brief This function converts string to a lowercase
 *
 * @param dst pointer where converted null terminated string will be stored
 * @param src pointer to string which will be converted
 */
static void CLI_StringToLower(char *dst, const char *src);



void CLI_Proc(void){
	//todo
}

bool CLI_AddCommand(CLI_CommandItem *item){
	//todo
	return false;
}

void CLI_PrintAllCommands(void){
	//todo
}

CLI_CommandItem* CLI_GetMenuItemByCommandName(char *command){
	//todo

	return NULL;
};

void CLI_StringToLower(char *dst, const char *src){
	//todo proszÄ wykorzystaÄ funkcje z biblioteki ctype.h
}

bool CLI_StoreCommand(){
	//todo

	return false;
}
