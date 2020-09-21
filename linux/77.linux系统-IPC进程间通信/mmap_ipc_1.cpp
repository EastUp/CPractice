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
	struct person stu = { "Darren", 25 };
	struct person *p;
	fd = open("test_map", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		sys_err("open error");

	ftruncate(fd, sizeof(stu));

	p = (person*)mmap(NULL, sizeof(stu), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED)
		sys_err("mmap error");
	while (1){
		memcpy(p, &stu, sizeof(stu));
		stu.age++;
		sleep(1);
	}

	munmap(p, sizeof(stu));
	close(fd);
	return 0;
}
