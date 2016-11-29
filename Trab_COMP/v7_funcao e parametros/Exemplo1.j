.class public Exemplo1.j
.super java/lang/Object

.method public <init>()V
  aload_0

  invokevirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit local 4

  getstatic java/lang/System/out
  ldc "Valor de A:"
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  iconst_3
  istore 0
  getstatic java/lang/System/out
  ldc "Valor de B:"
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  iconst_3
  istore 1
  l1:	
  iload 0	
  iload 1	
  if_icmpne l2	
  goto l9
  l2:	
  iload 0	
  iload 1	
  if_cmpgt l4	
  goto l3
  l3:	
  iload 0	
  iload 1	
  if_icmpeq l4	
  goto l5
  l4:	
  iload 0	
  iload 1	
  isub	
  istore 0
  l5:	
  iload 1	
  iload 0	
  if_cmpgt l6	
  goto l7
  l6:	
  iload 1	
  iload 0	
  isub	
  istore 1	
  goto l8
  l7:	
  iload 1	
  iload 0	
  iadd	
  istore 1
  l8:	
  goto l1
  l9:	
  bipush 20	
  iload 0	
  iadd	
  istore 1	
  getstatic java/lang/System/out	
  ldc "\nRes="	
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V	
  getstatic java/lang/System/out	
  iload 0	
  invokevirtual java/io/PrintStream/println(I)V
  .return
.end method