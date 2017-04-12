#include <stdint.h>
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

void PrintBytes(const uint8_t Bytes[], const uint32_t NumBytes)
{
  for (uint32_t i = 0; i < NumBytes; ++i)
  {
    printf("%d:0x"BYTE_TO_BINARY_PATTERN"\n", i, BYTE_TO_BINARY(*(Bytes + i)));
  }
}

void PrintBytes(const int8_t Bytes[], const uint32_t NumBytes)
{
  for (uint32_t i = 0; i < NumBytes; ++i)
  {
    printf("%d:0x"BYTE_TO_BINARY_PATTERN"\n", i, BYTE_TO_BINARY(*(Bytes + i)));
  }
}

uint8_t Reverse(uint8_t Bits)
{
  Bits = (Bits & 0xf0) >> 4 | (Bits & 0x0f) << 4;
  Bits = (Bits & 0xcc) >> 2 | (Bits & 0x33) << 2;
  Bits = (Bits & 0xaa) >> 1 | (Bits & 0x55) << 1;
  return Bits;
}

void ReverseBits(int8_t Data[], uint32_t NumberOfBitsToReverse)
{
	// Reverse the first NumberOfBitsToReverse in the specified array, leaving
    // the remainder unchanged.
    // You may assume the array will always be adequately sized to support the        
    // input.

    if (NumberOfBitsToReverse <= 0)
    {
    	return;
    }

    uint8_t extractedBits[NumberOfBitsToReverse / 8];

    // extract the desired number of bits from the input
    for (uint32_t i = 0; i < NumberOfBitsToReverse; ++i)
    {
      // clear this bucket
      if (i % 8 == 0)
      {
        *(extractedBits + i/8) = 0;
      }

      // extract one bit
    	*(extractedBits + i/8) = *(extractedBits + i/8) | (*(Data + i/8) & (1 << (i%8)));
    }

    printf("\nPrinting extracted bytes:\n");
    PrintBytes(extractedBits, NumberOfBitsToReverse / 8);

    // feed the extracted bits into the input in reverse order
    for (uint32_t i = 0; i < NumberOfBitsToReverse / 8; ++i)
    {
      uint32_t sourceBucketIndex = (NumberOfBitsToReverse / 8 - 1) - i;

      *(Data + i) = 0;
      *(Data + i) = *(Data + i) | Reverse(*(extractedBits + sourceBucketIndex));
    }

    printf("\nPrinting input with bits reversed:\n");
    PrintBytes(Data, NumberOfBitsToReverse / 8);
}

int main()
{
  int8_t Data[8] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xff };
  
  printf("Input:");
  for (uint8_t i = 0; i < 8; ++i)
  {
    printf("0x%02x ", Data[i]);
  }

  ReverseBits(Data, 24);

  printf("\nOutput:");
  for (uint8_t i = 0; i < 8; ++i)
  {
    printf("0x%02x ", Data[i]);
  }
  printf("\n");
}