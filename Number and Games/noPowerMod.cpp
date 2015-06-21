/*
calculate (x^y)%z without pow();
*/
int NoPowMod(int x, int y, int z) {
	int a = x % z;
	int t = 1;
	while(y) {
		if(y & 1)
			t = (t * a) % z;
		y >>= 1;
		a = (a * a) % z;
	}
	return t;
}