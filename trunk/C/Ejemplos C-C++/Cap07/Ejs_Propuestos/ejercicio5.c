// Gestión del mantenimiento de electrodomésticos
// ejercicio5.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char Descripcion[80];  // Descripción del electrodoméstico
  int ValorCompra;       // Valor del electrodoméstico
  int ImpContrato;       // Importe del Contrato de mantenimiento
  char NumSerie[15];     // Número de serie del aparato
  char NumContrato[10];  // Número del Contrato
} tcon;

typedef struct 
{
  tcon *Contrato;        // Puntero a una estructura tcon
  int nContratosAct;     // Número actual de contratos por cliente
}tcontrato;

typedef struct 
{
  char Nombre[35];       // Nombre del cliente
  char Apellidos[55];    // Apellidos del cliente
  char Direccion[35];    // Dirección del cliente
  char Codigo[15];       // Código del cliente
  tcontrato ContratoCli; // Estructura de tipo tcontrato
}tcliente;

void DarDeAltaUnContrato(tcliente *pcliente, int );
int AutorizaReparacion(tcliente *pcliente, char [], int, int);
int BuscarPosicion(tcliente *pcliente, char Codigo[15], int);
void LiberarMemoria(tcliente *pcliente, int);
void Listar(tcliente *pcliente, int);

//------------Funciones complementarias-------------------//
void DatosContrato(tcliente *pcliente, int, int);
int menu();
void DatosCliente(tcliente *pcliente, int, int);
//------------Funciones complementarias-------------------//

main()
{
  tcliente *pcliente = NULL, *preasig = NULL;
  int numClientes = 0, n_cl = 0, op = 0, impReparacion = 0, cod = 0;
  char numSerie[15], codigo[15];

  while (1)
  {
    op = menu();

    switch (op)
    {
      case 1: // se autoriza o no la reparación
        printf("\nNúmero de serie: ");
        gets(numSerie);
        printf("\nCoste de la reparación: ");
        scanf("%d", &impReparacion);
        cod = AutorizaReparacion(pcliente, numSerie, numClientes, impReparacion);
        if (cod == 1)
          printf("\nSe autoriza la reparación");
        else
          printf("\nNo se autoriza la reparación");
        break;

      case 2: // buscar la posición en la matriz de un cliente
        printf("\nCódigo del cliente:  ");
        gets(codigo);
        n_cl = BuscarPosicion(pcliente, codigo, numClientes);
        if (n_cl == -1)
          printf("\nNo existe ese cliente");
        else
          printf("\nLa posición es: %d", n_cl);
        break;

      case 3: // dar de alta un contrato
        printf("\nPosición del cliente: ");
        scanf("%d", &n_cl);
        if (n_cl < 0 || n_cl >= numClientes)
        {
          printf("Índice fuera de límites\n");
          break;
        }
        fflush(stdin);
        DarDeAltaUnContrato(pcliente, n_cl);
        printf("\nEl contrato ha sido dado de alta");
        break;

      case 4: // introducir datos para uno o más clientes
        do
        {
          n_cl = 0;
          printf("\nNúmero de clientes: ");
          scanf("%d", &n_cl);
          fflush(stdin);
        }
        while (n_cl < 1);
        if ((preasig = realloc(pcliente, (numClientes + n_cl) * sizeof(tcliente))) == NULL)
        {
          printf("Insuficiente memoria para asignar\n");
          if ( pcliente == NULL) exit(0);
          // Si preasig == NULL, pcliente se conserva
        }
        else
          pcliente = preasig;
        DatosCliente(pcliente, numClientes, numClientes + n_cl);
        numClientes += n_cl;
        break;

      case 5: // visualizar los datos de todos los clientes
        Listar(pcliente, numClientes);
        break;

      case 6: // liberar la memoria reservada dinámicamente
        LiberarMemoria(pcliente, numClientes); 
        exit(0);
    }
  }
}


//------------Implementación--------------------

void DarDeAltaUnContrato(tcliente *pcliente, int i)
{
  tcon *q = pcliente[i].ContratoCli.Contrato, *p;
  int nconts = pcliente[i].ContratoCli.nContratosAct;

  p = realloc(q, (nconts + 1) * sizeof(tcon));
  if (p == NULL)
  {
    printf("Insuficiente memoria\n");
    if (q == NULL) exit(0);
  }
  pcliente[i].ContratoCli.Contrato = p;
  pcliente[i].ContratoCli.nContratosAct++;
  DatosContrato(pcliente, i, nconts);
}

void DatosContrato(tcliente *pcliente, int i, int pos)
{
  printf("\n\t---Datos Contrato %d ", pos + 1);
  printf("\nDescripción del aparato:  ");
  fflush(stdin);
  gets(pcliente[i].ContratoCli.Contrato[pos].Descripcion);
  
  printf("\nNúmero de serie:  ");
  gets(pcliente[i].ContratoCli.Contrato[pos].NumSerie);
  
  printf("\nNúmero del contrato:  ");
  gets(pcliente[i].ContratoCli.Contrato[pos].NumContrato);
  
  printf("\nImporte del contrato:  ");
  scanf("%d", &pcliente[i].ContratoCli.Contrato[pos].ImpContrato);
  
  printf("\nValor de la compra:  ");
  scanf("%d", &pcliente[i].ContratoCli.Contrato[pos].ValorCompra);
  fflush(stdin);
}

