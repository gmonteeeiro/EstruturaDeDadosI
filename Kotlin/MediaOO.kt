import java.util.Scanner

class Aluno(){
    var g1 : Float = 0f
    var g2 : Float = 0f
    var md : Float = 0f
    
    fun CalcMedia() {
        md = (g1 + g2 *2)/3;
    }
}

fun main(args: Array<String>) {
    val aluno = Aluno()
    val reader = Scanner(System.`in`)
    
    print("Informe o valor do G1: ")
    aluno.g1 = reader.nextFloat()
    
    print("Informe o valor do G2: ")
    aluno.g2 = reader.nextFloat()
    
    aluno.CalcMedia()
    
    println(aluno.md.toString())
}