//ejercicio 1.Desarrollar una funci�n para calcular el factorial de un entero
int obtenerFactorial(const int * num)
{
    int i,fac=1;
    for(i=1;i <= num ;i++)
    {
        fac*=i;
    }
    return fac;
}
// ejercicio 2. Desarrollar una funci�n para calcular el combinatorio m sobre n
int calculoCombinatorio(const int * m,const  int * n)
{
    int resul,aux1=m,aux2=n;
    resul= obtenerFactorial(m) / ( (obtenerFactorial(n)) * (obtenerFactorial(aux1 - aux2)) );
    return resul;
}
//ejercicio 10.Construir un programa que lea un n�mero natural N y calcule la suma de los primeros N n�meros naturales
int LeerYsumarNaturales(const int * num)
{
    int i,suma=0;
    for(i=1;i<=num;i++)
    {
        suma+=i;
    }
    return suma;
}
//ejercicio 11.Construir un programa que lea un n�mero natural N y calcule la suma de los primeros N n�meros pares
int LeerYsumarPares(const int * num)
{
    int i,suma=0;
    for(i=1;i<=num;i++)
    {
        if (i%2==0)
            suma+=i;
    }
    return suma;
}
//Construir un programa que lea un n�mero natural N y calcule la suma de los n�meros pares menores que N.
int LeerYsumarParesMenores(const int * num)
{
    int i,suma=0;
    for(i=1;i<num;i++)
    {
        if (i%2==0)
            suma+=i;
    }
    return suma;
}
//Desarrollar una funci�n que determine si un n�mero natural es primo
int EsUnNumeroPrimo(const int * num)
{
    int i=1,primo=1,cont,num1=num;
    while(primo==1 && i<=num1)
    {
        if(num1%i==0)
            cont++;
        if (cont>2)
            primo=-1;
        i++;
    }
    return primo;
}
