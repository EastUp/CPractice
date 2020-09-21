#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>

struct person{
	char name[24];
	int age;
};

void sys_err(const char *str){
	perror(str);
	exit(0);
}

int main(int argc, char *argv[]){
	int fd;
	struct person *p;
	fd = open("test_map", O_RDONLY);
	if (fd == -1)
		sys_err("open error");

	p = (person*)mmap(NULL, sizeof(person), PROT_READ, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED)
		sys_err("mmap error");
	while (1){
		printf("name = %s, age = %d\n", p->name, p->age);
		sleep(2);
	}
	munmap(p, sizeof(person));
	close(fd);
	return 0;
}

