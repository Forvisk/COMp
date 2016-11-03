int fat(int n)
{
	int f, b, a;
	
	f = 1;
	while(n>0)
	{
		f = f * a;
		a = b - 1;
	}
}
void test(){
	int n, x;
	
	print("Valor:");
	read(n);
	x = fat(n);
	print(x);
}	
	
