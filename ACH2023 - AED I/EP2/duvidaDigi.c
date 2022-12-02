
// Isso funciona

bool inserirNotaRecuperacao(TURMA *turma, int nusp, int nota)
{
    PONT alunoBuscado = buscarAlunoRec(turma, nusp);

    if (!alunoBuscado)
        return false;

    int frequencia = alunoBuscado->aluno.freq;

    if (excluirAluno(turma, nusp))
    {

        if (inserirAluno(turma, nusp, nota, frequencia))
            return true;
        else
            return false;
    }
    else
        return false;
}

// Isso Não funciona

bool inserirNotaRecuperacao(TURMA *turma, int nusp, int nota)
{
    PONT alunoBuscado = buscarAlunoRec(turma, nusp);

    if (!alunoBuscado)
        return false;
    if (excluirAluno(turma, nusp))
    {

        if (inserirAluno(turma, nusp, nota, alunoBuscado->aluno.freq))
            return true;
        else
            return false;
    }
    else
        return false;
}

// E isso não funciona também

bool inserirNotaRecuperacao(TURMA *turma, int nusp, int nota)
{
    PONT alunoBuscado = buscarAlunoRec(turma, nusp);

    if (!alunoBuscado)
        return false;
    if (excluirAluno(turma, nusp))
    {
        int frequencia = alunoBuscado->aluno.freq;
        if (inserirAluno(turma, nusp, nota, frequencia))
            return true;
        else
            return false;
    }
    else
        return false;
}
