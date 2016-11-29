
int fat(int k){
	while( k < 10){
		k = k + 1;
	}
	return k;
}
void test(){
	int n, x;
	
	print("Valor:");
	read(n);
	x = fat(n);
	print(x);
}
	
