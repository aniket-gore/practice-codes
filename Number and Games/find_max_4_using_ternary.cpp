#define max2(a,b) (a>b?a:b)
#define max4(a,b,c,d) max2(max2(a,b),max2(c,d))

int find_max_4(int a, int b, int c, int d) {
	return max4(a,b,c,d);
}
