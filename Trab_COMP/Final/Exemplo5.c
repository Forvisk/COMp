int main( int k){
	int a, b;
	String nome;
	int s;
	
	print("Valor de A:");
	read(a);
	print("Valor de B:");
	read(b);
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		if (b > a)
		{
			b = b - a;
		}
	}
	print("\nRes=");
	print(a);
}
	
