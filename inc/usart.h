/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _USART_H_
#define _USART_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Function prototypes ------------------------------------------------------- */

/** Initializes the USART interface.
 *  @return true if the initialization was successfull and the port is operational,
 *          false otherwise
 */
bool USART_Init(void);

/**
 * Appends a single character to the usart buffer and enables the
 * TXE interrupt so the data can be sent away.
 *
 * @param c character to add
 * @return true if the character was added successfully, false otherwise
*/
bool USART_PutChar(char c);

/**
 * Appends contents of a data buffer to the usart transmit buffer and triggers transmision.
 *
 * @param data pointer to the source memory buffer
 * @param dataSize size (in bytes) of the data buffer
 * @return number of bytes sucessfully written to the usart transmit buffer
*/
size_t USART_WriteData(const void *data, size_t dataSize);

/**
 * Appends a null-terminated string to the usart transmit buffer and triggers transmision.
 *
 * @param string pointer to null-terminated string
 * @return number of characters sucessfully written to the usart transmit buffer
*/
size_t USART_WriteString(const char *string);

/**
 * Pulls out a single character from the usart receive buffer.
 *
 * @param c pointer to a variable, where the readed character will be stored
 * @return true if the character was pulled out successfully, false otherwise
*/
bool USART_GetChar(char *c);

/**
 * Pulls out characters from the usart buffer and stores them into a destination buffer.
 *
 * @param data pointer to memory where readed characters will be stored
 * @param maxSize maximum numbers of characters that can be read
 * @return number of read characters
*/
size_t USART_ReadData(char *data, size_t maxSize);

/**
 * Sets a pointer to a function that will be called when a newline character is be
 * received by usart device. The callback will be called from within and interrupt
 * service routine.
 *
 * @param callback pointer to a newline handler function
 * @return true if callback was added succesfully or false when error ocurred
*/
bool USART_SetCallback_OnNewLine(int TODO);	// todo: define the argument - callback type

#endif // _USART_H_
