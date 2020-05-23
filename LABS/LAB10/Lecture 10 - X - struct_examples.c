#include <stdio.h>


typedef struct {
	int x, y, z;
	char name[200];
} Point3D;


typedef struct {
	int x[6];
} Point6D;


Point3D p3_random_v() {
	Point3D p;
	p.x = rand() % 256;
	p.y = rand() % 256;
	p.z = rand() % 256;
	sprintf(p.name,"R%d", rand() % 1000); 
	return p;
}


void p3_random_r(Point3D * p) {
	p->x = rand() % 256;
	p->y = rand() % 256;
	p->z = rand() % 256;
	sprintf(p->name,"R%d", rand() % 1000); 
}


void printv(Point3D p) {
	printf("%s: [%d, %d, %d]\n", p.name, p.x, p.y, p.z);
}

void printp(Point3D * p) {
	printf("%s: [%d, %d, %d]\n", p->name, p->x, p->y, p->z);
}


void main(void) {
	
	Point3D p1, p2, p3, p4, p = {0,0,0,"Noname"};
	Point3D2 a;
	printv(p);
	printp(&p);
	p1 = p3_random_v();
	p3_random_r(&p1);
	p2 = p3_random_v();
	printv(p1);
	printv(p2);
}

