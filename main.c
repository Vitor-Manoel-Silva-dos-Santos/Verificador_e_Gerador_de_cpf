#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
void obter_cpf( void );
int validar_cpf( void );
int gerador_cpf();
char cpf[ 11 ];

int main()
{
    gerador_cpf();
    setlocale( LC_ALL, "Portuguese" );
    obter_cpf();
    if ( validar_cpf() )
    {
        printf( "\n Esse é um CPF válido!\n\n" );
    }
    else
    {
        printf( "\n * * * CPF inválido !!! * * * \n\n" );
    }

    return 0;
}
        /*Função para pegar um cpf digitado: */
void obter_cpf()
{
    int pos= 0;
    char caractere;
    printf( "\n Digite um CPF ( apenas números ): " );
    while ( 1 )
    {
        caractere = getch();
        if ( pos < 11 && caractere >= '0' && caractere <= '9' )
        {
            putchar( caractere );
            cpf[ pos++ ]= caractere;
        }
        if ( pos == 11 && caractere == '\r' )
        {
            break;
        }
        if ( pos > 0 && caractere == '\b' )
        {
             --pos;
             putchar( '\b' );
             putchar( ' ' );
             putchar( '\b' );
        }
    }
    printf( "\n\n CPF Digitado: " );
    for ( int i = 0; i < 11; i++)
    {
        putchar( cpf[ i ] );
        if ( i == 2 || i == 5 )
    {
    putchar( '.' );
    }
    if ( i == 8 )
    {
        putchar( '-' );
    }
    }
    puts( "\n" );
}
        /*Função que válida cpf: */
int validar_cpf( void )
{
    int soma= 0;

    for ( int i = 0; i < 11; i++ )
    {
        cpf[ i ]-= '0';/*Importante! Transforma a sequência de caracteres em dígitos!*/
    }

    for ( int i= 0, peso= 10; i < 9; i++, peso-- )
    {
        soma+= cpf[ i ] * peso;
    }
    if ( soma * 10 % 11 % 10 != cpf[ 9 ] )
    {
        return 0;
    }
 /*Primeiro dígito verificador correto!*/
    soma= 0;
    for ( int i= 0, peso= 11; i < 10; i++, peso-- )
    {
        soma+= cpf[ i ] * peso;
    }
    if ( soma * 10 % 11 % 10 != cpf[ 10 ] )
    {
        return 0;
    }
 /*Segundo dígito verificador correto!*/
    return 1;

}

int gerador_cpf(){
    int numero;
    char caractere;
    int pos = 9;
    char cpf[ 11 ];

    srand(time(NULL));/*torna o randomizador de numeros cada vez diferente*/

    for (int i = 0; i < 9; i++){
        numero = rand() % 10; /*randomizar um numero*/
        caractere = numero;
        cpf[i] = caractere;
    }

    int soma= 0;
    int digitocpf;
        /*Gerando o primeiro digito do cpf*/
    for ( int i= 0, peso= 10; i < 9; i++, peso-- )
    {
        soma+= cpf[ i ] * peso;
    }
    digitocpf = soma * 10 % 11;
    if (digitocpf == 10){
        digitocpf = 0;
    }
    cpf[9] = digitocpf;
        /*Gerando o segundo digito do cpf*/
    soma= 0;
    for ( int i= 0, peso = 11; i < 10; i++, peso-- )
    {
        soma+= cpf[ i ] * peso;
    }
    digitocpf = soma *10 % 11;
    if (digitocpf == 10){
        digitocpf = 0;
    }
    cpf[10] = digitocpf;

        /*Saida dos dados*/
    printf( "\n\n CPF Digitado: " );
    for ( int i = 0; i < 11; i++)
    {
        cpf[ i ]+= '0';
        putchar( cpf[ i ] );
        if ( i == 2 || i == 5 )
    {
        putchar( '.' );
    }
    if ( i == 8 )
    {
        putchar( '-' );
    }
    }
    puts( "\n" );
    return 0;
}
