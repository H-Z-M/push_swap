#ifndef LEAKDETECT_H
# define LEAKDETECT_H
# include <stdlib.h>

#define malloc(s) leak_detect_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

typedef struct
{
	void *p;
	size_t size;
	const char *file;
	unsigned int line;
} MEM_T;

void leak_detect_init(void);
void *leak_detect_malloc(size_t, const char*, unsigned int);
void leak_detect_free(void*);
void leak_detect_check(void);

#endif
