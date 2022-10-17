/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2022                           **/
/**   Turma 03 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Marcos Paulo Tomás Ferreira>             <13747950>          **/
/**                                                                 **/
/*********************************************************************/

#include "turma.h"

/* Funcao usada em testes da correcao automatica - NAO APAGAR OU MODIFICAR */
void print123()
{
	/* Funcao utilizada pelo sistema de correcao automatia
	   Nao apague ou modifique esta funcao                 */
}

/* IMPLEMENTE FUNCOES EXTRAS/AUXILIARES SE JULGAR NECESSARIO */

/* Funcao que retorna o numero de alunos da turma cujo endereco foi passado
   como parametro de entrada. */
int tamanho(TURMA *turma)
{
	int tam = 0;
	PONT proximo = turma->listaNUSP->prox;

	while (proximo != turma->listaNUSP)
	{
		tam++;
		proximo = proximo->prox;
	}

	return tam;
}

/*
	Esta função é auxiliar para a função insereAluno().
	Ela busca a posição do último elemento que tem número usp menor
	do que está sendo inserido.

*/
PONT buscarElementoOrdenadoNUSP(TURMA *turma, int nusp)
{
	PONT alunoAtual = turma->listaNUSP->prox;

	while ((alunoAtual != turma->listaNUSP) && (alunoAtual->prox->aluno->nusp < nusp))
	{
		if (alunoAtual->prox->aluno->nusp < nusp)
			alunoAtual = alunoAtual->prox;
	}
	return alunoAtual;
}

/*
	Esta função é auxiliar para a função insereAluno().
	Ela busca a posição do último elemento que tem nota menor
	do que está sendo inserido.

*/
PONT buscarElementoOrdenadoNOTA(TURMA *turma, int nota)
{
	PONT alunoAtual = turma->listaNOTA->prox;

	while ((alunoAtual != turma->listaNOTA) && (alunoAtual->prox->aluno->nota < nota))
	{
		alunoAtual = alunoAtual->prox;
	}
	return alunoAtual;
}

/* Funcao que recebe o endereco de uma turma e um numero USP e retorna
   NULL caso nao exista um aluno com o respectivo numero USP na turma ou
   o endereco de memoria do registro do respectivo aluno, caso ele esteja
   presente na turma. */
ALUNO *buscarAluno(TURMA *turma, int nusp)
{
	if (nusp < 0)
		return NULL;

	PONT primeiroElementoValido = turma->listaNUSP->prox;
	int i = 0, tam = tamanho(turma);

	while (i <= tam)
	{
		if (primeiroElementoValido->aluno->nusp == nusp)
			return primeiroElementoValido->aluno;
		primeiroElementoValido = primeiroElementoValido->prox;
		i++;
	}
	return NULL;
}

/* Funcao que recebe o endereco de uma turma e o numero USP, nota e frequencia
   de um aluno e deve:
   Retornar false caso o numero USP seja menor do que zero, ou a nota seja
   menor do que zero ou maior do que cem ou a frequencia seja menor do que
   zero ou maior do que cem;
   Deve, tambem, retornar false se a turma ja contiver um aluno com o mesmo
   numero USP.
   Caso contrario, esse novo aluno devera ser inserido na turma e a funcao
   devera retornar true. A insercao na turma contem as seguintes atividades:
	 1a) alocacao dinamica de memoria para uma estrutura do tipo ALUNO e
		 preenchimento de seus campos com os respectivos parametros recebidos
		 pela funcao de insercao;
	 *2a) alocacao dinamica de memoria de duas estruturas do tipo ELEMENTO
		 (ambas irao referenciar o novo aluno por meio de seu campo 'aluno'.
		 Uma delas devera ser inserida na posicao correta da lista ordenada
		 por nusp e a outra na posicao correta da lista ordenada por nota.
	 3a) por fim, a funcao devera retornar true.
*/
bool inserirAluno(TURMA *turma, int nusp, int nota, int frequencia)
{

	if (nusp < 0 || nota < 0 || nota > 100 || frequencia < 0 || frequencia > 100)
		return false;
	if (buscarAluno(turma, nusp))
		return false;
	else
	{
		ALUNO *novoAluno = (ALUNO *)malloc(sizeof(ALUNO));
		novoAluno->freq = frequencia;
		novoAluno->nota = nota;
		novoAluno->nusp = nusp;

		PONT novoElementoUSP = (PONT)malloc(sizeof(ELEMENTO));
		PONT novoElementoNOTA = (PONT)malloc(sizeof(ELEMENTO));
		novoElementoUSP->aluno = novoAluno;
		novoElementoNOTA->aluno = novoAluno;

		PONT elementoAnteriorNUSP = buscarElementoOrdenadoNUSP(turma, nusp);
		PONT elementoAnteriorNOTA = buscarElementoOrdenadoNOTA(turma, nota);

		PONT aux = elementoAnteriorNUSP->prox;
		elementoAnteriorNUSP->prox = novoElementoUSP;
		novoElementoUSP->prox = aux;

		aux = NULL;

		aux = elementoAnteriorNOTA->prox;
		elementoAnteriorNOTA->prox = novoElementoNOTA;
		novoElementoNOTA->prox = aux;

		return true;
	}
}

