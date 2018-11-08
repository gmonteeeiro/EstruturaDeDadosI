class Aluno {
    Nome: string;
    NotaG1: number;
    NotaG2: number;
    Media: number;

    ///Construtor
    constructor(name: string) {
        this.Nome = name;
    }
    
    ///seta nota do G1
    SetG1(nota: number) {
        this.NotaG1 = nota;
    }

    ///seta nota do G2
    SetG2(nota: number) {
        this.NotaG2 = nota;
    }

    ///calcula a média
    CalcMedia() {
        this.Media = (this.NotaG1 + this.NotaG2 * 2 ) / 3;
    }

    ///Mostra resultado do aluno
    ShowResult() {
        var result = this.Media >= 6 ? "aprovado" : "reprovado";
        var textHtml = "Aluno " + this.Nome + ", " + result + " com a média final " + this.Media;
        let p = document.createElement('p');
        p.textContent = textHtml;

        document.body.appendChild(p);
    }
}

//Aqui começa o programa
let aluno = new Aluno("Roberto");

aluno.SetG1(3.5);
aluno.SetG2(8);
aluno.CalcMedia();

aluno.ShowResult();