int BuscarPosicion(tcliente *pcliente, char *codigo, int numClientes)
{
  int i;

  for (i = 0; i < numClientes; i++)
    if (!strcmp(pcliente[i].Codigo, codigo))
      return i;

  return -1;
}

int AutorizaReparacion(tcliente *pcliente, char numSerie[15],
                       int numClientes, int impReparacion)
{
  int i, j;

  for (i = 0; i < numClientes; i++)
  {
    if (pcliente[i].ContratoCli.nContratosAct)
      for(j = 0; j < pcliente[i].ContratoCli.nContratosAct; j++)
      {
        if (!strcmp(pcliente[i].ContratoCli.Contrato[j].NumSerie, numSerie))
        {
          if (impReparacion <= (int)(0.25 * (pcliente[i].ContratoCli.Contrato[j].ValorCompra)))
            return 1;
          printf("\nEl importe de la reparación excede el 25% de la compra\n");
          return 0;
        }
      }
  }
  printf ("\nNo existe ese número de serie\n");
  return 2;
}

void LiberarMemoria(tcliente *pcliente, int numClientes)
{
  int i;

  for (i = 0; i < numClientes; i++)
    free(pcliente[i].ContratoCli.Contrato);
  free(pcliente);
}

void DatosCliente(tcliente *pcliente, int numClientesAct, int numCientesFinal)
{
  int i = 0, j = 0, conts = 0;

  for (i = numClientesAct; i < numCientesFinal; i++)
  {
    printf("\t\t-------Datos cliente  %d\n", i);
    printf("\nNombre: ");
    fflush(stdin);
    gets(pcliente[i].Nombre);
    
    printf("\nApellidos:  ");
    gets(pcliente[i].Apellidos);
    
    printf("\nDirección:  ");
    gets(pcliente[i].Direccion);
    
    printf("\nCódigo:  ");
    gets(pcliente[i].Codigo);

    printf("\nNúmero de contratos:   ");
    scanf("%d", &pcliente[i].ContratoCli.nContratosAct);
    fflush(stdin);

    conts = pcliente[i].ContratoCli.nContratosAct;
    if (conts == 0)
      pcliente[i].ContratoCli.Contrato = NULL;
    else
    {
      pcliente[i].ContratoCli.Contrato = (tcon *)malloc(conts *(sizeof(tcon)));
      for (j = 0; j < conts; j++)
        DatosContrato(pcliente, i, j);
    }
    printf("Pulse <Entrar> para continuar\n");
    getchar();
    fflush(stdin);
  }
}

void Listar(tcliente *pcliente, int numClientes)
{
  int i = 0, j = 0;

  for (i = 0; i < numClientes; i++)
  {
    printf("\n\t------ Cliente número %d  -------", i + 1);
    printf("\nNombre:  %s", pcliente[i].Nombre);
    printf("\nApellidos: %s", pcliente[i].Apellidos);
    printf("\nDirección:  %s", pcliente[i].Direccion);
    printf("\nCódigo:  %s", pcliente[i].Codigo);
      
    if (pcliente[i].ContratoCli.nContratosAct)
    {
      printf("\nTiene %d contratos", pcliente[i].ContratoCli.nContratosAct);
      for(j = 0; j < pcliente[i].ContratoCli.nContratosAct; j++)
      { 
        printf("\n\t----Datos del contrato %d", j + 1);
        printf("\nDescripción del aparato %s", pcliente[i].ContratoCli.Contrato[j].Descripcion);
        printf("\nNúmero de serie  %s", pcliente[i].ContratoCli.Contrato[j].NumSerie);
        printf("\nImporte del contrato  %d", pcliente[i].ContratoCli.Contrato[j].ImpContrato);
        printf("\nValor de la compra  %d", pcliente[i].ContratoCli.Contrato[j].ValorCompra);
      }
    }
    else
      printf("\n No tiene contratos vigentes");
  }
}

int menu()
{
  int op = 0;
  do
  {
    printf("\n\t 1.- ¿Se autoriza la reparación?\n");
    printf("\n\t 2.- Posición de un cliente\n");
    printf("\n\t 3.- Dar de alta un contrato\n");
    printf("\n\t 4.- Introducir datos para uno o más clientes\n");
    printf("\n\t 5.- Visualizar los datos de todos los clientes\n");
    printf("\n\t 6.- Salir\n");
    printf("\n\t Introduzca la opcion: ");
    scanf("%d",&op);
    fflush(stdin);
  }
  while (op < 1 || op > 6);
  return (op);
}