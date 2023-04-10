/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 *
 * @n: A pointer to the number to modify.
 * @index: The index of the bit to clear (starting from 0).
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	// Check if the index is greater than or equal to the number of bits in unsigned long int.
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1UL << index;
	*n = (*n & ~mask) | ((unsigned long int) 0 << index);
	return (1);
}
