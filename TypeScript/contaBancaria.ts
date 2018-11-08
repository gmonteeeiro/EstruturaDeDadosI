class ContaBancaria{
    public Nome : string;
    public Saldo : number;
}

class ContaPF extends ContaBancaria{
    public Cpf : string;
    public Nascimento : string;
}

class ContaPJ extends ContaBancaria{
    public Cnpj : string;
    public RazaoSocial : string;
}

//Começa o programa

//Classe pai (ContaBancaria)
let cb = new ContaBancaria();
var cbNome = cb.Nome;
var cbSaldo = cb.Saldo;

//Classe filha (ContaPF)
let cbPf = new ContaPF();
var cbPfNome = cb.Nome;
var cbPfSaldo = cb.Saldo;
var cbPfCpf = cbPf.Cpf;
var cbPfNascimento = cbPf.Nascimento;

//Classe filha (ContaPJ)
let cbPj = new ContaPJ();
var cbPjNome = cb.Nome;
var cbPjSaldo = cb.Saldo;
var cbPjCnpj = cbPj.Cnpj
var cbPjRazaoSocial = cbPj.RazaoSocial;