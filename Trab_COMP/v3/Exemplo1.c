{
	int a, b, c;
	
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
	b = 4;
	print("\nRes=");
	print(a);
}
	