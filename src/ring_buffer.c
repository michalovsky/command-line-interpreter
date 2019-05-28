/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize)
{
	assert(ringBuffer);
	assert(dataBuffer);
	assert(dataBufferSize > 0);

	if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0))
	{
		ringBuffer->data = dataBuffer;
		ringBuffer->capacity = dataBufferSize;
		ringBuffer->length = 0;
		ringBuffer->tail = 0;
		ringBuffer->head = 0;
		return true;
	}

	return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
	assert(ringBuffer);

	if (ringBuffer)
	{
		memset(ringBuffer->data, 0, ringBuffer->capacity);
		ringBuffer->length = 0;
		ringBuffer->head = 0;
		ringBuffer->tail = 0;
		return true;
	}
	return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);

	return !ringBuffer->length;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);

	return ringBuffer->length;
}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
	assert(ringBuffer);

	return ringBuffer->capacity;
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
	assert(ringBuffer);

	if (ringBuffer && ringBuffer->length != ringBuffer->capacity)
	{
		ringBuffer->data[ringBuffer->head] = c;

		if (ringBuffer->head == ringBuffer->capacity - 1)
		{
			ringBuffer->head = 0;
		}
		else
		{
			ringBuffer->head++;
		}

		ringBuffer->length++;

		return true;
	}
	return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
	assert(ringBuffer);
	assert(c);

	if ((ringBuffer) && (c) && (ringBuffer->length))
	{
		*c = ringBuffer->data[ringBuffer->tail];

		if (ringBuffer->tail == ringBuffer->capacity - 1)
		{
			ringBuffer->tail = 0;
		}
		else
		{
			ringBuffer->tail++;
		}

		ringBuffer->length--;

		return true;
	}

	return false;
}