/* Funcao que recebe o endereco de uma turma e um numero USP e deve:
   Retornar false se a turma nao possuir um aluno com esse numero USP.
   Caso contrario, esse aluno devera ser excluido da turma e a funcao
   devera retornar true. A exclusao na turma contem as seguintes atividades:
	 1a) remocao dos elementos que apontam para o respectivo aluno das duas
		 listas (ordenada por nusp e ordenada por nota).
	 2a) liberacao da memoria do registro do aluno e dos elementos das listas
		 que apontavam para o respectivo aluno.
	 3a) por fim, a funcao devera retornar true.
*/
bool excluirAluno(TURMA *turma, int nusp)
{
	ALUNO *alunoBuscado = buscarAluno(turma, nusp);
	if (!alunoBuscado)
		return false;
	else
	{
		PONT elementoAnteriorNUSP = buscarElementoOrdenadoNUSP(turma, nusp);
		PONT elementoAExcluirNUSP = elementoAnteriorNUSP->prox;
		elementoAnteriorNUSP->prox = elementoAExcluirNUSP->prox;
		free(elementoAExcluirNUSP);

		PONT elementoAnteriorNOTA = buscarElementoOrdenadoNOTA(turma, alunoBuscado->nota);
		PONT elementoAExcluirNOTA = elementoAnteriorNOTA->prox;
		elementoAnteriorNOTA->prox = elementoAExcluirNOTA->prox;
		free(elementoAExcluirNOTA);

		return true;
	}
}

/* Funcao que cria e retorna uma TURMA.
   Neste EP, uma turma contem duas listas ligadas de ELEMENTOS,
   estas listas sao circulares e https://estagiobancopan.com.br/possuem no-cabeca
*/
TURMA inicializaTurma()
{
	TURMA t1;

	// criacao de um aluno ficticio que poder ser usado como sentinela
	ALUNO *ficticio = (ALUNO *)malloc(sizeof(ALUNO));
	ficticio->nusp = -1;
	ficticio->nota = -1;
	ficticio->freq = -1;

	// criacao do primeiro no-cabeca
	t1.listaNUSP = (PONT)malloc(sizeof(ELEMENTO));
	t1.listaNUSP->aluno = ficticio;
	t1.listaNUSP->prox = t1.listaNUSP;

	// criacao do segundo no-cabeca
	t1.listaNOTA = (PONT)malloc(sizeof(ELEMENTO));
	t1.listaNOTA->aluno = ficticio;
	t1.listaNOTA->prox = t1.listaNOTA;

	return t1;
}

/* Funcao que reinicia (ou limpa) a TURMA passada como parametro.
   Todos os elementos, exceto os nos-cabeca, sao apagamos e a TURMA fica
   da mesma forma como se ela tivesse sido recem criada.
*/
void reinicializaTurma(TURMA *turma)
{
	PONT atual, apagar;

	// apagar todos os elementos, exceto o cabeca, da listaNUSP
	atual = turma->listaNUSP->prox;
	while (atual != turma->listaNUSP)
	{
		apagar = atual;
		atual = apagar->prox;
		free(apagar);
	}
	atual->prox = atual;

	// apagar todos os elementos e os alunos, exceto o cabeca, da listaNOTA
	atual = turma->listaNOTA->prox;
	while (atual != turma->listaNOTA)
	{
		apagar = atual;
		atual = apagar->prox;
		free(apagar->aluno);
		free(apagar);
	}
	atual->prox = atual;
}

/* Funcao que exibe todos os alunos da turma referenciada como parametro.
   Alem de exibir os alunos nas duas ordens. */
void exibirTurma(TURMA *turma)
{
	PONT atual = turma->listaNUSP->prox;
	ALUNO *aluno;
	printf("Exibindo lista [%i aluno(s)]\n", tamanho(turma));
	printf("   Ordenada por nusp:");
	while (atual != turma->listaNUSP)
	{
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno->nusp, aluno->nota, aluno->freq);
		atual = atual->prox;
	}
	printf("\n   Ordenada por nota:");
	atual = turma->listaNOTA->prox;
	while (atual != turma->listaNOTA)
	{
		aluno = atual->aluno;
		printf(" (%4i, %3i, %3i)", aluno->nusp, aluno->nota, aluno->freq);
		atual = atual->prox;
	}
	printf("\n");
}
