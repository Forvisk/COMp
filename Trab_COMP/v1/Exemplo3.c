int fat(int n)
{
	int f;
	
	f = 1;
	while(n>0)
	{
		f = f * n;
		n = n - 1;
	}
}
String ok(){
	int n, x;
	
	print("Valor:");
	read(n);
	x = fat(n);
	print(x);

	return "ha";
}	
	