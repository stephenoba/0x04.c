#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned long next = 1;

/**
 * _rand - custom rand function that generates random numbers from 33 - 122
 *
 * Return: random number
 */
int _rand(void)
{
	unsigned int value;

	next = next * 1103515245 + 12345;
	value = (unsigned int)(next / 65536) % 123;
	if (value >= 33)
		return (value);
	return (_rand());
}

/**
 * _srand - custom implementation of srand
 *
 * @seed: Seed to generate random number
 */
void _srand(unsigned int seed)
{
	next = seed;
}

/**
 * main - generates a key whose ASCII value adds up to 0xAD4
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	int ascii_total, i, diff;
	int r;
	time_t seed = time(NULL);

	_srand(seed);
	ascii_total = i = 0;
	/* 
	 * ensure that random numbers generated don't exceed a total
	 * of 2772
	 */
	while (ascii_total <= 0xAD4 - 0x7A)
	{
		r = (int)_rand();
		printf("%c", r);
		ascii_total += r;
		i++;
	}
	/* get the difference left and generate remaining characters */
	diff = (0xAD4 - ascii_total);
	printf("%c", diff);
	exit(EXIT_SUCCESS);
}
