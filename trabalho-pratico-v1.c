#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dadosAluno {
    char nome[100], curso[50], telefone[12];
    float nota1, nota2;
};

float calcularMedia(struct dadosAluno X){
    float mediaAluno = (X.nota1 + X.nota2) / 2;
    return(mediaAluno);  
}

char *verificarSituacaoFinal(struct dadosAluno X) { // para a funcao poder retornar uma string, precisa ser um
    char *situacaoAluno;                            // ponteiro que aponta para o endereco da string
    
    if (calcularMedia(X) >= 7) {
        situacaoAluno = "APROVADO";
    } else if (calcularMedia(X) < 7) {
        situacaoAluno = "REPROVADO";
    }
    return (situacaoAluno);    
}

void processarDados(FILE *f1, FILE *f2) {
    char linha[94];
    char situacaoFinalAluno[10];

    f1 = fopen("DadosEntrada.csv", "r");
    f2 = fopen("SituacaoFinal.csv", "w");
    
    if((f1 == NULL) || (f2 == NULL)){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fgets(linha, sizeof(linha), f1); // para ignorar a primeira linha
    fprintf(f2, "Nome,Media,Resultado\n"); //printar novo cabecalho

    while(fgets(linha, sizeof(linha), f1) != NULL){
    	char *divString; //token
    	struct dadosAluno aluno;
		
    	divString = strtok(linha, ","); //leitura encerra na virgula
    	strcpy(aluno.nome, divString); //copiando dado do token para a variavel nome
    	
    	divString = strtok(NULL, ","); 
    	strcpy(aluno.telefone, divString);
    	
    	divString = strtok(NULL, ",");
    	strcpy(aluno.curso, divString);
    	
    	divString = strtok(NULL, ",");
    	aluno.nota1 = atof(divString);
    	
    	divString = strtok(NULL, "\0"); //leitura encerra no espaco
    	aluno.nota2 = atof(divString);

        strcpy(situacaoFinalAluno, verificarSituacaoFinal(aluno));
    	
        fprintf(f2, "%s,%.2f,%s\n", aluno.nome, calcularMedia(aluno), situacaoFinalAluno);
    }
}

int main(){

    FILE *f1, *f2;

    f1 = fopen("DadosEntrada.csv", "r");
    f2 = fopen("SituacaoFinal.csv", "w");
    
    if((f1 == NULL) || (f2 == NULL)){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    processarDados(f1, f2);

    printf("\n\n\tO arquivo de Saida 'SituacaoFinal' foi gerado com sucesso!\n\n\n");

    fclose(f1);
    fclose(f2);
    return 0;
}
