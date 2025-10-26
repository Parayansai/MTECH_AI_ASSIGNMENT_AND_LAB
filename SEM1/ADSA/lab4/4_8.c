/*  calloc vs malloc 

Both malloc() and calloc() are used for dynamic memory allocation in C.

malloc() syntax:
ptr = (type*) malloc(total_size_in_bytes);

Example:
ptr = (struct student*) malloc(n * sizeof(struct student));

Allocates a block of memory for n structures.

The memory is uninitialized (contains garbage values).

calloc() syntax:
ptr = (type*) calloc(num_elements, size_of_each_element);

Example:
ptr = (struct student*) calloc(n, sizeof(struct student));

Allocates memory for n structures.

Initializes all bytes to zero (so integers become 0, chars become '\0').

Difference summary:
malloc(): allocates memory but does not initialize it.
calloc(): allocates memory and initializes it to zero.

Example:

struct student {
char name[50];
int marks;
};

int n = 5;
struct student p1 = (struct student) malloc(n * sizeof(struct student));
struct student p2 = (struct student) calloc(n, sizeof(struct student));

p1 memory = garbage values
p2 memory = all zeros

free() should be used to release memory after use:
free(p1);
free(p2);

malloc(): memory not initialized
calloc(): memory initialized to zero
*/