class Ataque {
    public Forca: number;

    public Atacar() : number {
        return this.CalcDano();
    }

    protected CalcDano() : number{
        return this.Forca;
    }
}

class AtaqueFogo extends Ataque{

    protected CalcDano() : number{
        return this.Forca + 25;
    }
}

//começa o programa
let atq = new AtaqueFogo();
atq.Forca = 6;
var ataque = atq.Atacar();

let p = document.createElement('p');
p.textContent = ataque.toString();
document.body.appendChild(p);