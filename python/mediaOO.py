class Aluno:
    def __init__(self, name):
        self.Nome = name
        
    def SetG1(self, nota):
        self.G1 = nota
        
    def SetG2(self, nota):
        self.G2 = nota
    
    def CalcMedia(self):
        self.Media = (self.G1 + self.G2 * 2)/3
        
    def Print(self):
        print("Aluno: ", self.Nome)
        print("Media final: %.2f" % (self.Media))
        
        if self.Media > 6:
            print("Resultado: Aluno APROVADO")
        else:
            print("Resultado: Aluno REPROVADO")

##Aqui começa o programa de fato
continuar = 1
while continuar != 0:
    aluno = Aluno(input ("informe o nome do aluno: "))
    aluno.SetG1(float(input ("Informe do G1: ")))
    aluno.SetG2(float(input ("Informe do G2: ")))

    aluno.CalcMedia()
    aluno.Print()
    
    print("1 - Verificar outro aluno")
    print("0 - Sair")
    continuar = int(input ("Selecione uma opção: "))